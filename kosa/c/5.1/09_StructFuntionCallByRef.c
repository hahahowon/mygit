//Call by reference예제

// 변수에 초기화된 값의 부호를 바꿔주는 코드
#include <stdio.h>
//구조체 선언
typedef struct point
{
    int xpos;
    int ypos;
}Point;

//인자전달 0, 반환값 x //주소값을 가리키기 떄문에 반환값은 없음
void OrgSymTrans(Point *ptr)//원점대칭 
{
    ptr->xpos =(ptr->xpos) * -1; // 이 명령어 구조 해석
    ptr->ypos =(ptr->ypos) * -1;
    
}

void ShowPosition(Point pos)
{
    printf("[%d, %d]", pos.xpos, pos.ypos);//*ptr을 쓰려 했지만 안된다. 그럼..? 밑에 되도록 만들어보자
}

void ShowAddress(Point ptr)
{
    printf("[%d, %d]", ptr.xpos, ptr.ypos);
}


int main(void)
{
    Point pos ={7, -5}; //변수 초기화
    OrgSymTrans(&pos);// 원점 대칭이동
    ShowPosition(pos);//결과
    ShowAddress(pos);//주소값 확인해보자
    OrgSymTrans(&pos);//다시 이동
    ShowAddress(pos);
    ShowPosition(pos);//결과
    return 0;

}