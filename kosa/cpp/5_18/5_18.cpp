#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    for(int i=0;i<q.size();++i)//q.size 변수로 만들어 놓고 넣는게 좋다 호출될때 마다 함수를 불러오기 때문에 시간복잡도가 늘어난다.
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}



#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    priority_queue<int, deque<int>, greater<int>> pq3;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(40);
    pq.push(10);
    pq.push(20);

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.push(pq.top());
        pq.pop();
    }

    cout<<endl;
    while(!pq2.empty()){
        cout<<pq2.top()<<" ";
        pq3.push(pq2.top());
        pq2.pop();
    }

    cout<<endl;
    while(!pq3.empty()){
        cout<<pq3.top()<<" ";
        pq3.pop();
    }
    cout<<endl;

    return 0;
}


#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}


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


#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    multimap<string, int> mm;
    mm.insert(make_pair("A", 10));
    mm.insert(make_pair("B", 20));
    mm.insert(make_pair("C", 30));
    mm.insert(make_pair("D", 40));
    mm.insert(make_pair("E", 50));
    mm.insert(make_pair("C", 100));
    mm.insert(make_pair("C", 200));

    for(auto i=mm.begin(); i !=mm.end(); ++i){
        cout<<"["<<i->first<<" "<<i->second<<"]";
    }
    cout <<endl;

    auto lo_bo = mm.lower_bound("C");
    auto up_bo = mm.upper_bound("C");

    cout<<"value of key C: ";
    for(auto i=lo_bo; i !=up_bo; ++i){
        cout<<i->second<<" ";
    }
    cout<<endl;

    auto eq_ra =mm.equal_range("C");
    cout<<"또 다른 방법)value of key: ";
    for(auto i= eq_ra.first; i !=eq_ra.second; ++i){
        cout<<i->second<<" ";
    }
    cout<<endl;

    return 0;
}


#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    pair<set<int>::iterator, bool> pr;
    s.insert(10);
    s.insert(30);
    s.insert(60);
    s.insert(20);
    s.insert(50);
    pr=s.insert(40);

    for(auto i=s.begin(); i != s.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    s.insert(pr.first, 55);
    for(auto i=s.begin(); i !=s.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    auto f=s.find(55);
    if(f != s.end()){
        cout<<*f<<endl;
    }
    return 0;
}


#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> ms;

    multiset<int>::iterator ms_iter;
    ms.insert(10);
    ms.insert(30);
    ms.insert(60);
    ms.insert(20);
    ms.insert(50);
    ms_iter = ms.insert(40);

    for(auto i=ms.begin(); i != ms.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    cout<<"40의 개수: "<<ms.count(40)<<endl;
    auto f=ms.find(40);
    if(f != ms.end()){
        cout<<*f<<endl;
    }
    return 0;
}




#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> um;
    um.insert({"A", 100});
    um.insert(make_pair("A", 100));
    um.insert({
        {"C", 1000},
        {"D", 2000}
    });

    for(auto i=um.begin(); i != um.end(); ++i){
        cout<<"["<<i->first<<" "<<i->second<<"]";
    }
    cout<<endl;

    cout<<"find value of B: "<<endl;
    auto bc=um.bucket("B");
    for(auto i=um.begin(bc); i != um.end(bc); ++i){
        cout<<i->first<<":"<<i->second;
    }
    cout<<endl;
    return 0;
}


#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main()
{
    unordered_multiset<string> cities{
        "Braunschweig", "Hanover", "Frankfurt", "New York",
        "Chicago", "Toronto", "Paris", "Frankfurt"
    };

    for(const auto& elem : cities)
        cout<<elem<<" ";
    cout<<endl;
    cities.insert({"London", "Munich", "Hanover", "Braunschweig"});

    for(const auto& elem : cities)
        cout<<elem<<" ";
    cout<<endl;

}



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int arr[10]={97, 44, 23, 55, 61, 12, 3, 75, 27, 84};
    cout<<"정렬된 배열";
    sort(arr, arr+10);
    for(int i=0;i<10; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

    vector<string> strings;
    string s;
    cout<<"문자열을 입력하세요: ";
    while(cin >>s)
        strings.push_back(s);

    sort(strings.begin(), strings.end());
    cout<<"정렬된 문자열:";
    for(vector<string>::iterator it = strings.begin(); it != strings.end(); it++)
        cout<<*it<<" ";
    cout<<"\n";

}



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int arr[5] ={0, 1, 2, 3, 4};
    for(int i: arr){
        cout<<i<<endl;
    }
    vector<int>::const_iterator it;
    for(it = v.begin(); it != v.end(); ++it){
        cout<<*it<<endl;
    }    
}


#include <iostream>

using namespace std;

int main()
{
    int a=0, b=0;
    int result =0;

    cout<<"a/b를 수행, a,b입력: "<<endl;
    cout<<"a:";
    cin>>a;
    cout<<"b:";
    cin>>b;

    result=a/b;
    cout<<"a/b의 결과는"<<result<<"입니다"<<endl;

    return 0;

}



#include <iostream>

using namespace std;

