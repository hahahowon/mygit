public:
 /*클래스이름(인자리스트)*/   DailyLife(char* chulsooName, char* chulsooSex, char* chulsooJob, /
                                char* chulsooCharacter, int chulsooAge, bool chulsooMArriageStatus, /
                                char* youngheeName, char* youngheeSex, char* youngheeJob, /
                                char* youngheeCharacter, int youngheeAge, bool youngheeMarriageStatus)
                            
     /*:멤버변수이름(초기값)*/       :chulsoo(chulsooName, chulsooSex, chulsooJob, chulsooCharacter, chulsooAge, chulsooMArriageStatus),
                                    younghee(youngheeName, youngheeSex, youngheeJob, youngheeCharacter, youngheeAge, youngheeMarriageStatus){
                                    cout<<"DaliyLife::Dailylife(chulsooObject, youngheeobject)생성자 완료"<<endl;
                                }

     /* 초기화 리스트 
     클래스이름::클래스이름(인자리스트)
     :멤버변수이름(초기값), 멤버변수이름(초기값),......
     {
     } 
     */   
                                void run(){

                                    chulsoo.drive("레스토랑")
                                }   


#include <iostream>

using namespace std;

class Person
{
private:
    char* name;
    int age;
public:
    Person(char * myname, int myage)
    {
        int len=strlen(myname)+1; //NULL문자로 끝나니까 +1해줌
        name=new char[len]; //char[len] 메모리할당  {}는 초기화
        age=myage;
    }
    void ShowPersonInfo() const
    {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
    ~Person()
    {
        delete []name;
        cout<<"called destructor"<<endl;
    }
};



#include <iostream>
#include <string>
using namespace std;

class MyProfile{
private:
    string name;
public:
    MyProfile(string n){
        name.append(n);
    }
    void setName(string n){
        name.clear();
        name.append(n);
    }
    void getName(){
        cout<<"name: "<<name<<endl;
    }
};

int main()
{
    MyProfile profile1("allen");
    profile1.getName();

    MyProfile* ptrProfile1=new MyProfile("andrew");
    ptrProfile1->getName();
    delete ptrProfile1;

    return 0;
}

//복사생성자

#include <iostream>
#include <string>
using namespace std;

class SoSimple
{
private:
    int num1;
    int num2;
public:
    SoSimple(int n1, int n2): num1(n1),num2(n2)//private로 은닉된 데이터값인 num1, num2를 초기화 하기 위해 초기화리스트사용
    {}
    void ShowSimpleData()
    {
        cout<<num1<<endl;
        cout<<num2<<endl;
    }
};

int main(void)
{
    SoSimple sim1(15, 20);//초기화리스트 SoSimple(n1,n2)에 각각15, 20 값 할당
    SoSimple sim2=sim1;//sim1을 sim2로 할당 // 복사생성자
    sim2.ShowSimpleData();
    return 0;
}






#include <iostream>
#include <string>
using namespace std;

class SoSimple
{
private:
    int num1;
    int num2;
public:
    SoSimple(int n1, int n2): num1(n1),num2(n2)//private로 은닉된 데이터값인 num1, num2를 초기화 하기 위해 초기화리스트사용
    {}
    SoSimple(SoSimple &copy): num1(copy.num1), num2(copy.num2)
    {
        cout<<"called SoSimple(SoSimple &copy)"<<endl;
    }
    void ShowSimpleData()
    {
        cout<<num1<<endl;
        cout<<num2<<endl;
    }
};

int main(void)
{
    SoSimple sim1(15, 20);//초기화리스트 SoSimple(n1,n2)에 각각15, 20 값 할당
    cout<<"생성 및 초기화 직전"<<endl;
    SoSimple sim2=sim1;//sim1을 sim2로 할당 // 복사생성자
    cout<<"생성 및 초기화 직수"<<endl;
    sim2.ShowSimpleData();
    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n): num(n)//private로 은닉된 데이터값인 num1, num2를 초기화 하기 위해 초기화리스트사용
    {}
    SoSimple(const SoSimple &copy): num(copy.num)//멤버 이니셜라이저 기반의 멤버 초기화
    {
        cout<<"called SoSimple(SoSimple &copy)"<<endl;
    }
    void ShowData()
    {
        cout<<"num: "<<num<<endl;

    }
};

