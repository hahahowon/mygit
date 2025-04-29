/*
�޸��� ��ġ�� ��� ����Ҷ� ���������ͻ��
�����͵� �ּҸ� ������ ������ �̸� ����Ű�� ���������� ���
*/

/*
#include <stdio.h>

int main(void)
{
	double num = 3.14;
	double* ptr = &num; //num �ּҰ� ����
	double** dptr = &ptr;//ptr �� �ּ� ����Ŵ
	double* ptr2;//ptr2 ������ ������ ����

	printf("%9p %9p \n", ptr, *dptr);//ptr�� dptr �ּҰ� ���
	printf("%9g %9g \n", num, **dptr);// num�� ���� dptr�� ����Ű�� �� ��� num =3.14 -> ptr -> dptr //dptr�� **�ι� ��� num�� ���ٰ���

	ptr2 = *dptr; //ptr2 -> dptr;
	*ptr2 = 10.99;//ptr2�� �� ����  num =3.14 -> ptr -> dptr -> ptr2 10.99 ����

	printf("%9g %9g \n", num, **dptr); // 10.99, 10.99 ���

	return 0;
}	

*/
#include <stdio.h>

void SwapIntPTr(int* p1, int* p2)// p1, p2 �ּҰ� ����, ������ �����Ű�� ����
{
	int* temp = p1;
	p1 = p2;
	p2 = temp;
}
//�� �Լ��� ����� p1�� p2�� ����� ���� �ٲ��.
int main(void)
{
	int num1 = 10, num2 = 20;
	int* ptr1, *ptr2;
	ptr1 = &num1, ptr2 = &num2;
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);

	SwapIntPTr(&ptr1, &ptr2);
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);
	return 0;
}

#include <stdio.h>

void SwapIntPTr(int** dp1, int** dp2)
{
	int* temp = *dp1;
	*dp1 = *dp2;
	*dp2 = temp;
}

int main(void)
{
	int num1 = 10, num2 = 20;
	int* ptr1, * ptr2;
	ptr1 = &num1, ptr2 = &num2;
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);

	SwapIntPTr(&ptr1, &ptr2); // 
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);
	return 0;
}

//������ �迭

#include <stdio.h>

int main(void)
{
	int num1 = 10, num2 = 20, num3 = 30;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	int* ptr3 = &num3;

	int* ptrarr[] = { ptr1, ptr2,ptr3 };
	int** dptr = ptrarr;

	printf("%d %d %d \n", *(ptrarr[0]), *(ptrarr[1]), *(ptrarr[2]));
	printf("%d %d %d \n", *(dptr[0]), *(dptr[1]), *(dptr[2]));
	return 0;
}




//���� 17-1 368p

void MaxAndMin(int **dptr, int **dptr)


int* maxPtr;
int* minPTr;
int arr[5];