#include <stdio.h>

struct point
{
    int xpos;
    int ypos;  
};
struct circle
{
    double radius;
    struct point* center;//포인터 변수도 구조체 멤버가 될 수 있음
};

int main(void)
{
    struct point cen={2, 7};
    double rad=5.5;

    struct circle ring={rad, &cen};//구조체 변수 ring 지역변수로 선언 -> ring의 멤버변수 center가 구조체 변수 cen을 가리키는 형태


    printf("원의 반지름: %g\n", ring.radius);
    printf("원의 중심[ %d, %d]", (ring.center)->xpos, (ring.center)->ypos);//구조체 변수 ring의 멤버변수 center가 포인터 변수이기에 
                                                                          //ring.center를 쓰고 대상으로 "->" 연산해서 구조체 변수 cen의 멤버에 접근
                                                                          //연산자 우선순위 관계상 -> 연산자의 왼편에 있는 소괄호는 생략가능
    return 0;
}