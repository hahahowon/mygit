#include <stdio.h>

int main(void)
{
	char str1[10] = "My String";
	char* str2 = "Your String";//�޸𸮰� ��򰡿� �����ִµ� ������ �Ұ����� ����� ����
	printf("%s, %s \n", str1, str2); // My String, Your String���

	str2 = "Our String";// ����Ű�� ��� ����// �ʱ�ȭ
	printf("%s, %s \n", str1, str2); //My String Our String ���

	str1[0] = 'X';
	str2[0] = 'X';
	printf("%s %s \n", str1, str2);
	return 0;
}


#include <stdio.h>

int main(void)
{
	char str1[10] = "My String";// ���� ���� ���ڿ�
	char* str2 = "Your String";//�޸𸮰� ��򰡿� �����ִµ� ������ �Ұ����� ��� ���� ���ڿ�
	printf("%s, %s \n", str1, str2); // My String, Your String���

	str2 = "Our String";// ����Ű�� ��� ����// �ʱ�ȭ
	printf("%s, %s \n", str1, str2); //My String Our String ���
	str2 = str1;//���� �̷��� �ϸ�??? :: �޸𸮰� ��������� ���� ���¸� ����Ű�°ɷ� ����Ǿ��⿡ �۵��Ѵ�
	str1[0] = 'X';
	str2[0] = 'X';
	printf("%s %s \n", str1, str2);
	return 0;
} ///Xy String Xy String ���
