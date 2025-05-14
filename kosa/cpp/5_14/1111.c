#include <iostream>
#include <string>

using namespace std;
class  Chulsoo;

class Younghee{
private:
    int age;
public:
    Younghee(int age): age(age){
        cout<<"Younghee::Younghee(age) 생성자 완료"<<endl;
    }
    void introduce(){
        cout<<"영희 나이: "<< age <<endl;
    }
    void whoIsOlder(const Chulsoo & chulsooObj);
};

class Chulsoo{
private:
    int age;
public:
    Chulsoo(int age): age(age){
        cout<<"Chulsoo::Chulsoo(age) 생성자 완료"<<endl;
    }
    void introduce(){
        cout<<"Chulsoo age: "<<age<<endl;
    }
    //friend class Younghee;
};

void Younghee::whoIsOlder(const Chulsoo&chulsooObj){
    cout<<"영희는 철수보다"<<((age>chulsooObj.age)? "나이가 많다" :"나이가 같거나 적다");
}
int main(void)
{
    Chulsoo chulsoo1(32);
    chulsoo1.introduce();
    Younghee younghee1(35);
    younghee1.introduce();
    
    younghee1.whoIsOlder(chulsoo1);
    return 0;    
}







#include <iostream>
#include <string>

using namespace std;
class  Chulsoo;

class Younghee{
private:
    int age;
public:
    Younghee(int age): age(age){
        cout<<"Younghee::Younghee(age) 생성자 완료"<<endl;
    }
    void introduce(){
        cout<<"영희 나이: "<< age <<endl;
    }
    void whoIsOlder(const Chulsoo & chulsooObj);
    
    friend void howOldAreYou(const Chulsoo& chulsooObj, const Younghee& youngheeObj);
};

class Chulsoo{
private:
    int age;
public:
    Chulsoo(int age): age(age){
        cout<<"Chulsoo::Chulsoo(age) 생성자 완료"<<endl;
    }
    void introduce(){
        cout<<"Chulsoo age: "<<age<<endl;
    }
    friend void Younghee::whoIsOlder(const Chulsoo & chulsooObj);//
    friend void howOldAreYou(const Chulsoo & chulsooObj, const Younghee&youngheeObj);
    //friend class Younghee;
};

void howOldAreYou(const Chulsoo&chulsooObj, const Younghee&youngheeObj){ //영희와 철수의 나이를 출력하는 함수
    cout<<"철수는"<<chulsooObj.age<<"살 입니다"<<endl;
    cout<<"영희는"<<youngheeObj.age<<"살 입니다"<<endl;
}

void Younghee::whoIsOlder(const Chulsoo&chulsooObj){
    cout<<"영희는 철수보다"<<((age>chulsooObj.age)? "나이가 많다" :"나이가 같거나 적다");
}
int main(void)
{
    Chulsoo chulsoo1(32);
    chulsoo1.introduce();
    Younghee younghee1(35);
    younghee1.introduce();
    
    younghee1.whoIsOlder(chulsoo1);
    howOldAreYou(chulsoo1, younghee1);
    return 0;    
}



#include <iostream>
using namespace std;

class SoSimple
{
private:
    static int simObjCnt; //static 멤버 변수, 클래스 변수
public:
    SoSimple()
    {
        simObjCnt++;
        cout<<simObjCnt<<"번째 SoSimple 객체"<<endl;
    }
};

int SoSimple::simObjCnt=0; //static 멤버변수 초기화

int main(void)
{
    SoSimple sim1;
    SoSimple sim2;
    SoSimple sim3;
}

#include <iostream>
using namespace std;

class Chulsoo
{
private:
    int age;
    static int chulsooPrivateCounter;
protected:
    static int chulsooProtectedCounter;
public:
    static int chulsooPublicCounter;
    Chulsoo(int age) : age(age) {
        chulsooPrivateCounter++;
        chulsooProtectedCounter++;
        chulsooPublicCounter++;
        cout<<"Chulsoo::chulsoo(age)생성자로 만들어지는"<<chulsooPrivateCounter<<"(Private)번째 객체 생성 완료"<<endl;
        cout<<"Chulsoo::chulsoo(age)생성자로 만들어지는"<<chulsooProtectedCounter<<"(Protected)번째 객체 생성 완료"<<endl;
        cout<<"Chulsoo::chulsoo(age)생성자로 만들어지는"<<chulsooPublicCounter<<"(Public)번째 객체 생성 완료"<<endl;
    }
};

