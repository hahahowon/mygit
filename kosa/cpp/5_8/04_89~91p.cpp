//이름공간의 기본원리
//존재하는 이름 공간이 다르면 동일한 이름의 함수 및 변수를 선언하는 것이 가능하다.
#include <iostream>

namespace BestCOmlmpl //BestCOmlmpl이라는 namespace
{
    void SimpleFunc(void)
    {
        std::cout<<"BestCom이 정의한 함수"<<std::endl;
    }
}   
namespace ProgComlpl//ProgComlpl이라는 namespace
{
    void SimpleFunc(void){
        std::cout<<"ProgCom이 정의한 함수"<<std::endl;
    }
} // namespace RtogComlpl

int main(void)
{
    BestCOmlmpl::SimpleFunc();//정의된 namespace의 SimpleFunc호출
    ProgComlpl::SimpleFunc();//정의된 namespace의 SimpleFunc호출
    return 0;
}

//프로잭트의 진행에 있어서 발생할 수 있는 이름의 충돌을 막을 목적으로 namespace 존재
