//index 기반 사용할때 많이 사용
/*
기본 구조
for(초기(변수 생성 및 초기회; 조건; 증감)
{
반복할 내용
}
초기문 실행-> 조건문 실행(조건문이 거짓이면 빠져나감, 참이면 반복할 내용 반복)-> 증감 -> 조건 -> 증감 ~~~반복 -> 조건문 거짓이 되면 빠져나옴


for 문을 while문으로 작성했을때 예시
int i; 초기
while(i<10)조건
{
printf("llll")
i++  증감
}

//반복의 횟수가 정해진 경우 => for문, 
//프로그램 사용자가 임의의 값 입력하기만 기다리는 상황 => while or do while

*/

#include <stdio.h>
int main(void)
{
	int total = 0;
	int i, num;
	printf("0부터  num까지의 덧셈, num은? ");
	scanf_s("%d", &num);

	for (i = 0; i < num + 1 ; i++) {
		total += i;
	}
	printf("0부터 %d까지 덧셈결과: %d \n", num, total);
	return 0;
	}

//for문 중첩

#include <stdio.h>
int main(void)
{
	int cur, is;

	for (cur = 2; cur < 10; cur++)
	{
		for (is = 1; is < 10; is++) {
			printf("%d X %d = %d \n", cur, is, cur * is);
		}
		printf("\n");
	}
	return 0;
}


//for if 중첩

int main(void)
{
	int num = 0;
	printf("정수 입력:: ");
	scanf("%d", &num);

	if (num < 0) {
		printf("입력값은 0보다 작다.\n");
	}
	else {
		printf("입력값은 0보다 작지 않다.\n");
	}
	return 0;
}
