/*
�� ��: Operator
�� ��: ���ڿ��� ���
�����̸�: Operator.c
������¥: 2025. 04. 23
�ۼ���: ��ȣ��
*/



#include <stdio.h>

int main(void)
{
	3 + 4; // 3�� 4�� ���� �����, ������ ���� �ʿ�
	return 0;
}
//


int main(void)
{
	int num1, num2;									//���� num1, num2�� ����
	int num3 = 30, num4 = 40;						//���� num3, num4 ���� �� �ʱ�ȭ

	printf("num1: %d, num2: %d\n", num1, num2);		//���� num1, num2 ���
	num1 = 10;										//���� num1 �ʱ�ȭ
	num2 = 20;										//���� num1 �ʱ�ȭ

	printf("num1: %d, num2: %d \n", num1, num2);	//���� num1, num2 ���
	printf("num3: %d, num4: %d \n", num3, num4);	//���� num3, num4 ���
	
	return 0;										//0���� ��ȯ
}


int main(void)
{
	int a, b;
	int c = 30, d = 40;

	a = 10;
	b = 20;

	printf("%d %d \n", a, b);
	printf("%d %d \n", c, d);

	return 0;
}

/*�������α׷� �ϼ�*/

int main(void)
{
	int num1 = 3, num2 = 4; //���� ���� �� �ʱ�ȭ
	int result;				//����� ���� ����
	result = num1 + num2;	//����� ������ ���� ��� ����

	printf("���� ��� : %d \n", result); //������� result ����� �� ���
	printf("%d ���ϱ� %d�� %d �Դϴ�.\n", num1, num2, result);// num1, 2 ������ result ����� �� ���
	printf("���� result�� ����� �� : %d \n", result); // result ����� �� ���

	return 0;

}
