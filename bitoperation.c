/*AND*/
#include <stdio.h>


int main(void)
{
	int num1 = 15; //00000000 00000000 00000000 00001111
	int num2 = 20; //00000000 00000000 00000000 00010100
	int num3 = num1 & num2; //num1 과 num2의 비트단위 & 연산
	printf("AND 연산의 결과: %d \n", num3); 
	return 0;
}

/*OR*/


int main(void)
{
	int num1 = 15; //00000000 00000000 00000000 00001111
	int num2 = 20; //00000000 00000000 00000000 00010100
	int num3 = num1 | num2; //num1 과 num2의 비트단위 & 연산
	printf("OR 연산의 결과 : % d \n", num3);
	return 0;
}

/*XOR*/
int main(void)
{
	int num1 = 15; //00000000 00000000 00000000 00001111
	int num2 = 20; //00000000 00000000 00000000 00010100
	int num3 = num1 ^ num2; //num1 과 num2의 비트단위 & 연산
	printf("XOR 연산의 결과: %d \n", num3);
	return 0;
}

/*NOT*/


int main(void)
{
	int num1 = 15; //00000000 00000000 00000000 00001111
	int num2 = ~num1; 
	printf("NOT 연산의 결과: %d \n", num2);
	return 0;
}

/*shift*/

//비트 왼쪽이나 오른쪽으로 이동 << >>

#include <stdio.h>

int main(void)
{
	int num = 15; ///00000000 00000000 00000000 00001111

	int result1 = num << 1;
	int result2 = num << 2;
	int result3 = num << 3;

	printf("1칸 이동 결과 : %d", result1);
	printf("2칸 이동 결과 : %d", result2);
	printf("3칸 이동 결과 : %d", result3);

	return 0;

}


/*문제 4-4*/
//1번
int main(void)
{
	int num1;
	scanf("%d", &num1);
	int result = ~num1 + 1;
	printf("부호 변경 결과: %d", result);
	return 0;


}
//2번

int main(void)
{	
	int num = 3;
	num << 3;
	num >> 2;

	int result = num;
	printf("%d", result);
	return 0;
}
