/*���ڿ��� �����ϴ� ������ �迭*/

// simple, string,Array�� �����ϴ� ������ �迭��������

#include <stdio.h>
int main(void)
{
	char* strArr[3] = { "simple", "string", "Array" };
	//���� ����� �迭�� ����غ���
	printf("%s \n", strArr[0]);
	printf("%s \n", strArr[1]);
	printf("%s \n", strArr[2]);
	return 0;
}

/*
stack -> �Ű� ����
*/
#include <stdio.h>

void ShowArayElem(int* param, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		printf("%d ", param[i]);
	}
	printf("\n");
}

int main(void)
{
	int arr1[3] = { 1, 2, 3 };
	int arr2[5] = { 4, 5, 6, 7, 8 };
	ShowArayElem(arr1, Sizeof(arr1) / sizeof(int));
	ShowArayElem(arr2, Sizeof(arr2) / sizeof(int));
	return 0;
}


#include <stdio.h>
void ShowArayElem(int* param, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		printf("%d ", param[i]);
	}
	printf("\n");
}


void AddArayElem(int* param, int len, int add)
{
	int i;
	for (i = 0;i < len;i++)
	{
		param[i] += add;
	}
}

int main(void)
{
	int arr[3] = { 1, 2, 3, };
	AddArayElem(arr, sizeof(arr) / sizeof(int), 1);
	ShowArayElem(arr, sizeof(arr) / sizeof(int));

	AddArayElem(arr, sizeof(arr) / sizeof(int), 2);
	ShowArayElem(arr, sizeof(arr) / sizeof(int));

	AddArayElem(arr, sizeof(arr) / sizeof(int), 3);
	ShowArayElem(arr, sizeof(arr) / sizeof(int));

	return 0;
}

#include <stdio.h>

void Swap(int n1, int n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
	printf("n1 n2: %d %d \n", n1, n2);
}

int main(void)
{
	int num1 = 10;
	int num2 = 20;
	printf("num1 num2: %d %d \n", num1, num2);

	Swap(num1, num2);
	printf("num1 num2: %d %d \n", num1, num2);
	return 0;
}




#include <stdio.h>
void Swap(int* ptr1, int* ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
	printf("n1 n2: %d %d \n", *ptr1, *ptr2);
}

int main(void)
{
	int num1 = 10;
	int num2 = 20;
	printf("num1 num2: %d %d \n", num1, num2);

	Swap(&num1, &num2);//&����ؼ� �ּҰ� �ʱ�ȭ
	printf("num1 num2: %d %d \n", num1, num2);
	return 0;
}


//14-1 ���� 1��
#include <stdio.h>

void CallByValue(int n1)
{
	n1 *= n1;
	printf("%d\n", n1);
	return n1;
}


void CallByReference(int* ptr)
{
	*ptr *= *ptr;
	printf("%d\n", *ptr);
	return *ptr;
}

int main(void)
{
	int num;
	scanf_s("%d", &num);
	CallByValue(num);
	printf("%d\n", num);
	CallByReference(&num);
	printf("%d", num);
	return 0;
}
/*
���
100
10000
100
10000
*/


//14-1 ���� 2��
#include <stdio.h>
void Swap3(int* ptr1, int* ptr2, int* ptr3)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = *ptr3;
	*ptr3 = temp;
	return temp;
}

int main(void)
{
	int num1 = 1, num2 = 2, num3 = 3;
	printf("num1: %d, num2: %d, num3: %d", num1, num2, num3);

	Swap3(&num1, &num2, &num3);
	printf("num1: %d, num2: %d, num3: %d", num1, num2, num3);
	return 0;
}

///���� ���α׷���
//���� 1��
#include <stdio.h>

int main(void)
{
	int num[10];
	for (int i = 0; i < 10; i++) {
		printf("%d : ", i + 1), scanf_s("%d", &num[i]);
	}
	//�Է°��� �迭�� ����� ����
	printf("Ȧ�� ���: ");
	for (int i = 0; i < 10; i++)
	{
		if ((num[i] & 01) == 1) {  // (num[i] & 2 == 1)������ ��ȣ�ȿ� �־��
			printf("%d", num[i]);
		}
	}
	printf("¦�� ���: ");
	for (int i = 0; i < 10; i++)
	{
		if ((num[i] & 0) == 0) {  // (num[i] & 2 == 1)������ ��ȣ�ȿ� �־��
			printf("%d", num[i]);
		}
	}
	return 0;


}

//���� ���� 3��
#include <stdio.h>

int main(void)
{

	int num[10];
	for (int i = 0; i < 10; i++) {
		printf("%d : ", i + 1), scanf_s("%d", &num[i]);
	}
	printf("�迭��� ��� :");
	for (int i = 0; i < 10; i++) {
		if ((num[i] & 01) == 1)
			printf(" %d", num[i]);
	}

	for (int i = 0; i < 10; ++i) {//�迭 �Ųٷ� ����ϱ� �غ���
		if ((num[i] & 01) == 0)
			printf(" %d", num[i]);
	}
	printf("\n");


	return 0;
}

//������ �ڵ� **������ ���**
#include <stdio.h>

int main(void)
{
	int num[10], a;
	int* start = num;
	int* end = num + 9;
	for (int i = 0; i < 10; i++) {
		printf("%d : ", i + 1);
		scanf("%d", &a);
		if ((a & 01) == 0)*(end--) = a; else *(start++) = a;
	}
	printf("Print the Element of Array : [");
	for (int i = 0; i < 10; i++) {
		printf("%d, ", num[i]);
	}
	printf("\b\b]\n");

	return 0;
}