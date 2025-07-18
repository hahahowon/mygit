#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#define WIDTH 640
#define HEIGHT 480
#define FRAMEBUFFER_DEVICE "/dev/fb0"
#define TCP_PORT 5100
#define FRAME_SIZE (WIDTH * HEIGHT * 2)

static struct fb_var_screeninfo vinfo;

void display_frame(uint16_t *fbp, uint8_t *data) {
    int x_offset = (vinfo.xres - WIDTH) / 2;
    int y_offset = (vinfo.yres - HEIGHT) / 2;

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; x += 2) {
            uint8_t Y1 = data[(y * WIDTH + x) * 2];
            uint8_t U  = data[(y * WIDTH + x) * 2 + 1];
            uint8_t Y2 = data[(y * WIDTH + x + 1) * 2];
            uint8_t V  = data[(y * WIDTH + x + 1) * 2 + 1];

            int R1 = Y1 + 1.402 * (V - 128);
            int G1 = Y1 - 0.344136 * (U - 128) - 0.714136 * (V - 128);
            int B1 = Y1 + 1.772 * (U - 128);

            int R2 = Y2 + 1.402 * (V - 128);
            int G2 = Y2 - 0.344136 * (U - 128) - 0.714136 * (V - 128);
            int B2 = Y2 + 1.772 * (U - 128);

            uint16_t pixel1 = ((R1 & 0xF8) << 8) | ((G1 & 0xFC) << 3) | (B1 >> 3);
            uint16_t pixel2 = ((R2 & 0xF8) << 8) | ((G2 & 0xFC) << 3) | (B2 >> 3);

            fbp[(y + y_offset) * vinfo.xres + (x + x_offset)] = pixel1;
            fbp[(y + y_offset) * vinfo.xres + (x + x_offset + 1)] = pixel2;
        }
    }
}

int main() {
    int fb = open(FRAMEBUFFER_DEVICE, O_RDWR);
    if (fb < 0) {
        perror("framebuffer open");
        return 1;
    }

    if (ioctl(fb, FBIOGET_VSCREENINFO, &vinfo)) {
        perror("FBIOGET_VSCREENINFO");
        return 1;
    }

    uint32_t screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
    uint16_t *fbp = mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fb, 0);
    if ((intptr_t)fbp == -1) {
        perror("mmap");
        return 1;
    }

    int server = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(TCP_PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server, (struct sockaddr*)&addr, sizeof(addr));
    listen(server, 1);

    printf("Waiting for client...\n");
    int client = accept(server, NULL, NULL);
    printf("Client connected.\n");

    uint8_t *buf = malloc(FRAME_SIZE);

    while (1) {
        uint32_t net_size;
        if (recv(client, &net_size, sizeof(net_size), MSG_WAITALL) <= 0) break;
        int size = ntohl(net_size);
        if (size != FRAME_SIZE) break;

        if (recv(client, buf, FRAME_SIZE, MSG_WAITALL) <= 0) break;
        display_frame(fbp, buf);
    }

    close(client);
    close(server);
    munmap(fbp, screensize);
    return 0;
}
