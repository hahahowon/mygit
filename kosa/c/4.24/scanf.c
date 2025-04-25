#include <stdio.h>

int main(void)
{
	int result;
	int num1, num2;

	printf("정수 one: ");
	scanf("%d", &num1); //num1 정수 입력
	printf("정수 two: ");
	scanf("%d", &num2); //num2 정수 입력

	result = num1 + num2;
	printf("%d+%d=%d\n", num1, num2, result); //입력값 연산 결과 출력
	return 0;

}

//scanf는 보안문제로 scanf_s를 사용

