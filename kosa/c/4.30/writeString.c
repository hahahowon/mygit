
#include <stdio.h>


int main(void)
{
	char* str = "Simple String";

	printf("1. puts test ------ \n");
	puts(str); //puts �Լ��� ��´���� stdout���� �����Ǿ��ִ�
	puts("So Simple String");

	printf("2. fputs test -----\n");
	fputs(str, stdout); printf("\n");//fputs �Լ��� �� ��° ���ڸ� ���ؼ� ����� ����� ���� ����
	fputs("So Simple string", stdout); printf("\n");

	printf("3. end of main-----\n");
	return 0;
}
//���������� ù ��° ���ڷ� ���޵Ǵ� �ּ� ���� ���ڿ��� ����Ѵ�
//����� ���¿� �־� �������� ���� å 424p
//stdout ���

//stdin���κ��� ���ڿ��� �Է� �޾Ƽ� �迭 str�� �����ϵ� sizeof(str)�� ���̸�ŭ�� �����ض�.
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


//gets �Լ��� ������ ũ�⸦ �����ؼ� �Է¹޴� ũ�⸦ ������ �� �ִ�.
// ���� �̽��� gets_s�� vs������ �����

//����(buffer)
//����»��̿� �����ϴ� ������ ����
//������ �ӽ� �޸��� Ư¡
//�������
// �ѹ��� ��Ƽ� ������ �ѹ��� ��Ƽ�  �����ϰ� �����
#include <stdio.h>

int main(void)
{
	char perID[7];
	char name[10];

	fputs("�ֹι�ȣ �� 6�ڸ� �Է�:", stdout);
	fgets(perID, sizeof(perID), stdin); //������ �����ͷ� ����Ǿ������� sizeof �Ұ��� �迭�� ũ��� ����
	
	fflush(stdin); //�Է¹��� �����.

	fputs("�̸� �Է�: ", stdout);
	fgets(name, sizeof(name), stdin);

	printf("�ֹι�ȣ :%s \n", perID);
	printf("�ֹι�ȣ :%s \n", name);

	return 0;
}

/*
�ֹι�ȣ �� 6�ڸ� �Է� : 1234567
�̸� �Է� : �ֹι�ȣ:123456
�ֹι�ȣ : 7

����: �̸��� �Է��� ��ȸ�� ���� ���ߴ�.
ù ��° ����¿��� �Է¹��� ���ڴ� null ���� ���� �ִ� 6���� �Է°���:[7]�� �ε����� �����߱� ����
������ �Էµ� ���� 1,2,3,4,5,6,7,�̴� 6������ �׷��� 6���� ��µǰ� �Է¹��ۿ� 7�� null�� �����ִ�
�� ��° fgets�� �Է¹޾ƾ� ������ fgets �� \n�� ������ ���� �о���̴� �Լ��� �Է����� ���ϰ� �ٷ�
����Ʈ�� �Ѿ���� �׷��� �Է¹��ۿ� �����ִ� 7�� ��µ�
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

	fputs("�ֹι�ȣ �� 6�ڸ� �Է�:", stdout);
	fgets(perID, sizeof(perID), stdin); //������ �����ͷ� ����Ǿ������� sizeof �Ұ��� �迭�� ũ��� ����
	ClearLineFromReadBuffer();

	fputs("�̸� �Է�: ", stdout);
	fgets(name, sizeof(name), stdin);

	printf("�ֹι�ȣ :%s \n", perID);
	printf("�ֹι�ȣ :%s \n", name);

	return 0;
}

//7�ڸ� ���� ���� 7 ������鼭 ���
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
	printf("���ڿ� �Է�: ");
	fgets(str, sizeof(str), stdin);
	printf("���� : %d, ���� : %s", strlen(str), str);

	RemoveBSN(str);
	printf("���� : %d, ���� : %s", strlen(str), str);
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
}// �̰� ���� �����̽��� _s �ٿ��־�� ��
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
	strncat(str3, str4, 7); //str3 �ڿ�, str4 �����̵�, ���� 7����
	puts(str3); //

	return 0;


}// �̰� ���� �����̽��� _s �ٿ��־�� ��// �����÷ο찡 �߻��Ҹ��� �͵��� _s ���̱�

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[20] = "First~";
	char str2[20] = "Second";
	printf("���ڿ� �Է� 1: ");
	scanf("%s", str1);
	printf("���ڿ� �Է� 2: ");
	scanf("%s", str2);

	if (!strcmp(str1, str2))
	{
		puts("�� ���ڿ��� �Ϻ��� �����մϴ�.");
	}
	else
	{
		puts("�� ���ڿ��� �������� �ʽ��ϴ�. ");
		
		if (!strncmp(str1, str2, 3))
		{
			puts("�׷��� �� �� ���ڴ� �����մϴ�. ");
		}
	}

	return 0;
}


///���ڿ��� ���ڷ� ��ȯ
#include<stdlib.h>
int atoi(char* ptr);	// ���ڿ��� int�� �����ͷ� ��ȯ
long atol(char* ptr);	// ���ڿ��� long�� �����ͷ� ��ȯ
double atof(char* str); // ���ڿ��� double�� �����ͷ� ��ȯ

//�� �ҹ����� ��ȯ�� ó���ϴ� �Լ�
#include <ctypes.h>
int toupper(int c); //�ҹ��ڸ� �빮�ڷ�
int tolower(int c); //�빮�ڸ� �ҹ��ڷ�


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
////sizeof()�� �ƴ�strlen���� 


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

	printf("�����Է�1: ");
	fgets(str1, sizeof(str1), stdin);
	ClearLineFromReadBuffer();
	printf("�����Է�2: ");
	fgets(str2, sizeof(str2), stdin);
	strncpy(str3, str1, sizeof(str3));
	puts(str3);
	strncpy(str3, str2, sizeof(str3) - 1);
	puts(str3);

	printf("\b%s", str3);
	return 0;
}

//������ �ڵ�
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
	str2[strlen(str2) - 1] = '\0';//!!!!!���� ã�� ��

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
		puts("�̸��� �����մϴ�");
	}
	else {
		puts("�̸��� �������� �ʽ��ϴ�");
	}
	return 0;
}
//strcmp�� ����ؼ� ���� ���غ��� ��뿹�ô� �ؿ� �ֵ�
//�̸��� ���̰� ������ ���� �Ǵ��Ͽ� ���
if (!strcmp(str1, str2))
{
	puts("�� ���ڿ��� �Ϻ��� �����մϴ�.");
}
else
{
	puts("�� ���ڿ��� �������� �ʽ��ϴ�. ");

	if (!strncmp(str1, str2, 3))
	{
		puts("�׷��� �� �� ���ڴ� �����մϴ�. ");
	}
}