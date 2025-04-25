/*실수 기반의 입력형태 정의하기*/

#include <stdio.h>

int main(void)
{
	float num1;
	double num2;
	long double num3;

	printf("실수 입력1(e 표기법으로): ");
	scanf("%f", &num1);
	printf("입력된 실수%f \n", num1);

	printf("실수 입력2(e 표기법으로): ");
	scanf("%lf", &num2);
	printf("입력된 실수%f \n", num2);

	printf("실수 입력3(e 표기법으로): ");
	scanf("%Lf", &num3);
	printf("입력된 실수%f \n", num3);

	return 0;

}

/* %s 문자열 출력 */

