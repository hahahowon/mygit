#include <stdio.h>

int main(void)
{
    char str[30];
    int ch;
    FILE*fp=fopen("simple.txt","rt");
    if(fp==NULL){
        puts("error");
        return -1;
    }

    ch=fgetc(fp);
    printf("%c \n", ch);
    ch=fgetc(fp);
    frintf("%c \n", ch);

    fgets(str, sizof(str),fp);
    printf("%s", str);
    fgets(str, sizeof(str), fp);
    printf("%s", str);

    fclose(fp);
    return 0;
}