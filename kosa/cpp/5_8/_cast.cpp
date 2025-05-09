

int main()
{
    float i =100.12345;
    double j=200.12345;
    float count = static_cast<float>(i/j);
}

int main()
{
    double d = 1212;
    void*p = &d;
    double *p=static_cast<double*>(p);
}

int main()
{
double d= 4.24;
int* i1=(int*)&d;
int *i2=static_cast<int*>(&d);
int i3=dynamic_cast<int>(d);
}

#include <iostream>
#include <stdio.h>

int main(void)
{
    int num=0x040204;
    char* ptr =reinterpret_cast<char*>(&num);
    std::cout<<static_cast<int>(*(ptr+1))<<std:endl;
    return 0;
}

int main()
{
    const char *cp;
    char *q = static_cast<char*>(cp);
    const_cast<string>(cp);
}
//안됨

int main()
{
const char*str="Hello";
char* str2=const_cast<char*>(str);//성향을 제거했다
std::cout<<str2<<std::endl;
//됨
}

int main()
{
const char*str="Hello";
char* str2=const_cast<char*>(str);//성향을 제거했다
str2[2]='a';//에러
std::cout<<str2<<std::endl;
//Segmentation fault
}

int main(void)
{
    int *p=NULL;
    p=new int(0); //동적 메모리 할당 및 초기화
    if(p==0){
        std::cout<<"동적 메모리 할당 실패\n";
        return 0;
    }
    std::cout<<"정수를 입력하세요";
    std::cin>>*p; // 동적 메모리 사용
    std::cout<<"입력된 정수는"<<p[0]<<"\n";//동적 메모리 사용
    delete p; //동적 메모리 해제
    p=NULL;
    return 0;
}


#include <iostream>

using namespace std;

int main(void)
{
  int *p = nullptr;
  p = new int{12.0}; //{갯수를 의미} 괄호{}안의 숫자 타입이 앞에 선언된 형과 괄호 안의 형이 명확하게 일치하도록 하기 위해 {}사용, (값을 의미),
  //int 정수{12.0} 실수 == 두 형이 다르다 컴파일 되지 않음 
  //p = new int(12.0);
  if(p == nullptr) {
    cout << "Memory allocation error!" << endl;
    return -1;
  }

  cout << "Input the number : ";
  cin >> *p;
  cout << "The inputted number is " << p[0] << endl;

  delete p;
  p = nullptr;

  return 0;
}

//nullptr: null=0을 의미하는 것인지 null pointer를 의미하는것인지 구문이 모호하여 c++11에서 추가됨 이렇게 사용해주는 것이 좋음
//



int main(void)
{
    int num;
    cin>>num;
    int *data=new int[num];
    for(int i=0; i<num; i++)
        cin>>data[i];
    delete[] data;
    return 0;
}


//128p

#include <iostream>

using namespace std;

char*NumberToString(int n)
{
    char*p=new char[20];
    sprintf(p, "%d", n);
    return p;
}
int main(void)
{
    int num;
    cout<<"정수를 입력하세요:";
    cin>>num;
    
    char *str=NumberToString(num);
    cout<<"문자열로 변환된 값:"<<str<<"\n";
    delete[] str;
    return 0;
}

3 3 
3.141592 74101257324219 
3.141592 65358979311600 


//C++ 파일 입출력

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{   
    string str ="파일에 쓰기";
    ofstream ofs("file.txt");
    ofs << str;
    ofs.close();
    ifstream ifs("file.txt");
    ifs>>str;
    cout<<str<<endl;
    ifs.close();
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
    fstream fs;
    fs.open("test.txt, ios::out");
    if(fs.fail())
        return 0;
    
    fs<<"keyboard"<<endl;
    fs<<"montior"<<endl;

    fs.close();

    fs.open("test.txt", ios::out|ios::binary);
    fs<<"desk"<<endl;
    fs.close();

    fs.open("test.txt", ios::in);
    string temp;

    while(fs>>temp, !fs.eof()){
        cout<<temp<<endl;
    }

    fs.close();
    return 0;
}
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(void)
{
    fstream fp;
    int data, score[5]={78, 96, 100, 25,96};

    fp.open("sample.txt", ios::out|ios::binary);
    fp.write((char*)score,20);
    fp.close();

    fp.open("sample.txt", ios::in | ios::binary);
    if(fp.fail()) return 1;

    fp.read((char*)&data, 4);
    cout<<setw(3)<<right<<data<<endl;

    fp.seekg(4, ios::cur);
    fp.read((char*)&data, 4);
    cout<<setw(3)<<right<<data<<endl;

    fp.close();
    return 0;
}


