#include <stdio.h>

int main(void)
{
	int num;

	printf("���� �Է�: ");
	scanf("%d", &num);

	if (num < 0) {
		printf("�Է� ���� 0���� �۴�. \n");
	}
	if (num > 0) {
		printf("�Է� ���� 0���� ũ��. \n");
	}
	if (num == 0) {
		printf("�Է� ���� 0�̴�. \n");
	}
	return 0;
}



int main(void)
{
	int num;

	printf("���� �Է�: ");
	scanf("%d", &num);

	if (num < 0) {
		printf("�Է� ���� 0���� �۴�. \n");
	}
	else if (num > 0) {
		printf("�Է� ���� 0���� ũ��. \n");
	}
	else (num == 0) {
		printf("�Է� ���� 0�̴�. \n");
	}
	return 0;
}


//if �� ��Ģ����

int main(void)
{
	int opt;//�޴�����
	double num1, num2;// �� ���� ����
	double result;

	printf("1. ����, 2 ����, 3. ����, 4. ������ :: ��ȣ�� �����Ͻÿ�.\n");
	scanf("%d", &opt);
	printf("�� ���� �Ǽ��� �Է�::");
	scanf("%lf %lf", &num1, &num2);

	if (opt == 1) {
		result = num1 + num2;
	}
	if (opt == 2) {
		result = num1 - num2;
	}
	if (opt == 3) {
		result = num1 * num2;
	}
	if (opt == 4) {
		result = num1 / num2;
	}
	printf("��� %f", result);
	return 0;

}

//if else
int main(void)
{
	int num = 0;
	printf("���� �Է�:: ");
	scanf("%d", &num);

	if (num < 0) {
		printf("�Է°��� 0���� �۴�.\n");
	}
	else {
		printf("�Է°��� 0���� ���� �ʴ�.\n");
	}
	return 0;
}


int main(void)
{
	int opt;//�޴�����
	double num1, num2;// �� ���� ����
	double result;

	printf("1. ����, 2 ����, 3. ����, 4. ������ :: ��ȣ�� �����Ͻÿ�.\n");
	scanf("%d", &opt);
	printf("�� ���� �Ǽ��� �Է�::");
	scanf("%lf %lf", &num1, &num2);

	if (opt == 1) {
		result = num1 + num2;
	}
	else if(opt == 2) {
		result = num1 - num2;
	}
	else if (opt == 3) {
		result = num1 * num2;
	}
	else (opt == 4) {
		result = num1 / num2;
	}
	printf("��� %f", result);
	return 0;

}

//����� ���� �������� ù ����, �� ���� �ִ°��� ����
//���� ������
int main(void)
{
	int num, abs;
	printf("���� �Է�: ");
	scanf("%d", &num);

	abs = num > 0 ? num : num * (-1); // (����) ? data : data2 
	//������ '��'�̸� ������ data 1 ��ȯ, ������ '����'�̸� ������ data2 ��ȯ
	printf("����: %d \n", abs);
	return 0;
}



//���� 08-1 ���� 1�� �ٽ��ѹ� �����غ��� 7�� ����� 9�� ����� �� �ٿ� ����ϰ� ��ģ�ٸ� �ѹ��� ����ϰ� �����
#include <stdio.h>

int main(void)
{
	int i = 1;
	while (i < 100)
	{
		if (i % 7 == 0 || i % 9 == 0) {
			printf("%d 7�ǹ��", i);
		}
		i++;
	}
}
//while��, do while��, for�� �� �����غ��� Ǯ���