#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> m;
    m.insert(make_pair("A", 10));
    m.insert(make_pair("B", 20));
    m.insert(make_pair("C", 30));
    m.insert(make_pair("D", 40));
    m.insert(make_pair("E", 50));
    m["F"]=100;//m.insert 대신 이렇게 넣어도 가능
    for(auto i= m.begin(); i != m.end(); i++)
         cout<<"["<<i->first<<" "<<i->second<<"]";
    cout<<endl;
    auto i=m.find("A");
    cout<<i->first<<":"<<i->second<<endl;
    m.insert(make_pair("E", 150));//m["E"]=150 이렇게 값을 바꾸는건 가능하나 m.insert로 추가는 불가능


    return 0;
}