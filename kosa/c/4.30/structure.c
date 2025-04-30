/*
하나 이상의 기본 자료형을 기반으로 사용자 정의 자료형 만드는 문법요소

strcut point
{
	int x;
	int y;
};   //괄호 뒤에 ; 넣어줘야함

*/

//454p
#include <stdio.h>
#include <math.h>

struct point
{
	int xpos;
	int ypos;
};

int main(void)
{
	struct point pos1, pos2;
	double distance;
	fputs("point1 pos: ", stdout);
	scanf("%d %d", &pos1.xpos, &pos1.ypos);
	
	fputs("point2 pos: ", stdout);
	scanf("%d %d", &pos2.xpos, &pos2.ypos);
	
	/*두 점간의 거리 계산 공식*/

	distance = sqrt((double)((pos1.xpos - pos2.xpos) * (double)(pos1.xpos - pos2.xpos) +
		(pos1.ypos - pos2.ypos) * (double)(pos1.ypos - pos2.ypos)));

	printf("두 점의 거리는 %g\n", distance);
	return 0;
}

//456p

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
	struct person man1, man2;// 구조체 변수 선언
	strcpy(man1.name, "안성준");
	strcpy(man1.phoneNum, "010-1122-3344");
	man1.age = 23;
	//초기화 값을 strcpy나 strncpy로 해줘라

	printf("이름 입력: "); scanf("%s", man2.name);
	printf("번호 입력: "); scanf("%s", man2.phoneNum);
	printf("나이 입력: "); scanf("%d", &(man2.age));

	printf("이름: %s \n", man1.name);
	printf("번호: %s \n", man1.phoneNum);
	printf("나이: %d \n", man1.age);


	printf("이름: %s \n", man2.name);
	printf("번호: %s \n", man2.phoneNum);
	printf("나이: %d \n", man2.age);
	return 0;

}




#include <stdio.h>
#include <string.h>

struct employee
{
	char name[20];
	char num[20];
	int info;
};

int main(void)
{
	struct employee ch1, ch2;
	strcpy(ch1.name, "amu");
	strcpy(ch1.num, "010-5167-3667");
	ch1.info = 23333;

	printf("이름 입력:"); scanf("%s", ch2.name);
	printf("w주민번호 입력:"); scanf("%s", ch2.num);
	printf("급여정보:"); scanf("%d", &(ch2.info));


	printf("이름:%s\n", ch2.name);
	printf("전화번호:%s\n", ch2.num);
	printf("급여정보+:%d\n", ch2.info);
	return 0;
};


#include <stdio.h>
#include <string.h>
struct point
{
	int xpos;
	int ypos;
};

struct person
{
	char name[20];
	char phoneNum[20];
	int age;
};

int main(void)
{
	struct point pos = { 10, 20 };
	struct person man = { "이승기", "010-5151-1515", 23 };
	printf("%d %d\n", pos.xpos, pos.ypos);
	printf("%s %s %d\n", man.name, man.phoneNum, man.age);
	return 0;

}