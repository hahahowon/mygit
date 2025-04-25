#include <stdio.h>

int main(void)
{
	double a, b;
	scanf("%ls %ls", &a, &b);

	printf("a+b=%d", a + b);
	printf("a-b=%d", a - b);
	printf("a*b=%d", a * b);
	printf("a/b=%d", a / b);
	return 0;
}