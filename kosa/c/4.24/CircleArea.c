#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
int main(void)
{
	double rad;
	double area;
	printf("���� ������ �Է�: ");
	scanf_s("%lf", &rad);

	area = rad * rad * M_PI;
	printf("���� ����: %f", area);
	return 0;
}

//visual studio�� scanf �� ���� �ʴ´� ����ϱ� scanf_s�� ��� ����

/*
#define _USE_MATH_DEFINES
#include <math.h>
�� �� ���� �߰��ؼ� 3.1415������ �����Է´�� M_PI�� ��밡��
*/

//���ڿ� ���ڿ� ���� '����' "���ڿ�"