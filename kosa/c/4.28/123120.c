//ȸ��, �������о �ڷ� �о ���� �ܾ��
// ���ڿ��� �Է¹ް� for ���� ����ؼ� ������, �Ųٷ� ������, ���� ������ Ȯ���ϱ�
//���ٸ� ȸ�� �Դϴ� ���


#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[BUFSIZ];
	printf("�Է��ϼ���: ");
	scanf("%d", str);

	int len = strlen(str);


	return 0;
}


//string ��������� ������� �ʰ� ���̸� ���� ���� ���
int main(void)
{	
	int len = 0;
	char str[BUFSIZ];
	printf("�Է��ϼ���: ");
	scanf("%d", str);
	
	while (1) {
		if (str[len++] == '\0') {
			break;
		}
	}
	len--;
	printf("length : %d\n", len);//while���� ������� ���ڿ� ���� 

	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]) {
			printf("ȸ���� ���Դϴ� \n");
			break;
		}


	return 0;
}

//���� ���� 5��
