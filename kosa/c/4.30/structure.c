/*
�ϳ� �̻��� �⺻ �ڷ����� ������� ����� ���� �ڷ��� ����� �������

strcut point
{
	int x;
	int y;
};   //��ȣ �ڿ� ; �־������

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
	
	/*�� ������ �Ÿ� ��� ����*/

	distance = sqrt((double)((pos1.xpos - pos2.xpos) * (double)(pos1.xpos - pos2.xpos) +
		(pos1.ypos - pos2.ypos) * (double)(pos1.ypos - pos2.ypos)));

	printf("�� ���� �Ÿ��� %g\n", distance);
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
	struct person man1, man2;// ����ü ���� ����
	strcpy(man1.name, "�ȼ���");
	strcpy(man1.phoneNum, "010-1122-3344");
	man1.age = 23;
	//�ʱ�ȭ ���� strcpy�� strncpy�� �����

	printf("�̸� �Է�: "); scanf("%s", man2.name);
	printf("��ȣ �Է�: "); scanf("%s", man2.phoneNum);
	printf("���� �Է�: "); scanf("%d", &(man2.age));

	printf("�̸�: %s \n", man1.name);
	printf("��ȣ: %s \n", man1.phoneNum);
	printf("����: %d \n", man1.age);


	printf("�̸�: %s \n", man2.name);
	printf("��ȣ: %s \n", man2.phoneNum);
	printf("����: %d \n", man2.age);
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

	printf("�̸� �Է�:"); scanf("%s", ch2.name);
	printf("w�ֹι�ȣ �Է�:"); scanf("%s", ch2.num);
	printf("�޿�����:"); scanf("%d", &(ch2.info));


	printf("�̸�:%s\n", ch2.name);
	printf("��ȭ��ȣ:%s\n", ch2.num);
	printf("�޿�����+:%d\n", ch2.info);
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
	struct person man = { "�̽±�", "010-5151-1515", 23 };
	printf("%d %d\n", pos.xpos, pos.ypos);
	printf("%s %s %d\n", man.name, man.phoneNum, man.age);
	return 0;

}