#include <iostream>
using namespace std;

class Chulsoo{
    public:
        void Eat(int SteakWeight);
        inline void EatInlinke(int SteakWeight);//인라인 함수 선언
};


int main(void)
{   
    Chulsoo chulsoo;
    chulsoo Eat(500);
    chulsoo EatInline(500);//인라인함수 호출
    return 0;
}

void Chulsoo::Eat(int SteakWeight)
{
    cout<<"Eat()::철수는"<<SteakWeight<<"g짜리 스테이크를 먹는다"<<endl;
}

inline void Chulsoo::EatInlinke(int Steakweight)//인라인 함수 정의
{
    cout<<"EatInline()::철수는"<<Steakweight <<"g짜리 스테이크를 먹는다"<<endl;
}



//간단한 람다식


#include <iostream>
using namespace std;

int main(void)
{
    [](int x, int y){cout<<"합은"<<x+y;}(2, 3); //5 출력
}



#include <iostream>
using namespace std;

class Chulsoo{
    public:
        int count;//철수가 스테이크를 먹는 횟수
};


int main(void)
{
    Chulsoo chulsoo;
    chulsoo.count=1;
    for(int i=0; i< 10; i++)
    {
        [=](int steakWeight)mutable{cout<<"eatLambda()::철수는"<<chulsoo.count++<<"번째"<<steakWeight<<"g짜리 스테이크를 먹는다"<<endl;}(1000);
    }
    cout<<chulsoo.count;
    return 0;
}



#include <iostream>
using namespace std;

class Chulsoo{
    public:
        int count;//철수가 스테이크를 먹는 횟수
};


int main(void)
{
    Chulsoo chulsoo;
    chulsoo.count=1;
    for(int i=0; i< 10; i++)
    {
        [&](int steakWeight){cout<<"eatLambda()::철수는"<<chulsoo.count++<<"번째"<<steakWeight<<"g짜리 스테이크를 먹는다"<<endl;}(1000);
    }
    cout<<chulsoo.count;
    return 0;
}
//mutable은 call by value에서 값을 변경할때 앞에 써준다.


#include <iostream>
using namespace std;

class Chulsoo{
    public:
        int count;//철수가 스테이크를 먹는 횟수
};


int main(void)
{
    Chulsoo chulsoo;
    chulsoo.count=1;
    //반환형을 char로 지정한 람다함수
    cout<<[=](int steakWeight)mutable->char{cout<<"eatLambda()::철수는"<<chulsoo.count++<<"번째"<<steakWeight<<"g짜리 스테이크를 먹는다"<<endl; return steakWeight;}(67)<<endl;
 //반환형을 int로 지정한 람다함수
    cout<<[=](int steakWeight)mutable->int{cout<<"eatLambda()::철수는"<<chulsoo.count++<<"번째"<<steakWeight<<"g짜리 스테이크를 먹는다"<<endl; return steakWeight;}(67)<<endl;
 //반환형을 지정하지 않았찌만 steakWeight를 반환하므로 int
    cout<<[=](int steakWeight)mutable{cout<<"eatLambda()::철수는"<<chulsoo.count++<<"번째"<<steakWeight<<"g짜리 스테이크를 먹는다"<<endl; return steakWeight;}(67)<<endl;

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    auto love=[](string a, string b){
            cout<<a<<"보다"<<b<<"가 좋아"<<endl;
    };
    love("돈","너");
    love("냉면","만두");
    return 0;
}