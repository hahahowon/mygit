/*
제 목: Operator
기 능: 문자열의 출력
파일이름: Operator.c
수정날짜: 2025. 04. 23
작성자: 김호원
*/



#include <stdio.h>

int main(void)
{
	3 + 4; // 3과 4의 합을 명령함, 저장할 곳이 필요
	return 0;
}
//


int main(void)
{
	int num1, num2;									//변수 num1, num2의 선언
	int num3 = 30, num4 = 40;						//변수 num3, num4 선언 및 초기화

	printf("num1: %d, num2: %d\n", num1, num2);		//변수 num1, num2 출력
	num1 = 10;										//변수 num1 초기화
	num2 = 20;										//변수 num1 초기화

	printf("num1: %d, num2: %d \n", num1, num2);	//변수 num1, num2 출력
	printf("num3: %d, num4: %d \n", num3, num4);	//변수 num3, num4 출력
	
	return 0;										//0값을 반환
}


int main(void)
{
	int a, b;
	int c = 30, d = 40;

	a = 10;
	b = 20;

	printf("%d %d \n", a, b);
	printf("%d %d \n", c, d);

	return 0;
}

/*덧셈프로그램 완성*/

int main(void)
{
	int num1 = 3, num2 = 4; //변수 선언 및 초기화
	int result;				//결과값 변수 선언
	result = num1 + num2;	//결과값 변수에 덧셈 결과 저장

	printf("덧셈 결과 : %d \n", result); //덧셈결과 result 저장된 값 출력
	printf("%d 더하기 %d는 %d 입니다.\n", num1, num2, result);// num1, 2 변수와 result 저장된 값 출력
	printf("변수 result에 저장된 값 : %d \n", result); // result 저장된 값 출력

	return 0;

}
