/*����ü �迭 ���� �׸��� ������*/

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
		printf("��ǥ: ");
		scanf("%d %d ", &arr[i].xpos, &arr[i].ypos);//&�����Ϳ� ������ reference�� �ʱ�ȭ�� ���� &�־��
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
*///scanf ������ ������ �迭�� �� ���ڵ� �ʱ�ȭ�� strncpy���

int main(void)
{
	struct person arr[3] = {//arr[3] ����� ����
		{"�̽±�", "010-1000-0000", 23},
		{"�̽±�", "010-1000-0000", 23},
		{"�̽°�", "010-1000-0000", 23}
	};//����ü�� ; �ٿ��ְ�~
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
	{"�̽±�", "010-1000-0000", 23},
	{"�̽±�", "010-1000-0000", 23},
	{"�̽°�", "010-1000-0000", 23}
	};

	int i;
	for (i = 0;i < 3;i++) {

		printf("�̸� �Է�: "); scanf("%s", arr[i].name);
		printf("��ȣ �Է�: "); scanf("%s", arr[i].phoneNum);
		printf("���� �Է�: "); scanf("%d", &arr[i].age);
	}

	for (i = 0;i < 3;i++) {
		printf("%s %s %d", arr[i].name, arr[i].phoneNum, arr[i].age);
	}
	return 0;
}