int main(void)
{
    int a, b;
    int result;

    cout<<"a/b, input a,b: "<<endl;
    cout<<"a:";
    cin>>a;
    cout<<"b:";
    cin>>b;
    if(b == 0){
        cout<<"error"<<endl;
    }else{

    result= a/b;
    cout<<"a/b result: "<<result<<endl;
    }
    return 0;

}



#include <iostream>

using namespace std;

int main(void)
{
    int num1, num2;
    cout<<"두 개의 숫자 입력:";
    cin>>num1>>num2;
    try
    {
        if(num2==0)
            throw num2;
        cout<<"나눗셈 몫: "<< num1/num2 <<endl;
        cout<<"나눗셈의 나머지: "<<num1%num2<<endl;
    }
    catch (int expn)
    {
        cout<<"제수는"<<expn<<"이 될 수 없습니다."<<endl;
        cout<<"프로그램을 다시 실행하세요."<<endl;
    }
    cout<<"end of main"<<endl;
    return 0;
}



#include <iostream>

using namespace std;

void inputName(char *name){
    cout<<"input name";
    cin>>name;
    if(strlen(name)<=2)
        throw name;
}

int inputAge(){
    int age;
    cout<<"input age";
    cin>>age;
    if(age<1)
        throw age;
    return 0;
}

int main(void){

    char name[512];
    int age;
    try{
        inputName(name);
        age=inputAge();

        cout<<"my name is"<<name<<endl;
        cout<<"my age is"<<age<<endl;
    }
    catch(char*e){
        cout<<"name error"<<e<<"\n";
    }
    catch(int e){
        cout<<"age error"<<e<<"\n";
    }
    return 0;

}




#include <iostream>

using namespace std;

void Handler(){
    cout<<"in handler"<<endl;
}
void f1(void) noexcept(false){
    cout<<"About to throw 1"<<endl;
    if(1)
        throw 1;
}

void f2(void) noexcept(false){
    try{
        f1();
    }
    catch(...){
        Handler();
        throw;
    }
}

int main(void)
{
    //f1();

    try{
        f2();
    }
    catch(...){
        cout<<"Caught exception from f2"<<endl;
    }
    return 0;

}



#include <iostream>
#include <exception>

using namespace std;

void MyErrorHandler()
{
    cout<<"처리되지 않은 예외가 발생했습니다.";//함수를 사용해 강제종료가 아닌 정상종료로 수정
    exit(-1);
}

int main(void)
{
    set_terminate(MyErrorHandler);
    try{
        throw 1;
    }
    catch (char* const ex){
        //throw에서 int형으로 던졌기 때문에 catch에서 int형으로 받아야 하지만
        //catch에서 처리불가 정수형 예외 처리 불가
    }
    return 0;
}


#include <iostream>


using namespace std;

class MyException{
    int myValue;
public:
    MyException(int value){
        myValue=value;
    }
    void excepctionResult(){
        if(myValue<10)
            cout<<"10이상의 값 입력"<<endl;
        else if(myValue>20)
            cout<<"20이하의 값 입력"<<endl;
        else if(myValue%7 != 0)
            cout<<"7의 배수 값 입력"<<endl;
    }
};

int main(void)
{
    int value;
    
    try {
        cout<<"10과 20사이 7의 배수 입력: ";
        cin>>value;
        if(value <10 | value >20 | value & 7 != 0)
            throw MyException(value);
        
        cout<<"정답!!10과 20사이의 7의 배수는"<<value<<endl;
    } catch(MyException &e)
    {
        e.exceptionResult();
    }
    return 0;
}


#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception{
    int myValue;
public:
    MyException(int value){
        myValue=value;
    }
    virtual const char* what() const throw() {
        if(myValue<10)
            cout<<"10이상의 값 입력"<<endl;
        else if(myValue>20)
            cout<<"20이하의 값 입력"<<endl;
        else if(myValue%7 != 0)
            cout<<"7의 배수 값 입력"<<endl;
        return "잘못된 예외 전달";
    }
};

int main(void)
{
    int value;
    try{
        cout<<"10과 20사이의 7의 배수를 입력하세요: ";
        cin>>value;

        if(value<10|value>20|value%7 != 0)
            throw MyException(value);

        cout<<"정답 10과 20사이의 7의 배수는"<<value<<endl;
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }

    return 0;
}


#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception{
    int myValue;
public:
    MyException(int value){
        myValue=value;
    }
    virtual const char* what() const throw() {
        if(myValue<10)
            cout<<"10이상의 값 입력"<<endl;
        else if(myValue>20)
            cout<<"20이하의 값 입력"<<endl;
        else if(myValue%7 != 0)
            cout<<"7의 배수 값 입력"<<endl;
        return "잘못된 예외 전달";
    }
};
int getMultiple(){
    int value;
    cout<<"10과 20사이의 7의 배수 입력";
    cin>>value;
    if(value<10|value>20|value%7 != 0)
        throw MyException(value);
    return value;
}

int getValue(){
    int value;
    value=getMultiple();
    return value;
}

int main(void)
{
    int value;
    try{
        value=getValue();
        cout<<"정답 10과 20사이의 7의 배수는"<<value<<endl;
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }

    return 0;
}



