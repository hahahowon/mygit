#include <stdio.h>

int main(void)
{
    FILE*fp=fopen("data.txt", "wt");//쓰기모드
    if(fp==NULL){
        puts("파일오픈 실패");
        return -1;
    }
    fputc('A',fp);
    fputc('B',fp);
    fputc('C',fp);
    fclose(fp);
    return 0;
}