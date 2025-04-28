//회문, 앞으로읽어도 뒤로 읽어도 같은 단어들
// 문자열을 입력받고 for 문을 사용해서 돌리고, 거꾸로 돌리고, 둘이 같은지 확인하기
//같다면 회문 입니다 출력


#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[BUFSIZ];
	printf("입력하세요: ");
	scanf("%d", str);

	int len = strlen(str);


	return 0;
}


//string 헤더파일을 사용하지 않고 길이를 직접 구한 방법
int main(void)
{	
	int len = 0;
	char str[BUFSIZ];
	printf("입력하세요: ");
	scanf("%d", str);
	
	while (1) {
		if (str[len++] == '\0') {
			break;
		}
	}
	len--;
	printf("length : %d\n", len);//while부터 여기까지 문자열 길이 

	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]) {
			printf("회문이 아입니다 \n");
			break;
		}


	return 0;
}

//문제 도전 5번