int Chulsoo::chulsooPublicCounter=0;
int Chulsoo::chulsooProtectedCounter=0;
int Chulsoo::chulsooPrivateCounter=0;

class Younghee
{
private:
    int age;
public:
    Younghee(int age) : age(age){
        //Chulsoo::chulsooPrivateintroduceCounter++;
        //Chulsoo::chulsooProtectedintroduceCounter++;
        Chulsoo::chulsooPublicCounter++;
        cout<<"younghee::Younghee(age)생성자로 만들어지는"<<Chulsoo::chulsooPublicCounter<<"번째 객체 생성 완료"<<endl;
    }
};


int main(void)
{
    Chulsoo chulsoo1(32);
    Chulsoo chulsoo2(32);
    Younghee younghee1(32);
    Younghee younghee2(32);
    return 0;

}


#include <iostream>
using namespace std;

class A{
private:
    int num;
public:
    A(int num):num(num){
        cout<<"A::A(age)"<<endl;
    }
    void result(){
        cout<<"resutl: "<<num<<endl;
    }
    A add(const A&aObj);
    A sub(const A&aObj);
    A mul(const A&aObj);
    A div(const A&aObj);
};

int main(void)
{
    A a1(32);
    A a2(15);
    a1.result();
    a2.result();

    A aadd = a1.add((a2));
    aadd.result();
    A asub = a1.sub((a2));
    asub.result();
    A amul = a1.mul((a2));
    amul.result();
    A adiv = a1.div((a2));
    adiv.result();

    return 0;
}

A A::add(const A&aObj){
    cout<<"A::add()"<<endl;
    A a(this->num+aObj.num);
    return a;
}


A A::sub(const A&aObj){
    cout<<"A::sub()"<<endl;
    A a(this->num+aObj.num);
    return a;
}


A A::mul(const A&aObj){
    cout<<"A::mul()"<<endl;
    A a(this->num+aObj.num);
    return a;
}


A A::div(const A&aObj){
    cout<<"A::div()"<<endl;
    A a(this->num+aObj.num);
    return a;
}




#include <iostream>
using namespace std;

class A{
private:
    int num;
public:
    A(int num):num(num){
        cout<<"A::A(age)"<<endl;
    }
    void result(){
        cout<<"resutl: "<<num<<endl;
    }
    A operator+(const A&aObj);
    A operator-(const A&aObj);
    A operator*(const A&aObj);
    A operator/(const A&aObj);

    /*
    A add(const A&aObj);
    A sub(const A&aObj);
    A mul(const A&aObj);
    A div(const A&aObj);
    */
};

int main(void)
{
    A a1(32);
    A a2(15);
    a1.result();
    a2.result();

    A aAdd= a1+ a2;
    aAdd.result();
    A aSub= a1- a2;
    aSub.result();
    A aMul= a1* a2;
    aMul.result();
    A aDiv= a1/ a2;
    aDiv.result();
    /*
    A aadd = a1.add((a2));
    aadd.result();
    A asub = a1.sub((a2));
    asub.result();
    A amul = a1.mul((a2));
    amul.result();
    A adiv = a1.div((a2));
    adiv.result();
    */

    return 0;
}

A A::operator+(const A&aObj){
    cout<<"A::operator+()"<<endl;
    A a(this->num+aObj.num);
    return a;
}
A A::operator-(const A&aObj){
    cout<<"A::operator-()"<<endl;
    A a(this->num-aObj.num);
    return a;
}
A A::operator*(const A&aObj){
    cout<<"A::operator*()"<<endl;
    A a(this->num*aObj.num);
    return a;
}
A A::operator/(const A&aObj){
    cout<<"A::operator/()"<<endl;
    A a(this->num/aObj.num);
    return a;
}



#include <iostream>
using namespace std;

