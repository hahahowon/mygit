/*
메모리의 위치를 모아 사용할때 더블포인터사용
포인터도 주소를 가지고 있으며 이를 가리키기 이중포인터 사용
*/

/*
#include <stdio.h>

int main(void)
{
	double num = 3.14;
	double* ptr = &num; //num 주소값 저장
	double** dptr = &ptr;//ptr 의 주소 가리킴
	double* ptr2;//ptr2 포인터 변수만 선언

	printf("%9p %9p \n", ptr, *dptr);//ptr과 dptr 주소값 출력
	printf("%9g %9g \n", num, **dptr);// num의 값과 dptr이 가리키는 값 출력 num =3.14 -> ptr -> dptr //dptr에 **두번 써야 num에 접근가능

	ptr2 = *dptr; //ptr2 -> dptr;
	*ptr2 = 10.99;//ptr2로 값 변경  num =3.14 -> ptr -> dptr -> ptr2 10.99 변경

	printf("%9g %9g \n", num, **dptr); // 10.99, 10.99 출력

	return 0;
}	

*/
#include <stdio.h>

void SwapIntPTr(int* p1, int* p2)// p1, p2 주소값 변경, 하지만 변경시키지 못함
{
	int* temp = p1;
	p1 = p2;
	p2 = temp;
}
//위 함수는 선언된 p1과 p2에 저장된 값만 바뀐다.
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

//포인터 배열

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




//문제 17-1 368p

void MaxAndMin(int **dptr, int **dptr)


int* maxPtr;
int* minPTr;
int arr[5];