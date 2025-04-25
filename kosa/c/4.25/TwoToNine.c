#include <stdio.h>
/*
int main(void)
{
	int i = 0, j = 0;
	int num = 0;

	while (i < 10) {
		while (j < 10) {
			num++;
			j++;
			printf("%d %d\n", num, j);
		}
		i++;
		j = 0;
		printf("%d %d\n", i, j);
	}
	return 0; 
}
*/

int main(void)
{
	int cur = 2;
	int is = 0;

	while (cur < 10)
	{
		is = 1;
		while (is < 10) {
			printf("%d X %d = %d\n", cur, is, cur * is);
			is++;
		}
		cur++;
	}
	return 0;
}

//쉬는시간에 한번 확인
