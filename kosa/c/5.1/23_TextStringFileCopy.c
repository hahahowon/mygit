#include <stdio.h>

int main(void)
{
    FILE * src =fopen("scr.txt", "rt");
    FILE * des =fopen("des.txt", "wt");
    char str[20];

    if (src == NULL || des == NULL){
        puts("error");
        return -1;
    }

    whilte(fgets(str, sizeof(str), src)!=NULL)
    {
        fputs(str, des);
    }

    if (feof(src) != 0){
        puts("cp complete");
    }
    else{
        puts("cp fail");
    }

    fclose(src);
    fclose(des);
    return 0;

}