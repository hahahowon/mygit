#include <stdio.h>

int main(void)
{
	int result;
	int num1, num2;

	printf("���� one: ");
	scanf("%d", &num1); //num1 ���� �Է�
	printf("���� two: ");
	scanf("%d", &num2); //num2 ���� �Է�

	result = num1 + num2;
	printf("%d+%d=%d\n", num1, num2, result); //�Է°� ���� ��� ���
	return 0;

}

//scanf�� ���ȹ����� scanf_s�� ���

