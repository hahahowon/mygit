#include <stdio.h>

int main(void) 
{
	int dan = 0, num = 1;
	printf("¸î ´Ü? ");
	scanf_s("%d",dan);

	while (num < 10){
		printf("%d X %d = %d", dan, num, dan * num);
		num++;
	}
	return 0;

}