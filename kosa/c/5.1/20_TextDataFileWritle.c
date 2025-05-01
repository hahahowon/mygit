

#include <Stdio.h>

int main(void){
    FILE * fp=fopen("simple.txt", "wt");
    if(fp==NULL){
        puts("파일오픈실패");
        return -1;
    }

    fputs('A',fp);
    fputs('B',fp);
    fputs('My name is KIm \n',fp);
    fputs('Your name is Hong',fp);
    fclose(fp);
    return 0;
}