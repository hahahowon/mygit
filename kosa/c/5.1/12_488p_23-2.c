#include <stdio.h>

typedef struct point {
    int xpos;
    int ypos;
}Point;


typedef struct rectangle//두 점의 위치를 받아줘야한다.
{
    //그러면 Point 구조체의 값을 받아서 점을 지정한다
    Point topleft;
    Point bottomright;
}Rectangle;

int main(void)

{
    
    return 0;
}
