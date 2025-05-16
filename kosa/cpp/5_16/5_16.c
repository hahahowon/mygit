#include <iostream>

using namespace std;

class BaseOne
{
public:
    void SimpleFuncOne(){ cout<<"BaseOne"<<endl;}
};
class BaseTwo
{
public:
    void SimpleFuncTwo(){cout<<"BaseTwo"<<endl;}
};
class MultiDerived : public BaseOne, protected BaseTwo//다중 상속
{
public:
    void ComplexFunc()
    {
        SimpleFuncOne();
        SimpleFuncTwo();
    }
};

int main()
{
    MultiDerived mdr;
    mdr.ComplexFunc();
    return 0;
}







/*Template*/

#include <iostream>

using namespace std;

int const add( int const a,int const b )//const int a와 int const a의 차이를 기억하자
{
    return a+b;
}

int main(void)
{
    int i= 5;
    int j= 10;
    cout<<add(i,j)<<endl;
    return 0;

}


#include <iostream>

using namespace std;

template <typename T>
T const add( T const a,T const b )
{
    return a+b;
}

int main(void)
{
    int i= 5;
    int j= 10;
    cout<<add(i,j)<<endl;
    return 0;

}
//템플릿 예시



#include <iostream>

using namespace std;

template <class T1, class T2>
void ShowData( double num)
{
    cout<<(T1)num<<", "<<(T2)num<<endl;
}

int main(void)
{
    ShowData<char, int>(65);
    ShowData<char, int>(66);
    ShowData<char, double>(67);
    ShowData<short, double>(68);
    ShowData<short, double>(69);
    return 0;
}
//둘 이상의 타입에 대한 템플릿 선언 예시






#include <iostream>

using namespace std;

template <typename R, typename T, typename U>
R const add( T const& a, U const& b, R const& c){
    return a+b+c;
}


int main(void)
{
    double i= 5.1;
    int a = 5;
    int b = 5;
    cout<<i<<"+"<<a<<"="<<add(i, a, b)<<endl;
    return 0;
}
// 이구조 다시한번 보자




#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class MyArray{
private:
    vector<T> list;
public:
    void add_list(T const&);
    void delete_last_list(void);
    void show_list(void);
};

template <typename T>
void MyArray<T>::add_list(T const& element)
{
    list.push_back(element);
}
template <typename T>
void MyArray<T>::delete_last_list(void){
    list.pop_back();
}

template<typename T>
void MyArray<T>::show_list(void){
    cout<<"[MyArray list look up]"<<endl;
    for(typename vector<T>::iterator i=list.begin(); i!=list.end(); ++i)
        cout<<*i<<endl;
}
//********템플릿의 부분 특수화 실습*****///
template<>
class MyArray<int>
{
private:
    vector<int>list;
public:
    void add_list(int const&);
    void delete_last_list(void);
    void show_list(void);
};
void MyArray<int>::add_list(int const& element)
{
    list.push_back(element);
}
void MyArray<int>::delete_last_list(void){
    list.pop_back();
}

void MyArray<int>::show_list(void){
    cout<<"[MyArray list look up(specialization for int)]"<<endl;
    for(typename vector<int>::iterator i=list.begin(); i!=list.end(); ++i)
        cout<<*i<<endl;
}

int main(void){
    MyArray<int>array1;
    array1.add_list(1);
    array1.add_list(2);
    array1.add_list(3);
    array1.add_list(4);
    array1.add_list(5);
    array1.show_list();

    array1.delete_last_list();
    array1.delete_last_list();
    array1.show_list();


    MyArray<double>array2;
    array2.add_list(1.1);
    array2.add_list(2.2);
    array2.add_list(3.3);
    array2.add_list(4.4);
    array2.add_list(5.5);
    array2.show_list();
    array2.delete_last_list();
    array2.delete_last_list();

    array2.show_list();
    return 0;
}




#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Person{
private:
    int age;
    string name;
public:
    Person(const int a, const string& n): age(a), name(n){}
    int getAge() {return age;}
    string getName(){return name;}
};

int main(int argc, char **argv)
{
    //c++03
    Person p1{20, "Tom"};
    Person p2{19, "Tom"};
    //c++11
    vector<Person> vec{
    {21, "Smith"}, {39,"john"}, {23, "Mary"}, {45,"Ted"}
    };

    for_each(vec.begin(),vec.end(),[](Person p){
        cout<<p.getAge()<<","<<p.getName()<<endl;
    });
    return 0;
}








//deque
#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    cout<<"dq.size():"<<dq.size()<<endl;
    cout<<"[dq: ";
    for(auto i = 0; i < dq.size();i++)
        cout<<dq[i]<<" ";
    cout<<endl;

    for(auto i = 0; i< dq.size();i++)
        cout<<"dq["<<i<< "] address:"<<&dq[i]<<endl;
    cout<<endl;

    deque<int>dq2;
    dq2.push_back(100);
    dq2.push_back(200);
    dq2.push_back(300);

    cout<<"dq2.size():"<<dq2.size()<<endl;
    cout<<"[dq2]:";
    for(auto i=0; i <dq2.size(); i++)
        cout<<dq2[i]<<" ";
    cout<<endl;
    for(auto i =0; i<dq2.size(); i++)
        cout<<"dq2["<<i<<"] address: "<<&dq2[i]<<endl;
    cout<<endl;

    dq2.push_back(40);
    dq2.push_back(50);
    dq2.push_back(60);
    cout<<"da.size():"<<dq.size()<<endl;
    cout<<"[dq]:";
    for(auto i =0; i<dq.size(); i++)
        cout<<dq[i]<<" ";
    cout<<endl;

    for(auto i=0; i<dq.size();i++)
        cout<<"dq["<<i<<"] adress: "<<&dq[i]<<endl;
    cout<<endl;

    for(int i=70; i<2000; i+=10)
        dq.push_back(i);

    cout<<"dq.size():"<<dq.size()<<endl;
    cout<<"[dq]: ";

    for(auto i= 0; i< dq.size(); i++)
        cout<<dq[i]<<" ";
    cout<<endl;
    for(auto i=0; i<dq.size();i++)
        cout<<"dq["<<i<<"] adress: "<<&dq[i]<<endl;
    cout<<endl;
    cout<<"dq[127]("<< &dq[127]<<"):"<<dq[127]<<endl;
    cout<<"dq[128]("<< &dq[128]<<"):"<<dq[128]<<endl;

    deque<int>::iterator i = dq.begin()+127;
    cout<<"*i("<<&(*i)<<"):"<<*i<<endl;
    i++;
    cout<<"*++i("<<&(*i)<<"): "<< *i << endl;
    int*j=&dq[127];
    cout<<j<<":"<<*j<<endl;
    j++;
    cout<<j<<":"<<*j<<endl;

    return 0;






}
