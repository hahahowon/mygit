#include <stdio.h>
int main(void)
{
	int total = 0, num = 0;
	
	do {

		printf("���� �Է�(0 to quit): ");
		scanf_s("%d", &num);
		total += num;
		printf("%d %d\n", num, total);//���� Ȯ�ο� ����ڵ�

	} while (num != 0);

	printf("�հ�:%d \n", total);
	return 0;

}