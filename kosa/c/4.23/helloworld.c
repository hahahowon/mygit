/*
제 목: Hello world 출력하기
기 능: 문자열의 출력
파일이름: FileName.c
수정날짜: 2025. 04. 23
작성자: 김호원
*/

#include <stdio.h>					//stdio.h 헤더파일 포함(선언)



int main(void)						// main 함수의 시작
{
	/*
	printf 함수는 모니터로 출력을 하는 경우에 쓴다.
	인자로 문자열을 전달하면 문자열의 출력한다.
	*/
	printf("Hello, World! \n");		//모니터로 문자열 출력
	return 0;						//0을 반환
}									// main 함수의 끝
									

//;로 끝나야 문장
//ALU 정수 처리 FPU 실수 처리
//mac, linux는 gcc 컴파일러 많이 사용
//주석은 전체 코드의 30% 이상 작성(방산에서는 30%이상 넘지안으면 통과 안됌)
//C 표준 라이브러기 libc.so
// 출력 형태int, 함수이름main 입력형태(void)
//
//레포트 제출 주석달기
//_start_up() 나중에 나올 이야기



#include <stdio.h>

int main(void)
{
	printf("Hello Everybody \n");
	printf("%d \n", 1234);
	printf("%d %d \n", 10, 20);
	return 0;

}
