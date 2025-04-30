/*구조체 배열 접근 그리고 포인터*/

#include <stdio.h>
#include <string.h>
struct point
{
	int xpos;
	int ypos;
};

int main(void)
{
	struct point arr[3];
	int i;
	
	for (i = 0; i < 3; i++) {
		printf("좌표: ");
		scanf("%d %d ", &arr[i].xpos, &arr[i].ypos);//&포인터에 지정된 reference값 초기화를 위해 &넣어라
	}

	for (i = 0;i < 3;i++) {
		printf("[%d %d]", arr[i].xpos, arr[i].ypos);
	}
	return 0;

}


#include <stdio.h>
#include <string.h>
struct person
{
	char name[20];
	char phoneNum[20];
	int age;
};
/*
int main(void)
{
	struct person;
	int i

	return 0;
}
*///scanf 쓰려고 했지만 배열에 들어갈 문자들 초기화는 strncpy사용

int main(void)
{
	struct person arr[3] = {//arr[3] 까먹지 말고
		{"이승기", "010-1000-0000", 23},
		{"이승구", "010-1000-0000", 23},
		{"이승고", "010-1000-0000", 23}
	};//구조체니 ; 붙여주고~
	int i;
	for (i = 0;i < 3;i++) {
		printf("%s %s %d", arr[i].name, arr[i].phoneNum	, arr[i].age);
	}
	return 0;
}

//463p 22-2

#include <stdio.h>
#include <string.h>
struct person
{
	char name[20];
	char phoneNum[20];
	int age;
};


int main(void)
{
	struct person a, b, arr[3];
	strcpy(a.name, "amu");
	strcpy(a.phoneNum, "010-5167-3667");
	a.age = 23333;

	struct person arr[3] = {
	{"이승기", "010-1000-0000", 23},
	{"이승구", "010-1000-0000", 23},
	{"이승고", "010-1000-0000", 23}
	};

	int i;
	for (i = 0;i < 3;i++) {

		printf("이름 입력: "); scanf("%s", arr[i].name);
		printf("번호 입력: "); scanf("%s", arr[i].phoneNum);
		printf("나이 입력: "); scanf("%d", &arr[i].age);
	}

	for (i = 0;i < 3;i++) {
		printf("%s %s %d", arr[i].name, arr[i].phoneNum, arr[i].age);
	}
	return 0;
}