class A{
private:
    int num;
public:
    A(int num):num(num){
        cout<<"A::A(age)"<<endl;
    }
    void result(){
        cout<<"resutl: "<<num<<endl;
    }
    friend A operator+(const A&aobj1, const A&aobj2);
};

int main(void)
{
    A a1(32);
    A a2(15);
    a1.result();
    a2.result();
    A aAdd =  3 + a1;
    aAdd.result();

    return 0;
}

A operator+(const A&aObj1, const A&aObj2){
    cout<<"A::operator+()"<<endl;
    A a(aObj1.num+aObj2.num);
    return a;
}
//돌아가는 과정에서 형변환에 대한 내용 찾아보자




#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x=0, int y=0):xpos(x), ypos(y)
    {}
    void ShowPosition() const
    {
        cout<<'['<<xpos<<','<<ypos<<']'<<endl;
    }
    Point& operator++()
    {
        xpos+=1;
        ypos+=1;
        return *this;
    }

    friend Point& operator--(Point &ref);
};

Point& operator--(Point &ref)
{
    ref.xpos-=1;
    ref.ypos-=1;
    return ref;
}


int main(void)
{
    Point pos(1,2);
    ++pos;
    pos.ShowPosition();
    --pos;
    pos.ShowPosition();
    ++(++pos);
    pos.ShowPosition();
    --(--pos);
    pos.ShowPosition();
    
    return 0;
}


#include <iostream>

using namespace std;
class Number
{
private:
    int num;
public:
    Number(int n=0): num(n)
    {
        cout<<"Numder(int n=0)"<<endl;
    }
    Number& operator=(const Number& ref)
    {
        cout<<"operator=()"<<endl;
        num=ref.num;
        return *this;
    }
    Number(const Number& copy):num(copy.num)
    {
        cout<<"Number.copy"<<endl;
    }
    operator int()
    {
        return num;
    }
    void showNumber(){cout<<num<<endl;}
};

int main(void)
{
    Number num1;
    num1=30;
    Number num2=num1+30;
    num2.showNumber();
    return 0;
}


#include <iostream>
using namespace std;

class Chulsoo
{
private:
    int age;
public:
    Chulsoo(const Chulsoo&source): age(source.age){
        cout<<"Chulsoo::Chulsoo()copy"<<endl;
    }
    Chulsoo(int age): age(age){
        cout<<"Chulsoo::Chulsoo(age)"<<endl;
    }
    Chulsoo(){
        cout<<"Chulsoo::Chulsoo()"<<endl;
    }
    void introduce();
    Chulsoo& operator=(const Chulsoo& chulsooObj){
        this->age=chulsooObj.age;
        cout<<"Chulsoo::operator=()"<<endl;
        return *this;
    }
    ~Chulsoo(){
        cout<<"Chulsoo::~chulsoo()"<<endl;
    }
};



int main(void)
{
    Chulsoo chulsoo1(32);
    Chulsoo chulsoo2(50);
    Chulsoo chulsoo3(100);
    chulsoo1.introduce();
    chulsoo2.introduce();

    cout<<"==============before============="<<endl;
    chulsoo1 =chulsoo2=chulsoo3
    cout<<"==============after============="<<endl;
    chulsoo1.introduce();
    chulsoo2.introduce();
    return 0;
}

void Chulsoo::introduce(){
    cout<<"age"<<age<<endl;
}



#include <iostream>
using namespace std;

class Chulsoo
{
private:
    int age;
public:
    Chulsoo(const Chulsoo&source): age(source.age){
        cout<<"Chulsoo::Chulsoo()copy"<<endl;
    }
    Chulsoo(int age): age(age){
        cout<<"Chulsoo::Chulsoo(age)"<<endl;
    }
    Chulsoo(){
        cout<<"Chulsoo::Chulsoo()"<<endl;
    }
    void introduce();
    Chulsoo& operator=(const Chulsoo& chulsooObj){
        this->age=chulsooObj.age;
        cout<<"Chulsoo::operator=()"<<endl;
        return *this;
    }
    ~Chulsoo(){
        cout<<"Chulsoo::~chulsoo()"<<endl;
    }
};



