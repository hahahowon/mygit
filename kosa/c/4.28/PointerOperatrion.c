/*
배열 이름을 포인터처럼, 포인터를 배열 이름처럼 활요하는 것이 가능
포인터 연산:: 포인터가 지니는 값을 증가 혹은 감소시키는 연산을의미
ptr++;
prt1 +=3;
--ptr;
ptr2=ptr1+2;
위 연산에 대해 해석하기
*/

#include <stdio.h>

int main(void)
{
	int* ptr1 = 0x0010;
	double* ptr2 = 0x0010;
	printf("%p %p \n", ptr1, ptr2);
	
	printf("%p %p \n", ptr1 + 1, ptr1 + 2);
	printf("%p %p \n", ptr2 + 1, ptr2 + 2);

	printf("%p %p \n", ptr1, ptr2);
	ptr1++;
	ptr2++;
	printf("%p %p \n", ptr1, ptr2);
	return 0;
}
//포인터에 ++연산자를 쓰면 요소를 증가시킨다 즉 int형 데이터인 4바이트, double형 데이터 8바이트 증가한다.
//sizeof(int) 크기만큼, sizeof(double) 크기만큼 증가

#include <stdio.h>

int main(void)
{
	int arr[3] = { 11, 22, 33 };// ex) 각 배열이 주소 0x001000, 0x001004, 0x001008 저장 (int형 이기에 주소값 4바이트씩 증가.)
	int* ptr = arr; //int *ptr=&arr[0]; 과 같은 문장
	printf("%d %d %d \n", *ptr, *(ptr + 1), *(ptr + 2));// 첫 번째 주소, 두 번째 주소, 세 번째 주소 출력

	printf("%d ", *ptr); ptr++; //주소 증가 출력:: 22
	printf("%d ", *ptr); ptr++; //주소 증가 출력:: 33
	printf("%d ", *ptr); ptr--; //주소 감소 출력:: 22
	printf("%d ", *ptr); ptr--; //주소 감소 출력:: 11
	printf("%d ", *ptr); printf("\n");
	return 0;

}
//이해가 안되면 배열로 바꾸어서 짜보고, 잘 되면 포인터로 변경후 확인해보기


//299p~~~ 300p까지 문제 풀어보기 ::오늘 저녁
int main(void)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptr = &arr[0];//ptr// 인덱스 0으로 한 이유 알아오기
	for (int i = 0; i < 5; i++) {
		*(ptr + 2);
		}
	for (int j = 0; j < 5;j++) {
		printf("%d : %d\n", arr[j], ptr[j]);
	}

	return 0;
}