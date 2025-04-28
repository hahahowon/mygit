#include <stdio.h>

int main(void)
{
	char str1[10] = "My String";
	char* str2 = "Your String";//메모리가 어딘가에 잡혀있는데 변경이 불가능한 상수형 변수
	printf("%s, %s \n", str1, str2); // My String, Your String결과

	str2 = "Our String";// 가리키는 대상 변경// 초기화
	printf("%s, %s \n", str1, str2); //My String Our String 결과

	str1[0] = 'X';
	str2[0] = 'X';
	printf("%s %s \n", str1, str2);
	return 0;
}


#include <stdio.h>

int main(void)
{
	char str1[10] = "My String";// 변수 형태 문자열
	char* str2 = "Your String";//메모리가 어딘가에 잡혀있는데 변경이 불가능한 상수 형태 문자열
	printf("%s, %s \n", str1, str2); // My String, Your String결과

	str2 = "Our String";// 가리키는 대상 변경// 초기화
	printf("%s, %s \n", str1, str2); //My String Our String 결과
	str2 = str1;//만약 이렇게 하면??? :: 메모리가 상수형에서 변수 형태를 가리키는걸로 변경되었기에 작동한다
	str1[0] = 'X';
	str2[0] = 'X';
	printf("%s %s \n", str1, str2);
	return 0;
} ///Xy String Xy String 결과
