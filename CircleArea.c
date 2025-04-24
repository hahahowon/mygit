#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
int main(void)
{
	double rad;
	double area;
	printf("원의 반지름 입력: ");
	scanf_s("%lf", &rad);

	area = rad * rad * M_PI;
	printf("원의 넓이: %f", area);
	return 0;
}

//visual studio는 scanf 가 먹지 않는다 기억하기 scanf_s를 대신 쓰기

/*
#define _USE_MATH_DEFINES
#include <math.h>
이 두 줄을 추가해서 3.1415원주율 숫자입력대신 M_PI로 사용가능
*/

//문자와 문자열 구분 '문자' "문자열"