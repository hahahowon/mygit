
#include <stdio.h>


int main(void)
{
	char* str = "Simple String";

	printf("1. puts test ------ \n");
	puts(str); //puts 함수의 출력대상은 stdout으로 결정되어있다
	puts("So Simple String");

	printf("2. fputs test -----\n");
	fputs(str, stdout); printf("\n");//fputs 함수는 두 번째 인자를 통해서 출력의 대상을 결정 가능
	fputs("So Simple string", stdout); printf("\n");

	printf("3. end of main-----\n");
	return 0;
}
//공통적으로 첫 번째 인자로 전달되는 주소 값의 문자열을 출력한다
//출력의 형태에 있어 차이점이 있음 책 424p
//stdout 기억

//stdin으로부터 문자열을 입력 받아서 배열 str에 저장하되 sizeof(str)의 길이만큼만 저장해라.
#include <stdio.n>

int main(void)
{
	char str[7];
	int i;

	for (i = 0; i < 3; i++)
	{
		fgets(str, sizeof(str), stdin);
		printf("Read %d: %s\n", i + 1, str);
	}
	return 0;
}


//gets 함수는 버퍼의 크기를 지정해서 입력받는 크기를 조절할 수 있다.
// 보안 이슈로 gets_s로 vs에서는 변경됨

//버퍼(buffer)
//입출력사이에 존재하는 버퍼의 이해
//여분의 임시 메모리적 특징
//성능향상
// 한번에 모아서 보내고 한번에 모아서  가능하게 만들기
#include <stdio.h>

int main(void)
{
	char perID[7];
	char name[10];

	fputs("주민번호 앞 6자리 입력:", stdout);
	fgets(perID, sizeof(perID), stdin); //변수가 포인터로 선언되어있으면 sizeof 불가능 배열의 크기로 나옴
	
	fflush(stdin); //입력버퍼 지운다.

	fputs("이름 입력: ", stdout);
	fgets(name, sizeof(name), stdin);

	printf("주민번호 :%s \n", perID);
	printf("주민번호 :%s \n", name);

	return 0;
}

/*
주민번호 앞 6자리 입력 : 1234567
이름 입력 : 주민번호:123456
주민번호 : 7

문제: 이름을 입력할 기회를 얻지 못했다.
첫 번째 입출력에서 입력받은 문자는 null 문자 제외 최대 6문자 입력가능:[7]로 인덱스값 지정했기 때문
하지만 입력된 값은 1,2,3,4,5,6,7,이다 6까지는 그래서 6까지 출력되고 입력버퍼에 7과 null이 남아있다
두 번째 fgets로 입력받아야 하지만 fgets 는 \n을 만날때 까지 읽어들이는 함수로 입력하지 못하고 바로
프린트로 넘어가버림 그래서 입력버퍼에 남아있던 7이 출력됨
*/


#include <stdio.h>
void ClearLineFromReadBuffer(void)
{
	while (getchar() != '\n');
}

int main(void)
{
	char perID[7];
	char name[10];

	fputs("주민번호 앞 6자리 입력:", stdout);
	fgets(perID, sizeof(perID), stdin); //변수가 포인터로 선언되어있으면 sizeof 불가능 배열의 크기로 나옴
	ClearLineFromReadBuffer();

	fputs("이름 입력: ", stdout);
	fgets(name, sizeof(name), stdin);

	printf("주민번호 :%s \n", perID);
	printf("주민번호 :%s \n", name);

	return 0;
}

//7자리 까지 가면 7 사라지면서 출력
//


#include  <stdio.h>
#include  <string.h>

void RemoveBSN(char str[])
{
	int len = strlen(str);
	str[len - 1] = 0;
}

int main(void)
{
	char str[100];
	printf("문자열 입력: ");
	fgets(str, sizeof(str), stdin);
	printf("길이 : %d, 내용 : %s", strlen(str), str);

	RemoveBSN(str);
	printf("길이 : %d, 내용 : %s", strlen(str), str);
	return 0;
}

#include  <stdio.h>
#include  <string.h>

