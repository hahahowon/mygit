#include <stdio.h>

//구조체 선언
typedef struct person
{
    char name[20];
    char phoneNum[20];
    int age;
}Person;
//출력함수선언 인자 O 반환값 x
void ShowPersonInfo(Person man)
{
    printf("name: %s \nphoneNum: %s \nAge: %d\n", man.name,man.phoneNum, man.age);
}
//입력함수 전달인자 x 반환값 o
Person ReadPersonInfo(void)//이 함수 구조 분석해보자
{
    Person man;
    printf("name? "); scanf("%s", man.name);
    printf("phone numder? "); scanf("%s", man.phoneNum);
    printf("name? "); scanf("%d", &man.age);
    return man;
}


int main(void)
{
    Person man= ReadPersonInfo();
    ShowPersonInfo(man);
    return 0;
    
}