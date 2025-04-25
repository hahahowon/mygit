#include <stdio.h>

int main(void)
{
	int num1 = 7, num2 = 13;
	printf("%o %#o \n", num1, num1);//%#o 8진수 부호와 같이 출력
	printf("%x %#x \n", num2, num2);//%#x 16진수 부호와 같이 출력
	return 0;
}