int main(void)
{
    Chulsoo chulsoo1(32);
    Chulsoo chulsoo2(50);
    Chulsoo chulsoo3(100);
    chulsoo1.introduce();
    chulsoo2.introduce();
    chulsoo3.introduce();

    cout<<"==============before============="<<endl;
    chulsoo1 =chulsoo2=chulsoo3;
    cout<<"==============after============="<<endl;
    chulsoo1.introduce();
    chulsoo2.introduce();
    chulsoo3.introduce();
    return 0;
}

void Chulsoo::introduce(){
    cout<<"age"<<age<<endl;
}




#include <iostream>
#include <string>
using namespace std;

class Person
{

private:
    char * name;
    int age;
public:
    Person(char*myname, int myage)
    {
        int len=strlen(myname)+1;
        name=new char[len];
        strncpy(name ,myname, len);
        age=myage;
    }
    void ShowPersonInfo() const
    {
        cout<<"name: "<<name<<endl;
        cout<<"age: "<<age<<endl;
    }
    ~Person()
    {
        delete []name;
        cout<<"called destructor!"<<endl;
    }
};

int main(void)
{
    Person man1("Lee Dong Woo", 29);
    Person man2("Yoon Ji Yul", 22);
    man2=man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}
//이렇게 만들면 죽음   

#include <iostream>
#include <string>
using namespace std;

class Person
{

private:
    char *name;
    int age;
public:
    Person(char*myname, int myage)
    {
        int len=strlen(myname)+1;
        name=new char[len];
        strncpy(name ,myname, len);
        age=myage;
    }
    void ShowPersonInfo() const
    {
        cout<<"name: "<<name<<endl;
        cout<<"age: "<<age<<endl;
    }
    ~Person()
    {
        delete []name;
        cout<<"called destructor!"<<endl;
    }
    Person& operator=(const Person& ref)
    {
        delete []name;
        int len=strlen(ref.name)+1;
        name= new char[len];
        strncpy(name, ref.name,len);
        age=ref.age;
        return *this;
    }

};

int main(void)
{
    Person man1("Lee Dong Woo", 29);
    Person man2("Yoon Ji Yul", 22);
    man2=man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}


#include <iostream>
using namespace std;

class Chulsoo{
private:
    int age;
public:
    Chulsoo(int age):age(age){
        cout<<"chulsoo::Chulsoo"<<endl;
    }//생성자
    Chulsoo(){
        cout<<"chulsoo::Chulsoo"<<endl;
    }//임시 객체 생성자
    ~Chulsoo(){
        cout<<"Chulsoo::~chulsoo"<<endl;
    }
    void setAge(int age){
        this->age=age;
    }
    void introduce();

};

int main(void)
{
    Chulsoo*chulsooPtr1=(Chulsoo*)malloc(sizeof(Chulsoo));
    //Chulsoo*chulsooPtr1=new Chulsoo(32);

    chulsooPtr1->setAge(32);
    chulsooPtr1->introduce();
    free(chulsooPtr1);
    //delete chulsooPtr1;
    return 0;
}

void Chulsoo::introduce(){
    cout<<"Chulsoo age: "<<age<<endl;
}
//malloc을 쓰면 생성자 출력이 안된다.
//new를 쓰자



#include <iostream>
using namespace std;

class Point {
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {  }
    friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}
class BCPA//BoundCheakPointArray
{
private:
    Point *arr;
    int arrlen;
    BCPA(const BCPA&arr){}//초기화
    BCPA operator*(const BCPA& arr){}//초기화 연산자
public:
    BCPA(int len): arrlen(len)
    {
        arr=new Point[len];
    }
    Point& operator[](int idx)
    {
        if( idx < 0 || idx >=arrlen ){
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return arr[idx];
    }
    Point operator[] (int idx) const
    {
        if( idx > 0 || idx >=arrlen ){
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return arr[idx];
    }
    int GetArrLen() const { return arrlen; }
    ~BCPA() { delete []arr;}

};

int main(void)
{
    BCPA arr(3);
    arr[0]=Point(3, 4);
    arr[1]=Point(5, 6);
    arr[2]=Point(7, 8);

    for(int i=0; i<arr.GetArrLen();i++){
        cout<<arr[i];
    }
    return 0;
}

//객체 저장을 위한 배열 클래스 1


