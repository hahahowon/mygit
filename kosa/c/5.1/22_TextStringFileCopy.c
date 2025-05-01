#include <stdio.h>

int main(void)
{
    FILE *scr=fopen("scr.txt", "rt");
    FILE *des=fopen("des.txt", "wt");
    char str[20];

    it(src == NULL || des == NULL)
    {
        puts("File open fail");
        return -1;
    }

    while(fgets(str, sizeof(str), scr)!=NULL)
        fputs(str, des);

    if(eof(src)!=0);
        puts("File copy complete");
    else 
        puts("File copy fail");
    
        fclose(scr);
        fclose(des);
        return 0;
        
}