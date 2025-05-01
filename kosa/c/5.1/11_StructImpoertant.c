#include <stdio.h>

typedef struct student
{
    char name[20];
    char stdnum[20];
    char school[20];
    char major[20];
    int year;
}Student;


void ShowStudentInfo(Student *sptr)
{
    printf("학생 이름: %s \n", sptr->name); //sptr 포인터는 name을 가리킨다 -> **기억하기
    printf("학생 고유번호: %s \n", sptr->stdnum);
    printf("학교 이름: %s \n", sptr->school);
    printf("학생 전공: %s \n", sptr->major);
    printf("학생 나이: %d \n", sptr->year);
}

int main(void)
{
    Student arr[7];
    int i;

    for(i=0;i<7; i++)
    {
        printf("이름: "); scanf("%s", arr[i].name);
        printf("번호: "); scanf("%s", arr[i].stdnum);
        printf("학교: "); scanf("%s", arr[i].school);
        printf("전공: "); scanf("%s", arr[i].major);
        printf("나이: "); scanf("%d", &arr[i].year);
    }

    for(i=0; i<7; i++){
        ShowStudentInfo(&arr[i]);
    }
    return 0;
}