int main(void)
{
	char str1[20] = "1234567890";
	char str2[20];
	char str3[5];

	/**** case1 ****/
	strcpy(str2, str1);
	puts(str2);

	/**** case2 ****/
	strncpy(str3, str1, sizeof(str3));
	puts(str3);

	/**** case3 ****/
	strncpy(str3, str1, sizeof(str3) - 1);
	str3[sizeof(str3) - 1] = 0;

	puts(str2);
	return 0;
}// 이것 또한 보안이슈로 _s 붙여주어야 함
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[20] = "First~";
	char str2[20] = "Second";

	char str3[20] = "Simple num: ";
	char str4[20] = "1234567890";

	/**** case 1 ****/
	strcat(str1, str2);
	puts(str1);

	/**** case 2 ****/
	strncat(str3, str4, 7); //str3 뒤에, str4 덧붙이되, 문자 7개만
	puts(str3); //

	return 0;


}// 이것 또한 보안이슈로 _s 붙여주어야 함// 오버플로우가 발생할만한 것들은 _s 붙이기

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[20] = "First~";
	char str2[20] = "Second";
	printf("문자열 입력 1: ");
	scanf("%s", str1);
	printf("문자열 입력 2: ");
	scanf("%s", str2);

	if (!strcmp(str1, str2))
	{
		puts("두 문자열은 완벽히 동일합니다.");
	}
	else
	{
		puts("두 문자열은 동일하지 않습니다. ");
		
		if (!strncmp(str1, str2, 3))
		{
			puts("그러나 앞 세 글자는 동일합니다. ");
		}
	}

	return 0;
}


///문자열을 숫자로 변환
#include<stdlib.h>
int atoi(char* ptr);	// 문자열을 int형 데이터로 변환
long atol(char* ptr);	// 문자열을 long형 데이터로 변환
double atof(char* str); // 문자열을 double형 데이터로 변환

//대 소문자의 변환을 처리하는 함수
#include <ctypes.h>
int toupper(int c); //소문자를 대문자로
int tolower(int c); //대문자를 소문자로


//

#include <stdio.h>
#include <stdio.h>

int main(void)
{
	char str[20], tmp[]
	char* ptr = &str[20];
	scanf("%s", str);
	
	int atoi(char* ptr);
	for (int i = 0; i < sizeof(str); i++)
	{
		printf("%d", str);
	}
	return 0;
}


int maint(void)
{
	char str[BUFSIZ], tmp[BUFSIZ];
	char tum{ BUFSIZ };
	long sum = 0, cnt = 0;
	printf("input some string: ");
	scanf(" %s", str);

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			tmp[cnt++] = str[i];
		}
		 else if(cnt!=0) {
			tmp[cnt] = '\0';
			printf("%s+", tmp);
			sum += atoi(tmp);
			cnt = 0;
		}
	}
	printf("\b=%ld\n", sum);
	return 0;
}
////sizeof()가 아닌strlen으로 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char str[BUFSIZ], tmp[BUFSIZ];
	long sum = 0, cnt = 0;

	printf("Input some string : ");
	scanf("%s", str);

	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			tmp[cnt++] = str[i];
		}
		else if (cnt != 0) {
			tmp[cnt] = '\0';
			printf("%s+", tmp);
			sum += atoi(tmp);
			cnt = 0;
		}
	}
	printf("\b=%ld\n", sum);

	return 0;
}


#include <stdio.h>
#include <string.h>
void ClearLineFromReadBuffer(void)
{
	while (getchar() != '\n');
}

int main(void)
{
	char str1[20], str2[20], str3[40];

	printf("문자입력1: ");
	fgets(str1, sizeof(str1), stdin);
	ClearLineFromReadBuffer();
	printf("문자입력2: ");
	fgets(str2, sizeof(str2), stdin);
	strncpy(str3, str1, sizeof(str3));
	puts(str3);
	strncpy(str3, str2, sizeof(str3) - 1);
	puts(str3);

	printf("\b%s", str3);
	return 0;
}

//교수님 코드
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[20];
	char str2[20];
	char str3[40];

	fgets(str1, sizeof(str1), stdin);
	str1[strlen(str1) - 1] = '\0';
	fgets(str2, sizeof(str2), stdin);
	str2[strlen(str2) - 1] = '\0';//!!!!!내가 찾던 것

	strncpy(str3, str1, strlen(str1));
	strncat(str3, str2, strlen(str2));

	printf("%s\n", str3);

	return 0;
}

#include <stdio.h>
#include <string.h>

int main(void)
{
	char name1[BUFSIZ], name2[BUFSIZ];
	int age1, age2;

	scanf("%s %d", name1, age1);
	scanf("%s %d", name2, age2);
	printf("%s %d\n", name1, age1);
	printf("%s %d\n", name1, age1);

	if (!strcmp(name1, name2))
	{
		puts("이름은 동일합니다");
	}
	else {
		puts("이름은 동일하지 않습니다");
	}
	return 0;
}
//strcmp를 사용해서 둘을 비교해보자 사용예시는 밑에 있따
//이름과 나이가 같은지 각각 판단하여 출력
if (!strcmp(str1, str2))
{
	puts("두 문자열은 완벽히 동일합니다.");
}
else
{
	puts("두 문자열은 동일하지 않습니다. ");

	if (!strncmp(str1, str2, 3))
	{
		puts("그러나 앞 세 글자는 동일합니다. ");
	}
}