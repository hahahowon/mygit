#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <linux/videodev2.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#define WIDTH 640
#define HEIGHT 480
#define FRAME_SIZE (WIDTH * HEIGHT * 2)
#define VIDEO_DEVICE "/dev/video0"
#define TCP_PORT 5100

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <SERVER_IP>\n", argv[0]);
        return 1;
    }

    int cam_fd = open(VIDEO_DEVICE, O_RDWR);
    if (cam_fd < 0) {
        perror("camera open");
        return 1;
    }

    struct v4l2_format fmt = {0};
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = WIDTH;
    fmt.fmt.pix.height = HEIGHT;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
    fmt.fmt.pix.field = V4L2_FIELD_NONE;

    if (ioctl(cam_fd, VIDIOC_S_FMT, &fmt) < 0) {
        perror("VIDIOC_S_FMT");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(TCP_PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    uint8_t *frame = malloc(FRAME_SIZE);
    if (!frame) {
        perror("malloc");
        return 1;
    }

    while (1) {
        int ret = read(cam_fd, frame, FRAME_SIZE);
        if (ret != FRAME_SIZE) {
            perror("read");
            continue;
        }

        uint32_t net_size = htonl(FRAME_SIZE);
        send(sock, &net_size, sizeof(net_size), 0);
        send(sock, frame, FRAME_SIZE, 0);

        usleep(33000); // 30fps
    }

    close(sock);
    close(cam_fd);
    free(frame);
    return 0;
}
