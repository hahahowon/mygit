/*
콘스트가 앞에 있으면 함수를 바꾸지마라 별표 뒤에 붙어있으면 p의 주소를 바꾸지 마라
const char *p ::값을 못바꾼다
char *const p :: 주소를 못바꾼다
*/

//책 333p까지 읽어보기

//14-2 
//문제 1번
/*
매개변수 arr에 const를 선언한 이유는 
1. 수정되지 않는 값이라는걸 컴파일러에게 알려주기 위해 :: 장점 :: 실행속도가 빨라진다.
2. 사용자에게 고정된 값이라는 것을 알려주기 위해
*/

//문제 2번
/*

*/

#include <stdio.h>

int main(void)
{
	int num[10];
	for (int i = 0; i < 10; i++) {
		printf("%d : ", i+1), scanf("%d", num[i]);

	}
	for(int i= 0; i<10;i++){
		if (num[i] & 1 = 1) {
			printf("홀수 출력: \n", num[i]);
		
	}
	}
	
	return 0;
}