void SimpleFuncObj(SoSimple ob)
{
    ob.ShowData();
}
int main(void)
{
    SoSimple obj(7);
    cout<<"함수 호출 전"<<endl;
    SimpleFuncObj(obj);
    cout<<"함수 호출 후"<<endl;
    return 0;
}



#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {}
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout<<"Called SoSimple(const SoSimple& copy)"<<endl;
    }
    SoSimple& AddNum(int n)
    {
        num+=n;
        return *this;
    }
    void ShowData()
    {
        cout<<"num: "<<num<<endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    cout<<"return 이전"<<endl;
    return ob;
}

int main(void)
{
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData();
    obj.ShowData();
    return 0;
}



#include <iostream>
using namespace std;;
class Temporary
{
private:
    int num;
public:
    Temporary(int n) :num(n)
    {
        cout<<"create obj: "<<num<<endl;
    }
    ~Temporary()//소멸자
    {
        cout<<"destroy obj: "<<num<<endl;
    }
    void ShowTempInfo()
    {
        cout<<"My num is "<<endl;
    }
};

int main(void)
{
    Temporary(100);//임시객체 Temporary
    cout<<"*************after make**********"<<endl<<endl;
    Temporary(200).ShowTempInfo();
    cout<<"*************after make**********"<<endl<<endl;
    const Temporary &ref=Temporary(300); //&ref라는 이름을 가진 객체
    cout<<"*************end of main**********"<<endl<<endl;
    return 0;
}



#include <iostream>
using namespace std;;

class MyProFile
{
private:
    int* ptrNum;
    int zipcode;
public:
    MyProFile(int n, int zc){
        ptrNum = new int;
        *ptrNum = n;
        zipcode =zc;
    }
    void setProFile(int n, int zc){
        *ptrNum=n;
        zipcode =zc;
    }
    void getProFile(){
        cout<<"ptrNum: "<<ptrNum<<endl;
        cout<<"*ptrNum: "<<ptrNum<<endl;
        cout<<"zipcode: "<<zipcode<<endl;
        cout<<endl;
    }


    ~MyProFile(){
        delete ptrNum;
        cout<<"Destructor"<<endl;
    }
};

int main(void)
{
    MyProFile profile1(10, 90031);
    profile1.getProFile();

    MyProFile profile2(profile1);
    profile1.getProFile();
    profile2.getProFile();
    profile2.setProFile(500, 90000);
    profile1.getProFile();
    profile2.getProFile();
    return 0;
}

//이렇게 만들면 같은 주소를 가리키게 되며 메모리가 두번 삭제되어 프로그램 죽는다





#include <iostream>
using namespace std;;

void print(int &x){
    cout<<"print(int &x)";
}

void print(const int &x){
    cout<<"print(const int &x)"<< endl;
}
void print(int &&x){
    cout<<"print(int &&x)"<<endl;
}

int main(void)
{
    const int& x =3;//int라는 변수타입과 이름이 있기때문에 임시객체가 아니다
    print(x);//
    print(3);//3은 임시객체
    return 0;
}
/* 결과
print(const int &x)
print(int &&x)
 */




 #include <iostream>
#include <string>

using namespace std;

class MyClass
{
public:
    MyClass(){}
    MyClass(string str): m_str(str){}
    void print(){
        cout<<m_str<<endl;
    }
private:
    string m_str;
};

int main(void)
{
    MyClass A("aaa");
    MyClass B;
    MyClass C;

    B=A; //A의 "aaa"문자열 B에 복사 대입;; 복사생성자 만들어짐
    C=std::move(A); // A의 "aaa"문자열 C에 이동 복사생성자 만들어지지 않음
    A.print();
    B.print();
    C.print();
    return 0;
}



#include <iostream>

using namespace std;

void print(int &x)
{
  cout << "&x : " << x << endl;
}

void print(const int &x)
{
  cout << "const &x : " << x << endl;
}

void print(int &&x)
{
  cout << "&&x : " << x << endl;
}

