#include <stdio.h>
typedef struct dbshort
{
    unsigned short upper;
    unsigned short lower;
}DBShort;

typedef union rdbuf
{
    int iBuf;
    char bBuf[4];
    DBShort sBuf;

}RDBuf;

int main(void)
{
    RDBuf buf;
    printf("input int: ");
    scanf("%d", &(buf.iBuf));

    printf("upper 2bite: %u\n", buf.sBuf.upper);//기억하자 %u는 부호없는 십진수 //공용체의 멤버로 구조체 변수 선언되어 있음 -> sBuf로 선언되어잇음
    printf("lower 2bite: %u\n", buf.sBuf.lower);
    printf("upper 1bite ASCII code: %c\n", buf.bBuf[0]);
    printf("lower 1bite ASCII code: %c\n", buf.bBuf[3]);//이 코드는 유니온 코드안의 멤dd버를 선언하기에 공용체 변수인 sBuf 선언 안해도 됌
    return 0;

}
/*
uint16_t upper;
uint16_t lower;

unint16_t uBuf[2];
*/

//구조체로 안해도 되지만 구조체를 사용했다