#include <iostream>
using namespace std;

int main(void)
{
    int a =1234, b=0x12345678;

    cout<<hex<<"16진수 a="<<a;
    cout<<dec<<"\t16진수 a="<<a<<endl;
    cout<<hex<<"16진수 b="<<a;
    cout<<hex<<"\t16진수 b="<<b<<endl;
    return 0;
}

#include <fstream>

using namespace std;

int main(void)
{
    ofstream ofs;
    
    //파일열기 없으면 생성 
    ofs.open("file.txt");

    //문자열에 쓰기
    ofs.write("This is an apple", 16);
    //tellp() 멤버함수를 이용해 파일의 현재 위치 얻음
    //현채 위치는 this is an apple의 맨 끝
    long pos =ofs.tellp();
    return 0;
}


#include <iostream>
using namespace std;

class Chulsoo{
    public: 
            void Eat();
};

void Chulsoo::Eat{
    cout<<"철수가 먹는다"<<endl;
}


int main(void)
{
    Chulsoo chulsoo;
    chulsoo.Eat();
    return 0;
}
/***********Call by value**************** */


#include <stdio.h>

/*****변수에 값을 할당하는 함수****/
int assignValue(int n)
{
    n = 10;
    return n;
}
/*메인함수*/
int main(void)
{
    int num=0, value;
    value = assignValue(num);
    printf("[input]: %d/:[Output]: %d\n", num, value);
    return 0;
}




/******class로 call by value***** */
#include <iostream>
using namespace std;

class Restaurant{
    public:
    int Steak;
};
//클래스 정의

class Chulsoo {
    public:
    int Eat(int);
};
//클래스 정의

int Chulsoo::Eat(int SteakNum) {
    SteakNum =10000;
    cout<<"철수는 먹는다"<<endl;
    return SteakNum;
}

int main(void)
{
    Chulsoo chulsoo;
    Restaurant restaurant;

    restaurant.Steak=20000;
    cout<<"철수는"<<chulsoo.Eat(restaurant.Steak)<<"원 짜리 스테이크를 먹었다고 거짓말을 했다."<<endl;
    cout<<"레스토랑은 철수가"<<chulsoo.Eat(restaurant.Steak)<<"원 짜리 스테이크를 먹었다고 알고 있다."<<endl;
    return 0;
}



/******class로 call by reference***** */

#include <iostream>
using namespace std;

void Swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int main(void)
{
    int a, b;
    cout<<"두 수를 입력하세요: ";
    cin>>a>>b;
    cout<<"Swap 호출 전의 a="<<a<<", b = "<<b<<endl;
    Swap(&a,&b);
    cout<<"Swap 호출 후의 a="<<a<<", b = "<<b<<endl;
    return 0;
}

//C++에서 레버런스에 의한 전달은 *를 붙이지 않고 선언할 매개변수의 앞에 &를 붙여주면 된다

#include <iostream>
using namespace std;

void Swap(int &x, int &y)
{
    int temp=x;
    x=y;
    y=temp;
}

int main(void)
{
    int a, b;
    cout<<"두 수를 입력하세요: ";
    cin>>a>>b;
    cout<<"Swap 호출 전의 a="<<a<<", b = "<<b<<endl;
    Swap(a,b);
    cout<<"Swap 호출 후의 a="<<a<<", b = "<<b<<endl;
    return 0;
}


#include <stdio.h>
int assignValue(int *n)
{
    *n = 10;
    return *n;
}
/*메인함수*/
int main(void)
{
    int num=0, value;
    value = assignValue(&num);
    printf("[input]: %d/:[Output]: %d\n", num, value);
    return 0;
}

//호출한 함수의 변수의 값도 함께 변화한다.
//메인 함수로부터 받아오는 인자(주소 연산자)를 포인터로 전달
//원본 데이터 회손할 수 있음


#include <iostream>
using namespace std;

class Restaurant{
    public:
    int Steak;
};
//클래스 정의

class Chulsoo {
    public:
    int Eat(int&);
};
//클래스 정의

