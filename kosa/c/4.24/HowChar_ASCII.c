#include <stdio.h>

int main(void)
{
	char ch1 = 'A', ch2 = 65;
	int ch3 = 'Z', ch4 = 90;

	printf("%c %d \n", ch1, ch1);
	printf("%c %d \n", ch2, ch2);
	printf("%c %d \n", ch3, ch3);
	printf("%c %d \n", ch4, ch4);
	
	return 0;
}
//char는 문자의 표현을 목적으로 정의된 자료형이기 대문에 문자형으로 분류하지만 정수형이다. 문자도 정수형태로 표현,실제로  변수에 저장되는것은 정수