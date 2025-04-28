/*

**포인터와 배열의 차이
포인터는 크기가 고정되어있지 않다, 배열의 크기는 인덱스의 크기로 지정되어있음

*/

#include <stdio.h>

int main(void)
{
	int num1 = 10, num2 = 20, num3 = 30;
	int* arr[3] = { &num1, &num2, &num3 };//int형 포인터 배열 선언하고 위에서 선언한 변수의 주소 값으로 초기화
										  // &를 넣어서 주소 값 초기화 해주어야 함**기본**
	printf("%d \n", *arr[0]);//배열요소가 가리키는 변수에 저장된 값을 출력
	printf("%d \n", *arr[1]);
	printf("%d \n", *arr[2]);
	return 0;
}