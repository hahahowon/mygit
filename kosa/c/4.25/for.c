//index ��� ����Ҷ� ���� ���
/*
�⺻ ����
for(�ʱ�(���� ���� �� �ʱ�ȸ; ����; ����)
{
�ݺ��� ����
}
�ʱ⹮ ����-> ���ǹ� ����(���ǹ��� �����̸� ��������, ���̸� �ݺ��� ���� �ݺ�)-> ���� -> ���� -> ���� ~~~�ݺ� -> ���ǹ� ������ �Ǹ� ��������


for ���� while������ �ۼ������� ����
int i; �ʱ�
while(i<10)����
{
printf("llll")
i++  ����
}

//�ݺ��� Ƚ���� ������ ��� => for��, 
//���α׷� ����ڰ� ������ �� �Է��ϱ⸸ ��ٸ��� ��Ȳ => while or do while

*/

#include <stdio.h>
int main(void)
{
	int total = 0;
	int i, num;
	printf("0����  num������ ����, num��? ");
	scanf_s("%d", &num);

	for (i = 0; i < num + 1 ; i++) {
		total += i;
	}
	printf("0���� %d���� �������: %d \n", num, total);
	return 0;
	}

//for�� ��ø

#include <stdio.h>
int main(void)
{
	int cur, is;

	for (cur = 2; cur < 10; cur++)
	{
		for (is = 1; is < 10; is++) {
			printf("%d X %d = %d \n", cur, is, cur * is);
		}
		printf("\n");
	}
	return 0;
}


//for if ��ø

int main(void)
{
	int num = 0;
	printf("���� �Է�:: ");
	scanf("%d", &num);

	if (num < 0) {
		printf("�Է°��� 0���� �۴�.\n");
	}
	else {
		printf("�Է°��� 0���� ���� �ʴ�.\n");
	}
	return 0;
}
