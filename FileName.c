#include <stdio.h>

int main(void)
{
	int x1, y1;
	int x2, y2;
	int area;
	printf("�� ��� ��ǥ �Է� :");
	scanf_s("%d %d", &x1, &y1);
	printf("�� �ϴ� ��ǥ �Է� :");
	scanf_s("%d %d", &x2, &y2);

	printf(" �� ����� x, y ��ǥ: %d %d", x1, y1);
	printf(" �� �ϴ��� x, y ��ǥ: %d %d", x2, y2);
	
	printf(" �� ���� �̷�� ���簢���� ���̴� %d�Դϴ�.", (x2 - x1) * (y2 - y1));
	return 0;
	
}

int main(void)
{
	int a;
	scanf_s("%d", & a);
	printf("%c", a);
		return 0;

}

int main(void)
{
	char ch;
	scanf_s("%c", &ch);
	printf("%c", ch);
	return 0;

}
