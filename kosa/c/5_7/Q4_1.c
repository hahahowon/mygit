//2차원배열
//4-1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _bookinfo {
  char title[32];
  char author[32];
  int page;
} BookInfo;

int main(void)
{
  BookInfo *info;
  info =(BookInfo*)malloc(sizeof(BookInfo)*3);

  for(int i = 0; i < 3; i++) {
    printf("저자 : ");
    scanf("%s%*c", info[i].author);
    printf("제목 : ");
    fgets(info[i].title, 32, stdin);
    info[i].title[strlen(info[i].title)-1] = '\0';
    printf("페이지수 : ");
    scanf("%d", &info[i].page);
  }

  printf("도서 정보 출력\n");
  for(int i = 0; i < 3; i++) {
    printf("book %d\n", i);
    printf("저자 : %s\n", info[i].author);
    printf("제목 : %s\n", info[i].title);
    printf("페이지수 : %d\n", info[i].page);
  }
  free(info);
  return 0;
}

  //fgets로 모두 바꾸어주나?
  //동적 할당된 구조체 변수사이즈s
  //fflush ?
  //포인터로 접근하는법 -> 포인터 참조연산자
  //메모리를 할당한 후에 헤제하는 방법또한 알아두자.

//Q4-2
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  
  typedef struct _bookinfo {
    char title[32];
    char author[32];
    int page;
  } BookInfo;
  
  int main(void)
  {
    BookInfo *info;
    info = (BookInfo*)malloc(sizeof(BookInfo)*3);
  
    for(int i = 0; i < 3; i++) {
      printf("저자: ");
      scanf("%s%*c", (info+i)->author);
      fflush(NULL);
      printf("제목: ");
      fgets((info+i)->title, 32, stdin);
      info[i].title[strlen((info+i)->title)-1] = '\0';
      printf("페이지수: ");
      scanf("%d", &(info+i)->page);
    }
  
    printf("\n도서 정보 출력\n");
    for(int i = 0; i < 3; i++) {
      printf("book %d\n", i);
      printf("저자 : %s\n", (info+i)->author);
      printf("제목 : %s\n", (info+i)->title);
      printf("페이지수 : %d\n", (info+i)->page);
    }
  
    free(info);
  
    return 0;
  }
//2차원 배열 가능?

int main(void)
{
    int arr[3][3];

    for(int i=0; i<3; i++){
        for(int j;j<3;i++){

        }
    }
}

//Q4-3

//중요 포인트: 구조체와 함수를 어떻게 만들것인가
//call by reference로 받기 


#include <stdio.h>

typedef struct {//구조체 선언
  float realNum;
  float imgNum;
} ComplexType;

ComplexType add(ComplexType p1, ComplexType p2)//덧셈 함수
{
  ComplexType result;
  result.realNum = p1.realNum + p2.realNum;//복소수 덧셈공식
  result.imgNum = p1.imgNum + p2.imgNum;
  return result;
}

ComplexType mul(ComplexType p1, ComplexType p2)//곱셈 함수
{
  ComplexType result;
  result.realNum = p1.realNum*p2.realNum - p1.imgNum*p2.imgNum;//복소수 곱셈공식
  result.imgNum =  p1.realNum*p2.imgNum + p1.imgNum*p2.realNum;
  return result;
}

int main(void)
{
  ComplexType p1, p2, result;//구조체 call by reference :: 사용-> p1.realNum

  printf("복소수 입력1[실수 허수]: ");
  scanf("%f %f", &p1.realNum, &p1.imgNum);
  printf("복소수 입력2[실수 허수]: ");
  scanf("%f %f", &p2.realNum, &p2.imgNum);
  result = add(p1, p2);
  printf("합의 결과] 실수: %.6f, 허수 : %.6f\n", result.realNum, result.imgNum);
  result = mul(p1, p2);
  printf("곱의 결과] 실수: %.6f, 허수 : %.6f\n", result.realNum, result.imgNum);

  return 0;
}

//Q4-4

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main(int argc, char **argv)
{
  int a_cnt = 0, p_cnt = 0;//
  char ch;
  bool isFirst;
  FILE* fp;



    if(ch ==''|| ch=='\t'||ch=='\n')
        isFirst = ture;

    printf("%c",ch);
    while(ch != EOF);

  if(argc < 1) {
    fprintf(stderr, "Usage : %s filename\n", argv[0]);
    return -1;
  }

  fp = fopen(argv[1], "rt");//1 입력한 첫 번째 인자 1

  while(!feof(fp)) {
    str[0]='\0';
    fscanf(fp, "%s", str);
    if (str[0] == 'A' || str[0] == 'a')
      a_cnt++;
    else if (str[0] == 'P' || str[0] == 'p') 
      p_cnt++;
  } 

  printf("Count of words with A start: %d\n", a_cnt);
  printf("Count of words with P start: %d\n", p_cnt);

  fclose(fp);

  return 0;
}
//argc, fscanf

//fgets, fgetc 둘 다 사용해서 구현해보기
//한 줄씩 가지고 오기
//fgets는 문장으로 가져오기
//


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main(int argc, char **argv)
{
  int a_cnt = 0, p_cnt = 0;//
  char ch;
  bool isFirst;
  FILE* fp;

  if(argc < 1) {
    fprintf(stderr, "Usage : %s filename\n", argv[0]);
    return -1;
  }

  fp = fopen(argv[1], "rt");

  do {
    ch=0;
    ch =fgetc(fp);
    if(isFirst){
        //거짓인지 참값인지
        if(ch=='A'||ch=="a"){
            a_cnt++;
        }else if(ch=='P'||ch=="p"){
            p_cnt++;
        }
        isFirst = false;
    }
    
    if(ch ==''|| ch=='\t'||ch=='\n')
        isFirst = true;

    printf("%c",ch);
    }while(ch != EOF);
    return 0;
}
