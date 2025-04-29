#include <stdio.h>
int main(void)
{
	int ch1, ch2;
	
	ch1 = getchar();//문자입력
	ch2 = fgetc(stdin);//엔터 키 입력

	putchar(ch1); // 문자 출력
	fputc(ch2, stdout); //엔터 키 출력
	return 0;

}

#include <stdio.h>
int main(void)
{
	int ch;

	while (1)//무한반복루프
	{
		ch = getchar();
		
		if (ch == EOF) {
			break;
		} 
		putchar(ch);
	}
	return 0;
}


int main(void) {
	//아스키 코드를 활용 소문자와 대문자의 수 차이느 32

}
#include <stdio.h>
int main(void)
{
	int ch;
	int diff = 'a' - 'A';
	if (ch >= 'A' && ch <= 'Z')
		return ch + diff;
	else if (ch >= 'a' && ch <= 'z')
		return ch - diff;
	else
		return -1;
}

// Online C compiler to run C program online
#include <stdio.h>

int main() {
	int arr[5];
	printf("5개의 수를 입력하시오. ");

	while
		return 0;
}



#include <stdio.h>
int main(void)
{
	int arr[5];
	printf("5개의 수를 입력하시오. ");

	for (int j = 0; j < 5;j++) {
		scanf("%d", &arr[j]);
	}
	for (int i = 0; i < 5; i++) {
		printf("%d", arr[i]);
	}
	return 0;

}