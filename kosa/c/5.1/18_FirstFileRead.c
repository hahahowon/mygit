#include <stdio.h>

int main(void)
{
    int ch, i;
    FILE *fp=fopen("data.txt", "rt");
    if(fp==NULL){
        puts("실행 실패");
        return -1;
    }

    for(i=0;i<3;i++)
    {
        ch=fgetc(fp);
        printf("%c \n", ch);
    }
    fclose(fp);
    return 0;
}