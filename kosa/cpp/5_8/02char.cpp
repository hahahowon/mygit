#include <iostream>

int main(void)
{
    char name[100];
    char lang[200];
    std::cout<<"이름이 무엇";
    std::cin>>name;
    std::cout<<"좋아하는 프로그래밍언어";
    std::cin>>lang;

    std::cout<<"내 이름은 "<<name<<"입니다.\n";
    std::cout<<"좋아하는 언어는"<<lang<<"입니다"<<std::endl;
    return 0;
}

scanf("%123[^\n]s", str);//이렇게 쓰면 123자까지 공백포함으로 받을 수 있다.
