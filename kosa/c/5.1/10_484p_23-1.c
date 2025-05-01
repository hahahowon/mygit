//call by reference

//문제 처음 작성해본 코드
#include <stdio.h>

typedef struct point
{
    int xpos;
    int ypos;
}Point;


//함수 선언

Point Swap(Point *ptr1, Point* ptr2)//정수니까 인트로 함수를 만들려했지만 구조체에서 받아와야 하기 때문에 선언해둔 구조체를 앞에 써준다
{
    int tmp;
    ptr1->xpos= tmp;
    ptr2->ypos= ptr1->xpos;
    tmp = ptr2->ypos;
}

void Showresult(Point pos)
{
    printf("[%d %d] \n",pos.xpos, pos.ypos);
}

int main(void)
{
    Point pos1 = {2, 4};
    Point pos2 = {5, 7};
    Swap(&pos1, &pos2);
    Showresult(pos1);
    Showresult(pos2);
    return 0;
    
}

//call by reference


#include <stdio.h>

typedef struct point
{
    int xpos;
    int ypos;
}Point;


//함수 선언

Point Swap(Point *ptr1, Point* ptr2)//정수니까 인트로 함수를 만들려했지만 구조체에서 받아와야 하기 때문에 선언해둔 구조체를 앞에 써준다
{
    int tmp;
    ptr1->xpos= tmp;
    ptr2->ypos= ptr1->xpos;
    tmp = ptr2->ypos;
}

void Showresult(Point pos)
{
    printf("[%d %d] \n",pos.xpos, pos.ypos);
}

int main(void)
{
    Point pos = {2, 4};
    Swap(&pos);
    Showresult(pos);
    return 0;
    
}

#include <stdio.h>

typedef struct point
{
    int xpos;
    int ypos;
}Point;


//함수 선언

Point Swap(Point *ptr1, Point* ptr2)//정수니까 인트로 함수를 만들려했지만 구조체에서 받아와야 하기 때문에 선언해둔 구조체를 앞에 써준다
{
    Point tmp; ///나는 int로 했지만 이 선언을 포인트로 해줘야한다
    *ptr1= tmp;
    *ptr2= *ptr1;
    tmp = *ptr2;
}

void Showresult(Point pos)
{
    printf("[%d %d] \n",pos.xpos, pos.ypos);
}

int main(void)
{
    Point pos = {2, 4};
    Swap(&pos[1], &pos[0]);
    Showresult(pos);
    return 0;
    

}
///배열로 선언되었기 때문에 이렇게 하면 안되겠다
//이 코드가 동작하게 하려면 정수로 한번 써보자



//코드

#include <stdio.h>

typedef struct _point {
  int xpos;
  int ypos;
} Point;

void swap(Point *p1, Point *p2) 
{
  Point tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

void showPosition(Point p)
{
  printf("X : %d, Y : %d\n", p.xpos, p.ypos);
}

int main(void)
{
  Point x1 = { 10, 20 };
  Point x2 = { 30, 40 };

  swap(&x1, &x2);

  printf("Position1 Info : ");
  showPosition(x1);
  printf("Position2 Info : ");
  showPosition(x2);

  return 0;
}