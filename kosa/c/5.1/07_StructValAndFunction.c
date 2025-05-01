#include <stdio.h>

typedef struct point
{
    int xpos;
    int ypos;
} Point;

//함수
void ShowPosition(Point pos)
{
    printf("[%d %d] \n", pos.xpos, pos.ypos);
}

Point GetCurrentPosition(void)
{
    Point cen;
    printf("Input current pos: ");
    scanf("%d %d", &cen.xpos, &cen.ypos);
    return cen;
}

int main(void)
{
    Point curPos = GetCurrentPosition();//항상 변수 선언해주기
    ShowPosition(curPos);
    return 0;
}
//왜 20을 넣었는데 앞 숫자만 나왔을까===>함수 getcurrentPosition에 반환값을 안넣어줬다..