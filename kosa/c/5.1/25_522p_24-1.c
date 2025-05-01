


#include <Stdio.h>

int main(void){
    FILE * fp=fopen("mystory.txt", "wt");
    if(fp==NULL){
        puts("파일오픈실패");
        return -1;
    }

    fputs('#윤',fp);
    fputs('B',fp);
    fputs('My name is KIm \n',fp);
    fputs('Your name is Hong',fp);
    fclose(fp);
    return 0;
}





#include <stdio.h>

typedef struct {
  char name[9];
  char jumin[16];
  char phoneno[15];
} Person;

int main(void)
{
  Person me;
  FILE *fp;

  printf("정보를 입력하세요.\n");
  me.name[0] = '#'; me.jumin[0] = '#'; me.phoneno[0] = '#';
  printf("이름 : "), scanf("%s", &(me.name[1])); //첫 글자에 #을 채워놨기때문에 두 번째부터 채울 수 있도록 설정
  printf("주민등록번호 : "), scanf("%s", &(me.jumin[1]));
  printf("전화번호 : "), scanf("%s", &(me.phoneno[1]));

  fp = fopen("mystory.txt", "wt");
  fwrite(&me, sizeof(Person), 1, fp);
  fclose(fp);

  return 0;
}