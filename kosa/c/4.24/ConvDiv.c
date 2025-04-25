#include <stdio.h>

int main(void)
{
	
	int num1 = 3, num2 = 4;
	double divResult;
	divResult = num1 / num2;

	printf("나눗셈 결과: %f \n", divResult);
	return 0;

}
//나눗셈을 위해 강제적 형 변환이 필요하다.
//아래와 같이 변경
#include <stdio.h>

int main(void)
{

	int num1 = 3, num2 = 4;
	double divResult;
	divResult = (double)num1 / num2;

	printf("나눗셈 결과: %f \n", divResult);
	return 0;

}

