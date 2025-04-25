#include <stdio.h>
int main(void)
{
	int total = 0, num = 0;
	
	do {

		printf("정수 입력(0 to quit): ");
		scanf_s("%d", &num);
		total += num;
		printf("%d %d\n", num, total);//과정 확인용 출력코드

	} while (num != 0);

	printf("합계:%d \n", total);
	return 0;

}