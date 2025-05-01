#include <stdio.h>

struct point
{
    int xpos;
    int ypos;
};

typedef struct point Point;

typedef struct person
{  
   char name[20];
   char PNum[20];
   int age ;
}Person;


int main(void)
{
  Point pos ={10, 20};
  Person man={"이승기","000000", 23}; //struct 선언 없이 구초제 변수 선언
  printf("%d %d\n",pos.xpos, pos.ypos);
  printf("%s %s %d", man.name,man.PNum,man.age);
  return 0;  
}