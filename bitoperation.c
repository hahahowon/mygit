/*AND*/
#include <stdio.h>


int main(void)
{
	int num1 = 15; //00000000 00000000 00000000 00001111
	int num2 = 20; //00000000 00000000 00000000 00010100
	int num3 = num1 & num2; //num1 �� num2�� ��Ʈ���� & ����
	printf("AND ������ ���: %d \n", num3); 
	return 0;
}

/*OR*/


int main(void)
{
	int num1 = 15; //00000000 00000000 00000000 00001111
	int num2 = 20; //00000000 00000000 00000000 00010100
	int num3 = num1 | num2; //num1 �� num2�� ��Ʈ���� & ����
	printf("OR ������ ��� : % d \n", num3);
	return 0;
}

/*XOR*/
int main(void)
{
	int num1 = 15; //00000000 00000000 00000000 00001111
	int num2 = 20; //00000000 00000000 00000000 00010100
	int num3 = num1 ^ num2; //num1 �� num2�� ��Ʈ���� & ����
	printf("XOR ������ ���: %d \n", num3);
	return 0;
}

/*NOT*/


int main(void)
{
	int num1 = 15; //00000000 00000000 00000000 00001111
	int num2 = ~num1; 
	printf("NOT ������ ���: %d \n", num2);
	return 0;
}

/*shift*/

//��Ʈ �����̳� ���������� �̵� << >>

#include <stdio.h>

int main(void)
{
	int num = 15; ///00000000 00000000 00000000 00001111

	int result1 = num << 1;
	int result2 = num << 2;
	int result3 = num << 3;

	printf("1ĭ �̵� ��� : %d", result1);
	printf("2ĭ �̵� ��� : %d", result2);
	printf("3ĭ �̵� ��� : %d", result3);

	return 0;

}


/*���� 4-4*/
//1��
int main(void)
{
	int num1;
	scanf("%d", &num1);
	int result = ~num1 + 1;
	printf("��ȣ ���� ���: %d", result);
	return 0;


}
//2��

int main(void)
{	
	int num = 3;
	num << 3;
	num >> 2;

	int result = num;
	printf("%d", result);
	return 0;
}
