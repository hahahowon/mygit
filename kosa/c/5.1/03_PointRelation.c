#include <stdio.h>

struct point
{
    int xpos;
    int ypos;
    struct point *ptr;
    
    
};

int main(void)
{
    struct point pos1={1, 1};
    struct point pos2={2, 2};
    struct point pos3={3, 3};
    
    pos1.ptr = &pos2;
    pos2.ptr = &pos3;
    pos3.ptr = &pos1;
    
    printf("연결관계...\n");
    printf("[%d, %d]와 [%d, %d]의 연결\n", pos1.xpos, pos1.ypos, pos1.ptr->xpos, pos1.ptr->ypos);
    printf("[%d, %d]와 [%d, %d]의 연결\n", pos2.xpos, pos2.ypos, pos2.ptr->xpos, pos2.ptr->ypos);
    printf("[%d, %d]와 [%d, %d]의 연결\n", pos3.xpos, pos3.ypos, pos3.ptr->xpos, pos3.ptr->ypos);
    return 0;
}

//pos1의 출력은 초기화 해준 값인 [1,1]이고 pos1의 pointer 주소값이 가리키는 값은 pos2의 값으로 나타난다 ::3번까지 서클반복