int Chulsoo::Eat(int& SteakNum) {
    SteakNum =10000;
    cout<<"철수는 먹는다"<<endl;
    return SteakNum;
}

int main(void)
{
    Chulsoo chulsoo;
    Restaurant restaurant;

    restaurant.Steak=20000;
    cout<<"철수는"<<chulsoo.Eat(restaurant.Steak)<<"원 짜리 스테이크를 먹었다고 거짓말을 했다."<<endl;
    cout<<"레스토랑은 철수가"<<chulsoo.Eat(restaurant.Steak)<<"원 짜리 스테이크를 먹었다고 알고 있다."<<endl;
    return 0;
}




#include <iostream>
using namespace std;

int& RefRetFuncOne(int &ref)
{
    ref++;
    cout<<ref<<endl;
    return ref;
}

int main(void)
{
    int num1=1;
    cout<<num1<<endl;
    int num2=RefRetFuncOne(num1);
    cout<<num2<<endl;
    num1+=1;
    cout<<num1<<endl;
    num2+=100;
    cout<<num2<<endl;
    return 0;
}

/*******디폴트 변수*********** */


#include <iostream>

int BoxVolume(int lenght, int width=1, int height=1);// lenght는  디폴트변수 값이 선언되지 않았다

int main(void)
{
    std::cout<<"[3,3,3]: "<<BoxVolume(3, 3, 3)<<std::endl;
    std::cout<<"[5,5,D]: "<<BoxVolume(5, 5)<<std::endl;
    std::cout<<"[3,D,D]: "<<BoxVolume(7)<<std::endl;
    // std::cout<<"[D,D,D]: "<<BoxVolume()<<std::endl; //lenght에 값이 선언되어있지 않아서 error가 뜬다
    return 0;    
}

int BoxVolume(int lenght, int width, int height)//디포ㄹ트 값은 위에만 선언해주고 밑의 함수에는 선언해주지 않는다.
{
    return lenght*width*height;
}


#include <iostream>
using namespace std;



int main(void)
{
    Chulsoo chulsoo;
    Restaurant restaurant;

    restaurant.Steak=20000;
    cout<<"철수는"<<chulsoo.Eat(restaurant.Steak)<<"원 짜리 스테이크를 먹었다고 거짓말을 했다."<<endl;
    cout<<"레스토랑은 철수가"<<chulsoo.Eat(restaurant.Steak)<<"원 짜리 스테이크를 먹었다고 알고 있다."<<endl;
    return 0;
}

class Restaurant{
    public:
    int Steak;
};
//클래스 정의

class Chulsoo {
    public:
    int Eat(int);
};
//클래스 정의

int Chulsoo::Eat(int SteakNum) {
    SteakNum =10000;
    cout<<"철수는 먹는다"<<endl;
    return SteakNum;
}

//70p 완성하기



/***compare.h**/
#ifndef_COMPARE_H_
#define_COMPARE_H_

#include <iostream>
using namespace std;

int Compare(const int a, const int b);
int Compare(const float a, const float b);
int Compare(const char a, const char b);
int Compare(const char str1[], const char tr2[]);

#endif


/* compare.cpp*/

#include "compare.h"

int Compare(const int a, const int b)
{
    if(a>b)
        return 1;
    else if (a==b)
        return 0;
    else
        return -1;
}

int Compare(const float a, const float b){
    if(a>b)
        return 1;
    else if(a==b)
        return 0;
    else
        return -1;
}

int Compare(const char a, const char b){
    if(a>b)
        return 1;
    else if(a==b)
        return 0;
    else
        return -1;
}

int Compare(const char str1[], const char str2[]){
    int i
    for(i=0; str1[i]!='\0' && str2[i]!='\0'; i++)
    {
        if(str1[i]>str2[i])
            return 1;
        else if(str1[i]<str2[i])
            return -1;
        else
        ;
    }
    if(str1[i]=='\0' && str2[i]!='\0')
        return -1;
    else if(str1[i]!='\0' && str2[i]!='\0')
        return 1;
    else
        return 0;
}

/***main */
#include "compare.h"

int main(void)
{
    int a=34, b=4;
    float c=1.234f, d=98.34f;
    char e='H', f='K';
    char str1[]="computer", str2="computers";

    printf("%d\n",Compare(a, b));
    printf("%d\n",Compare(c, d));
    printf("%d\n",Compare(e, f));
    printf("%d\n",Compare(str1, str2));

    return 0;
}
