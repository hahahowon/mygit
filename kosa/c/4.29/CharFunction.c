#include <stdio.h>
int main(void)
{
	int ch1, ch2;
	
	ch1 = getchar();//�����Է�
	ch2 = fgetc(stdin);//���� Ű �Է�

	putchar(ch1); // ���� ���
	fputc(ch2, stdout); //���� Ű ���
	return 0;

}

#include <stdio.h>
int main(void)
{
	int ch;

	while (1)//���ѹݺ�����
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
	//�ƽ�Ű �ڵ带 Ȱ�� �ҹ��ڿ� �빮���� �� ���̴� 32

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
	printf("5���� ���� �Է��Ͻÿ�. ");

	while
		return 0;
}



#include <stdio.h>
int main(void)
{
	int arr[5];
	printf("5���� ���� �Է��Ͻÿ�. ");

	for (int j = 0; j < 5;j++) {
		scanf("%d", &arr[j]);
	}
	for (int i = 0; i < 5; i++) {
		printf("%d", arr[i]);
	}
	return 0;

}