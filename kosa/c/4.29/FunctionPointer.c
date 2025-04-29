#include <stdio.h>

int main(void)
{
	printf("main : %p\n", main);
	printf("printf : %p\n", printf);
	printf("scanf : %p\n", scanf);

	return 0;
}////함수의 주소

#include <stdio.h>

void SimpleAdder(int n1, int n2)
{
	printf("%d + %d = %d", n1, n2, n1 + n2);
}
void ShowString(char* str)
{
	printf("%s \n", str);
}

int main(void)
{
	char* str = "Function Pointer";
	int num1 = 10, num2 = 20;

	void (*fptr1)(int, int) = SimpleAdder;
	void (*fptr2)(char*) = SimpleAdder;
	
	/*함수 포인터 변수에 의한 호출*/
	fptr1(num1, num2);
	fptr2(str);
	return 0;
}

//매개변수 선언으로 함수 포인터 변수가 올 수 있음을 보이고 전달되는 인자에 따라 달리 동작하는 함수 정의

#include <stdio.h>
int WhoIsFirst(int age1, int age2, int (*cmp)(int n1, int n2))
{
	return cmp(age1, age2);
}

int OlderFirst(int age1, int age2)
{
	if(age1 > age2) {
		return age1;
	}
	else if(age1<age2){
		return age2;
	}
	else
		return 0;

	//ifreturn = (age1>age2) ? age1:age2)
}


int Youngerfirst(int age1, int age2)
{
	if (age1 < age2) {
		return age1;
	}
	else if (age1 > age2) {
		return age2;
	}
	else
		return 0;
}

int main(void)
{
	int age1 = 20;
	int age2 = 30;
	int first;

	printf("입장순서 1 \n");
	first = WhoIsFirst(age1, age2, OlderFirst);
	printf("%d세와 %d세 중 %d세가 먼저 입장 \n\n", age1, age2, first);


	printf("입장순서 2 \n");
	first = WhoIsFirst(age1, age2, Youngerfirst);
	printf("%d세와 %d세 중 %d세가 먼저 입장 \n\n", age1, age2, first);
	return 0;
}


#include <stdio.h>

float add(int n1, int n2);
float minus(int n1, int n2);
float mul(int n1, int n2);
float div(int n1, int n2);

int main(void)
{
	int n1, n2;
	int op;
	float result;

	printf("계산기입니다. 원하시는 모드를 선택해주세요.\n1. 덧셈, 2. 뺄셈, 3. 곱셈, 4. 나눗셈");
	scanf("%s", &op);

	switch (op)
	{

	case1:
		printf("두 수를 입력해주세요:");
		scanf("%lf %lf", &n1, &n2);
		result = add(n1, n2);
		printf("%lf", result);

	}
	{
	case2:
		printf("두 수를 입력해주세요:");
		scanf("%lf %lf", &n1, &n2);
		result = minus(n1, n2);

	}
	{
	case3:
		printf("두 수를 입력해주세요:");
		scanf("%lf %lf", &n1, &n2);
		result = mul(n1, n2);
	}
	{
	case4:
		printf("두 수를 입력해주세요:");
		scanf("%lf %lf", &n1, &n2);
		result = div(n1, n2);
	}

	return 0;
}

float add(int n1, int n2)
{
	printf("%lf + %lf = %lf", n1, n2, n1 + n2);
}
float minus(int n1, int n2)
{
	printf("%lf - %lf = %lf", n1, n2, n1 - n2);
}
float mul(int n1, int n2)
{
	printf("%lf * %lf = %lf", n1, n2, n1 * n2);
}
float div(int n1, int n2)
{
	printf("%lf / %lf = %lf", n1, n2, n1 / n2);
}



//이거 동작 안되는 이유 찾고 고치기

////교수님 코드

#include <stdio.h>

float add(int n1, int n2);
float minus(int n1, int n2);
float mul(int n1, int n2);
float div(int n1, int n2);

int main(void)
{
	int n1, n2;
	char op;
	float result;

	printf("input num1 op num2 : ");
	scanf("%d %c %d", &n1, &op, &n2);

	switch (op) {
	case '+': result = add(n1, n2); break;
	case '-': result = minus(n1, n2); break;
	case '*': result = mul(n1, n2); break;
	case '/': result = div(n1, n2); break;
	}
	printf("%d %c %d = %f\n", n1, op, n2, result);
	return 0;
}

float add(int n1, int n2)
{
	return n1 + n2;
}

float minus(int n1, int n2)
{
	return n1 - n2;
}

float mul(int n1, int n2)
{
	return n1 * n2;
}

float div(int n1, int n2)
{
	return n1 / (float)n2;
}




//함수포인터로 변환

#include <stdio.h>
float funcPtr(int n1, int n2, float(*fptr)(int p1, int p2));
float add(int n1, int n2);
float minus(int n1, int n2);
float mul(int n1, int n2);
float div(int n1, int n2);

int main(void)
{

	int n1, n2;
	char op;
	float result;
	printf("input num1 op num2 : ");
	scanf("%d %c %d", &n1, &op, &n2);

	switch (op) {
	case '+': result = funcPtr(n1, n2, add); break;
	case '-': result = funcPtr(n1, n2, minus); break;
	case '*': result = funcPtr(n1, n2, mul); break;
	case '/': result = funcPtr(n1, n2, div); break;
	}

	printf("%d %c %d = %f\n", n1, op, n2, result);
	return 0;
}

float add(int n1, int n2)
{
	return n1 + n2;
}

float minus(int n1, int n2)
{
	return n1 - n2;
}

float mul(int n1, int n2)
{
	return n1 * n2;
}

float div(int n1, int n2)
{
	return n1 / (float)n2;
}

float funcPtr(int n1, int n2, float(*fptr)(int p1, int p2))
{
	return fptr(n1, n2);
}


//도전 프로그래밍::::
{
	{ 1, 2, 3, 4 },
	{ 5, 6, 7, 8 },
	{ 9, 10, 11, 12 },
	{ 13, 14, 15, 16 }
};

int main(void)
{	
	int arr[4][4];

	//포인터 값을 사용
	for (int i = 0; i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			printf("%2d", arr[i][j]);
		}
	}
	
	//배열선언
	//회전을 해야한다.
	//포인터를 사용하면 쉽게 옮길 수 있음 배열을 그럼 배열에 규칙성이 있는지 확인


	return 0;
}