int main(void)
{
  int a;
  a = 10;
  int &x1 = a;
  const int &x2 = 10;
  int &&x3 = 10;
  int &&x4 = std::move(a);

  print(x1);    // 1
  print(x2);    // 2
  print(x3);    // 1
  print(x4);    // 1
  print(std::move(x4));    // 3
  print(3);     // 3

  return 0;
}



#include <iostream>
#include <string>
using namespace std;



int main(void)
{
    string name1="allen";
    cout<<"name1:"<<name1<<endl;

    string name2=std::move(name1);
    cout<<"After, name2=std::move(name1)"<<endl;
    cout<<"->name1: "<<name1<<endl;
    cout<<"->name2: "<<name2<<endl<<endl;

    int zipcode1=90031;
    
    cout<<"zipcode1: "<<zipcode1<<endl;
    
    int zipcode2=std::move(zipcode1);
    
    cout<<"After,zipcode2=std::move(zipcode1)"<<endl;
    cout<<"zipcode1:"<<zipcode1<<endl;
    cout<<"zipcode2:"<<zipcode2<<endl;
    return 0;
}



#include <iostream>
#include <string>
using namespace std;

class Integer{
public:
    int *val;
    Integer()=default;
    Integer(int val){
        this->val = new int(val);
    }
    ~Integer(){
        delete val;
    }
};

Integer Add(const Integer&a, const Integer &b){
    Integer tmp;
    tmp.val =new int(a.val+b.val);
    return tmp;
}
int main(void)
{
    Integer i1(1), i2(3);
    i1.val =Add(i1, i2).val;
    cout<<i1.val;
    return 0;
}




#include <iostream>
#include <string>
using namespace std;

class MyArray{
private:
    int num;
public:
    MyArray(int n){
        cout<<"생성자 호출"<<endl;
        num=n;
    }
    MyArray(const MyArray& copy){
        cout<<"복사 생성자 호출"<<endl;
        num=copy.num;
    }
    MyArray(MyArray&&move){
        cout<<"이동생성자 호출"<<endl;
        num=move.num;
        move.num=0;
    }
    MyArray operator=(MyArray&&move){
        cout<<"대입 연산자 호출"<<endl;
        swap(num, move.num);
        return *this;
    }
    int getNum(){
        return num;
    }

};


MyArray CreateMyArray(){
    return MyArray(100);
}

int main(){
    MyArray ar1(10);
    MyArray ar2(ar1);
    cout<<"ar1.getNum:"<<ar1.getNum()<<endl;
    cout<<"ar2.getNum:"<<ar2.getNum()<<endl;

    ar2=CreateMyArray();
    cout<<"ar1.getNum:"<<ar1.getNum()<<endl;
    cout<<"ar2.getNum:"<<ar2.getNum()<<endl;

    MyArray ar3(std::move(ar1));
    cout<<"ar1.getNum:"<<ar1.getNum()<<endl;
    cout<<"ar3.getNum:"<<ar3.getNum()<<endl;

    return 0;
}







#include <iostream>
#include <string>

using namespace std;

class MyClass{

public:
    MyClass(){}
    MyClass(string str, int a):m_str(str), m_ptr(new int(a)){}
    ~MyClass(){
        cout<<"~MyClass()"<<endl;
        if(m_ptr!=nullptr)
            delete m_ptr;
    }

    void print(){
        cout<<"String: "<<m_str<<endl;
        if(m_ptr !=nullptr)
            cout<<"ptr: "<<m_str<<endl;
        else
            cout<<"ptr: "<<endl<<endl;

    }

    MyClass& operator=(MyClass& other){
        cout<<"operator=(MyClass& other)"<<endl;
        m_str=other.m_str;
        m_ptr=new int(*other.m_ptr);
        return *this;
    }
#if 0
    MyClass& operator=(MyClass&&other)=default;
#else
    MyClass& operator=(MyClass&&other){
        cout<<"operator=(MyClass&&other)"<<endl;
        m_str=std::move(other.m_str);
        m_ptr=std::move(other.m_ptr);
        other.m_ptr =nullptr;
        return *this;
    }
private:
    string m_str ="ABC";
    int * m_ptr=nullptr;

};

int main(void)
{
    MyClass A("aaa", 10);
    MyClass B;
    MyClass C;

    B=A;
    C=move(A);

    A.print();

    B.print();

    C.print();
    return 0;
}
