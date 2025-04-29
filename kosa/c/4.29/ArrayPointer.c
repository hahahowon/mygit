#include <stdio.h>

int main(void)
{
	int arr2d[3][3];

	printf("%p \n", arr2d);     //전체를 의미      //sizeof 는 %lu
	printf("%p \n", arr2d[0]);	//한 줄을 의미
	printf("%p \n\n", &arr2d[0][0]);


	printf("%lu \n", arr2d[1]);
	printf("%lu \n\n", &arr2d[1][0]);  //%lu와 %p 확인하자
	
	printf("%d \n", arr2d[2]);
	printf("%d \n\n", &arr2d[2][0]);

	printf("sizeof(arr2d): %d \n", sizeof(arr2d));
	printf("sizeof(arr2d[0]): %d \n", sizeof(arr2d[0]));
	printf("sizeof(arr2d[1]): %d \n", sizeof(arr2d[1]));
	printf("sizeof(arr2d[2]): %d \n", sizeof(arr2d[2]));

	return 0;
}//sizeof 는 lu



//tip
#include <stdio.h>//포인터는 요소에 더하고 빼기 가능 곱셈 나눗셈은 불가능

int main(void)
{
	int a[10] = { 10, 11, 12, 13, 14, 15 };
	int* p = &a[2];

	printf("%p\n", p + 2);    // 1
	printf("%p\n", p - 3);    // 2 //인덱스 범위를 벗어남 실행은 가능하지만 죽음!
	printf("%p\n", p * 2);    // 3 
	printf("%p\n", p / 2);    // 4

	return 0;
}


#include <stdio.h>

int main(void)
{
	int arr1[3][2];
	int arr2[2][3];

	printf("arr1: %p \n", arr1);
	printf("arr1+1: %p \n", arr1+1);
	printf("arr1+2: %p \n", arr1+2);

	printf("arr2: %p \n", arr2);
	printf("arr2+1: %p \n", arr2+1);
	return 0;
}

#include <stdio.h>

int main(void)
{
	int arr1[2][2] = {
		{1,2}, { 3,4 }
	};
	int arr2[3][2] =
	{
	{1,2}, {3,4}, {5,6}
	};
	int arr3[4][2] =
	{
	{1,2},{ 3,4 }, { 5,6 }, {7, 8}
	};

	int (*ptr)[2];
	int i;

	ptr = arr1;
	printf("** Show 2,2 arr1 \n");
	for (i = 0; i < 2;i++) {
		printf("%d %d \n", ptr[i][0], ptr[i][1]);
	}

	ptr = arr2;
	printf("** Show 3,2 arr2 ** \n");
	for (i = 0; i < 3;i++) {
		printf("%d %d \n", ptr[i][0], ptr[i][1]);
	}

	ptr = arr3;
	printf("** Show 4,2 arr3 ** \n");
	for (i = 0; i < 4;i++) {
		printf("%d %d \n", ptr[i][0], ptr[i][1]);
	}

	return 0;
}

#include <stdio.h>

int main(void)
{

	int num1 = 10, num2 = 20, num3 = 30, num4 = 40;
	int arr2d[2][4] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int i, j;

	int* whoA[4] = { &num1, &num2, &num3, &num4 };
	int (*whoB)[4] = arr2d;

	printf("%d %d %d %d \n", *whoA[0], *whoA[1], *whoA[2], *whoA[3]);
	for (i = 0; i < 2;i++) {
		for (j = 0; j < 4; j++) {
			printf("%d", whoB[i][j]);
		}
		printf("\n");
	}
	return 0;
}

#include <stdio.h>

void ShowArr2DStyle(int (*arr)[4], int column) //배열 요소 출력함수
{
	int i, j;
	for (i = 0; i < column; i++) {
		for (j = 0; j < 4;j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int Sum2DArr(int arr[][4], int column)
{
	int i, j, sum = 0;
	for (i = 0; i < column; i++) {
		for (j = 0;j < 4;j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}


int main(void)
{
	int arr1[2][4] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int arr2[3][4] = { 1, 1, 1, 1, 3, 3, 3, 3, 5, 5, 5, 5 };


	ShowArr2DStyle(arr1, sizeof(arr1) / sizeof(arr1[0]));
	ShowArr2DStyle(arr2, sizeof(arr2) / sizeof(arr2[0]));
	printf("arr1의 합: %d\n", Sum2DArr(arr1, sizeof(arr1) / sizeof(arr1[0])));
	printf("arr2의 합: %d\n", Sum2DArr(arr2, sizeof(arr2) / sizeof(arr2[0])));
	return 0;
}


//386p
#include <stdio.h>
int main(void)
{
	int a[3][2] = { {1,2},{3,4},{5,6} };

	printf("a[0]: %p \n", a[0]);
	printf("*(a+0): %p \n", *(a + 0));
	
	printf("a[1]: %p \n", a[1]);
	printf("*(a+1): %p \n", *(a + 1));

	printf("a[2]: %p \n", a[2]);
	printf("*(a+2): %p \n", *(a + 2));
	

	printf("%d %d \n", a[2][1], (*(a + 2))[1]);
	printf("%d %d \n", a[2][1], *(a[2]+1));
	printf("%d %d \n", a[2][1], *(*(a + 2)+1));
	return 0;
}

//18-1번 387p 이 문제를 설명할 수 있도록 해보자
#include <stdio.h>
int main(void)
{
	int* arr1[5];
	int* arr2[3][5];

	int** ptr1 = arr1; //일차원 배열에 접근은 그냥 포인터 변수 선언만
	int* (*ptr2)[5] = arr2; //이중포인터사용

	printf("%d %d \n", ptr2);
	return 0;

}

int *ptrarr;
int *ptrarr[4];
#include <stdio.h>

void sssss(int *(*ptr1), int *(*ptr)[5]);
void ssssa(int **(*prt1),int ***(*ptr2)[5]);
int main(void)
{
	int* arr1[3];
	int* arr2[4][5];
	int** arr3[3];
	int*** arr4[2][4];
	sssss(arr1, arr2);
	ssssa(arr3, arr4);
	return 0;
	
}


#include <stdio.h>

int main(void)
{
	int arr[2][2][2] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	printf("%d\n", arr[1][0][1]);				//교수님이 만든 솔루션
	printf("%d\n", (*(arr + 1))[0][1]);     // 1  
	printf("%d\n", (*(arr[1] + 0))[1]);     // 2
	printf("%d\n", (*(*(arr + 1) + 0))[1]);   // 3
	printf("%d\n", *(*(*(arr + 1) + 0) + 1));  // 5
	printf("%d\n", *(arr[1][0] + 0 + 1)); // 6
	printf("%d\n", *(&arr[0][0][0] + 1 + 0 * 2 + 1 * 4)); // 7 
	
	printf("%d\n", arr[1][0][1]);				//내가 짠 솔루션
	printf("%d\n", (*(arr[1] + 0))[1]);
	printf("%d\n", *(*(*(arr + 1) + 0) + 1));
	printf("%d\n", (*(arr + 1))[0][1]);
	
	return 0;

}