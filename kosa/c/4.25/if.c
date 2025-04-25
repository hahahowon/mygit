#include <stdio.h>

int main(void)
{
	int num;

	printf("정수 입력: ");
	scanf("%d", &num);

	if (num < 0) {
		printf("입력 값은 0보다 작다. \n");
	}
	if (num > 0) {
		printf("입력 값은 0보다 크다. \n");
	}
	if (num == 0) {
		printf("입력 값은 0이다. \n");
	}
	return 0;
}



int main(void)
{
	int num;

	printf("정수 입력: ");
	scanf("%d", &num);

	if (num < 0) {
		printf("입력 값은 0보다 작다. \n");
	}
	else if (num > 0) {
		printf("입력 값은 0보다 크다. \n");
	}
	else (num == 0) {
		printf("입력 값은 0이다. \n");
	}
	return 0;
}


//if 문 사칙연산

int main(void)
{
	int opt;//메뉴선택
	double num1, num2;// 두 수를 연산
	double result;

	printf("1. 덧셈, 2 뺄셈, 3. 곱셈, 4. 나눗셈 :: 번호를 선택하시오.\n");
	scanf("%d", &opt);
	printf("두 개의 실수를 입력::");
	scanf("%lf %lf", &num1, &num2);

	if (opt == 1) {
		result = num1 + num2;
	}
	if (opt == 2) {
		result = num1 - num2;
	}
	if (opt == 3) {
		result = num1 * num2;
	}
	if (opt == 4) {
		result = num1 / num2;
	}
	printf("결과 %f", result);
	return 0;

}

//if else
int main(void)
{
	int num = 0;
	printf("정수 입력:: ");
	scanf("%d", &num);

	if (num < 0) {
		printf("입력값은 0보다 작다.\n");
	}
	else {
		printf("입력값은 0보다 작지 않다.\n");
	}
	return 0;
}


int main(void)
{
	int opt;//메뉴선택
	double num1, num2;// 두 수를 연산
	double result;

	printf("1. 덧셈, 2 뺄셈, 3. 곱셈, 4. 나눗셈 :: 번호를 선택하시오.\n");
	scanf("%d", &opt);
	printf("두 개의 실수를 입력::");
	scanf("%lf %lf", &num1, &num2);

	if (opt == 1) {
		result = num1 + num2;
	}
	else if(opt == 2) {
		result = num1 - num2;
	}
	else if (opt == 3) {
		result = num1 * num2;
	}
	else (opt == 4) {
		result = num1 / num2;
	}
	printf("결과 %f", result);
	return 0;

}

//경우의 수가 많은것을 첫 조건, 맨 위에 넣는것이 좋다
//조건 연산자
int main(void)
{
	int num, abs;
	printf("정수 입력: ");
	scanf("%d", &num);

	abs = num > 0 ? num : num * (-1); // (조건) ? data : data2 
	//조건이 '참'이면 연산결과 data 1 반환, 조건이 '거짓'이면 연산결과 data2 반환
	printf("절댓값: %d \n", abs);
	return 0;
}



//문제 08-1 문제 1번 다시한번 생각해보기 7의 배수와 9의 배수를 한 줄에 출력하고 곂친다면 한번만 출력하게 만들기
#include <stdio.h>

int main(void)
{
	int i = 1;
	while (i < 100)
	{
		if (i % 7 == 0 || i % 9 == 0) {
			printf("%d 7의배수", i);
		}
		i++;
	}
}
//while문, do while문, for문 다 생각해보고 풀어보기