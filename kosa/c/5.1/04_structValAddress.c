#include <stdio.h>

struct point
{
    int xpos;
    int ypos;
};

struct person
{
    char name[20];
    char phoneNum[20];
    int age;
};

int main(void)
{
    struct point pos={10, 20};
    struct person man={"이승기", "0101010", 11};

    printf("%p %p %p\n", &pos, &pos.xpos, &pos.ypos);//주소값을 가리키는거니까 근데 왜 ypos 는 다른 값이== 자료구조 &pos 포인트에 바이트값을 옮겨서 ypos를 가리킬 수 있는가
    printf("%p %p %p %p", &(man.age), &man.name, &man.phoneNum, &man.age);
    return 0;
}