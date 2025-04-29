#include <stdio.h>

int main(void)
{
	printf("main : %p\n", main);
	printf("printf : %p\n", printf);
	printf("scanf : %p\n", scanf);

	return 0;
}////�Լ��� �ּ�

#include <stdio.h>

void SimpleAdder(int n1, int n2)
{
	printf("%d + %d = %d", n1, n2, n1 + n2);
}
void ShowString(char* str)
{
	printf("%s \n", str);
}

int main(void)
{
	char* str = "Function Pointer";
	int num1 = 10, num2 = 20;

	void (*fptr1)(int, int) = SimpleAdder;
	void (*fptr2)(char*) = SimpleAdder;
	
	/*�Լ� ������ ������ ���� ȣ��*/
	fptr1(num1, num2);
	fptr2(str);
	return 0;
}

//�Ű����� �������� �Լ� ������ ������ �� �� ������ ���̰� ���޵Ǵ� ���ڿ� ���� �޸� �����ϴ� �Լ� ����

#include <stdio.h>
int WhoIsFirst(int age1, int age2, int (*cmp)(int n1, int n2))
{
	return cmp(age1, age2);
}

int OlderFirst(int age1, int age2)
{
	if(age1 > age2) {
		return age1;
	}
	else if(age1<age2){
		return age2;
	}
	else
		return 0;

	//ifreturn = (age1>age2) ? age1:age2)
}


int Youngerfirst(int age1, int age2)
{
	if (age1 < age2) {
		return age1;
	}
	else if (age1 > age2) {
		return age2;
	}
	else
		return 0;
}

int main(void)
{
	int age1 = 20;
	int age2 = 30;
	int first;

	printf("������� 1 \n");
	first = WhoIsFirst(age1, age2, OlderFirst);
	printf("%d���� %d�� �� %d���� ���� ���� \n\n", age1, age2, first);


	printf("������� 2 \n");
	first = WhoIsFirst(age1, age2, Youngerfirst);
	printf("%d���� %d�� �� %d���� ���� ���� \n\n", age1, age2, first);
	return 0;
}


#include <stdio.h>

float add(int n1, int n2);
float minus(int n1, int n2);
float mul(int n1, int n2);
float div(int n1, int n2);

int main(void)
{
	int n1, n2;
	int op;
	float result;

	printf("�����Դϴ�. ���Ͻô� ��带 �������ּ���.\n1. ����, 2. ����, 3. ����, 4. ������");
	scanf("%s", &op);

	switch (op)
	{

	case1:
		printf("�� ���� �Է����ּ���:");
		scanf("%lf %lf", &n1, &n2);
		result = add(n1, n2);
		printf("%lf", result);

	}
	{
	case2:
		printf("�� ���� �Է����ּ���:");
		scanf("%lf %lf", &n1, &n2);
		result = minus(n1, n2);

	}
	{
	case3:
		printf("�� ���� �Է����ּ���:");
		scanf("%lf %lf", &n1, &n2);
		result = mul(n1, n2);
	}
	{
	case4:
		printf("�� ���� �Է����ּ���:");
		scanf("%lf %lf", &n1, &n2);
		result = div(n1, n2);
	}

	return 0;
}

float add(int n1, int n2)
{
	printf("%lf + %lf = %lf", n1, n2, n1 + n2);
}
float minus(int n1, int n2)
{
	printf("%lf - %lf = %lf", n1, n2, n1 - n2);
}
float mul(int n1, int n2)
{
	printf("%lf * %lf = %lf", n1, n2, n1 * n2);
}
float div(int n1, int n2)
{
	printf("%lf / %lf = %lf", n1, n2, n1 / n2);
}



//�̰� ���� �ȵǴ� ���� ã�� ��ġ��

////������ �ڵ�

#include <stdio.h>

float add(int n1, int n2);
float minus(int n1, int n2);
float mul(int n1, int n2);
float div(int n1, int n2);

int main(void)
{
	int n1, n2;
	char op;
	float result;

	printf("input num1 op num2 : ");
	scanf("%d %c %d", &n1, &op, &n2);

	switch (op) {
	case '+': result = add(n1, n2); break;
	case '-': result = minus(n1, n2); break;
	case '*': result = mul(n1, n2); break;
	case '/': result = div(n1, n2); break;
	}
	printf("%d %c %d = %f\n", n1, op, n2, result);
	return 0;
}

float add(int n1, int n2)
{
	return n1 + n2;
}

float minus(int n1, int n2)
{
	return n1 - n2;
}

float mul(int n1, int n2)
{
	return n1 * n2;
}

float div(int n1, int n2)
{
	return n1 / (float)n2;
}




//�Լ������ͷ� ��ȯ

#include <stdio.h>
float funcPtr(int n1, int n2, float(*fptr)(int p1, int p2));
float add(int n1, int n2);
float minus(int n1, int n2);
float mul(int n1, int n2);
float div(int n1, int n2);

int main(void)
{

	int n1, n2;
	char op;
	float result;
	printf("input num1 op num2 : ");
	scanf("%d %c %d", &n1, &op, &n2);

	switch (op) {
	case '+': result = funcPtr(n1, n2, add); break;
	case '-': result = funcPtr(n1, n2, minus); break;
	case '*': result = funcPtr(n1, n2, mul); break;
	case '/': result = funcPtr(n1, n2, div); break;
	}

	printf("%d %c %d = %f\n", n1, op, n2, result);
	return 0;
}

float add(int n1, int n2)
{
	return n1 + n2;
}

float minus(int n1, int n2)
{
	return n1 - n2;
}

float mul(int n1, int n2)
{
	return n1 * n2;
}

float div(int n1, int n2)
{
	return n1 / (float)n2;
}

float funcPtr(int n1, int n2, float(*fptr)(int p1, int p2))
{
	return fptr(n1, n2);
}


//���� ���α׷���::::
{
	{ 1, 2, 3, 4 },
	{ 5, 6, 7, 8 },
	{ 9, 10, 11, 12 },
	{ 13, 14, 15, 16 }
};

int main(void)
{	
	int arr[4][4];

	//������ ���� ���
	for (int i = 0; i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			printf("%2d", arr[i][j]);
		}
	}
	
	//�迭����
	//ȸ���� �ؾ��Ѵ�.
	//�����͸� ����ϸ� ���� �ű� �� ���� �迭�� �׷� �迭�� ��Ģ���� �ִ��� Ȯ��


	return 0;
}