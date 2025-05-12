#include <iostream>
using namespace std;

#define NMAE_LEN      20
#define SEX_LEN       10
#define JOB_LEN       20
#define CHARACTER_LEN 20


struct Chulsoo
{
    char name[NMAE_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    void introduce(){};
    void eat(char*food){};
    void sleep(){};
    void drive(char*destination){};

};


int main(void)
{
    Chulsoo chulsoo ={"철수","남성","작가","diligent",32,true};
    chulsoo.drive("레스토랑");
    chulsoo.eat("스테이크");
    return 0;
}


#include <iostream>
using namespace std;

#define NMAE_LEN      20
#define SEX_LEN       10
#define JOB_LEN       20
#define CHARACTER_LEN 20


class Chulsoo
{
    public:
    char name[NMAE_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    void introduce(){};
    void eat(char *food){};
    void sleep(){};
    void drive(char *destination){};

};


int main(void)
{
    Chulsoo chulsoo ={"철수", "남성", "작가", "diligent", 32};
    chulsoo.drive((char*)"레스토랑");
    chulsoo.eat((char*)"스테이크");
    return 0;
}



#include <iostream>
using namespace std;

#define NMAE_LEN      20
#define SEX_LEN       10
#define JOB_LEN       20
#define CHARACTER_LEN 20


class Chulsoo
{
    
    char name[NMAE_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    void introduce(){};
    void eat(const char *food){};
    public:
    void sleep(){};
    void drive(const char *destination){};

};


int main(void)
{
    Chulsoo chulsoo ={"철수", "남성", "작가", "diligent", 32};
    chulsoo.drive("레스토랑");
    chulsoo.eat("스테이크");
    return 0;
}


#include <iostream>

class Stack
{
    public:
        int m_size;
        int m_top;
        int *m_buffer;

    void Initialize(int size =10);
    bool Push(int value);
    bool Pop(int& value);
    void RemoveALL();
};

void Skack::Initialize(int size){
    m_size = size;
    m_top = -1;
    m_buffer = new int[m_size];
    memset(m_buffer, 0, sizeof(int)*m_size);
}

void Stack::RemoveALL(){
    m_size = 0;
    m_top = -1;
    delete[] m_buffer;
    m_buffer =NULL;
}

bool Stack::Push(int value){
    if(m_top>=m_size -1) return false;
    m_buffer[++m_top] =value;
    return true;
}

bool Stack::Pop(int&value){
    if(m_top<0) return false;
    value = m_buffer[m_top--];
    return true;
}

int main(void)
{
    Stack s1;
    s1.Initialize(5);
    //s1.m_top=1;
    int data;
    s1.Pop(data);
    //delete[]s1.m_buffer;
    s1.Push(123);
    return 0;
}





////

#include <iostream>

class Stack
{
    public:
        int m_size;
        int m_top;
        int *m_buffer;

    void Initialize(int size =10);
    bool Push(int value);
    bool Pop(int& value);
    void RemoveALL();
};

void Stack::Initialize(int size){
    m_size = size;
    m_top = -1;
    m_buffer = new int[m_size];
    memset(m_buffer, 0, sizeof(int)*m_size);
}

void Stack::RemoveALL(){
    m_size = 0;
    m_top = -1;
    delete[] m_buffer;
    m_buffer =NULL;
}

bool Stack::Push(int value){
    if(m_top>=m_size -1) return false;
    m_buffer[++m_top] =value;
    return true;
}

bool Stack::Pop(int&value){
    if(m_top<0) return false;
    value = m_buffer[m_top--];
    return true;
}


class Stack{
    public:
        int m_size;
        int m_top;
        int *m_buffer;

    void Initialize(int size =10);
    bool Push(int value);
    bool Pop(int& value);
    void RemoveALL();

    int GetSize();
    int GetTop();
    bool SetSize(int size);
    bool GetData(int index, int& data);
};

int Stack::GetSize(){
    return m_size;
}

int Stack::GetTop(){
    return m_top;
}

bool Stack::SetSize(int size){
    if(size<m_size)  return false;
    int *tmp=m_buffer;
    m_size=size;
    m_buffer = new int[m_size];
    memcpy(m_buffer,tmp, sizeof(int)*(m_top +1));
    delete[] tmp;
    return true;
}

bool Stack::GetData(int indax, int& data){
    if(index<0 || index>m_top) return false;
    data = m_buffer[indax];
    data=m_buffer[indax];
    return true;
    
}

//57p

#include <iostream>
using namespace std;

class SelfRef
{
private:
    int num;
public:
    SelfRef(int n) : num(n)
    {
        cout<<"객체생성"<<endl;
    }
    SelfRef& Adder(int n)
    {
        num+=n;
        return *this;
    }
    SelfRef& ShowTowNumber()
    {
        cout<<num<<endl;
        return *this;
    }
};

int main(void)
{
    SelfRef obj(3);
    SelfRef &ref=obj.Adder(2);

    obj.ShowTowNumber();
    ref.ShowTowNumber();

    ref.Adder(1).ShowTowNumber().Adder(2).ShowTowNumber();
    return 0;
}


#include <iostream>
using namespace std;

class Howon{
    private:
        int age;
    public:
    Howon(int age){
        this->age=age;
        cout<<"Howon::Howon(age)생성자 완료"<<endl;

    }
    void setAge(int age){
        this->age-age;
    }
    void introduce(){
        cout<<"호원의 나이는"<<age<<"세 입니다"<<endl;
    }
    Howon* returnThisPointer(){
        return this;
    }
    Howon returnThis(){
        return *this;
    }
    Howon& returnThisRef(){
        return *this;
    }
};

int main(void)
{
    Howon howon1(32);
    cout<<"howon1 객체 introduce"<<endl;
    howon1.introduce();
    howon1.setAge(50);
    howon1.introduce();

    Howon howon2(32);
    cout<<"howonPointer introduce"<<endl;
    howon2.returnThisPointer()->introduce();
    howon2.returnThisPointer()->setAge(50);
    howon2.returnThisPointer()->introduce();

    Howon howon3(32);
    cout<<"howon introduce"<<endl;
    howon3.returnThis().introduce();
    howon3.returnThis().setAge(50);
    howon3.returnThis().introduce();
    
    Howon howon4(32);
    cout<<"howonRef introduce"<<endl;
    howon4.returnThisRef().introduce();
    howon4.returnThisRef().setAge(50);
    howon4.returnThisRef().introduce();

    return 0;
}



#include <iostream>
#include <cstring>
using namespace std;

#define NAME_LEN       20
#define SEX_LEN        10
#define JOB_LEN        20
#define CHARACTER_LEN   20


class Howon{
private:
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriageStatus;

public:
    void introduce(){
        cout<<"이름: "<<name<<endl;
        cout<<"성별: "<<sex<<endl;
        cout<<"직업: "<<job<<endl;
        cout<<"성격: "<<character<<endl;
        cout<<"나이: "<<age<<endl;
        cout<<"결혼여부: "<<(marriageStatus? "YES":"NO")<<endl;
    }
    void eat(char *food){
        cout<<"호원은"<<food<<"를 먹는다"<<endl;
    }
    void sleep(){
        cout<<"호원은 잔다"<<endl;
    }
    void drive(char *destination){
        cout<<"호원은"<<destination<<"으로 운전한다"<<endl;
    }
    void write(){
        cout<<"호원은 책을 쓴다"<<endl;
    }
    void read(){
        cout<<"호원은 책을 읽는다"<<endl;
    }
    void constructor(const char* name, const char* sex, const char* job, const char* character, const int age, bool marriageStatus){
        strcpy(this->name, name);
        strcpy(this->sex, sex);
        strcpy(this->job, job);
        strcpy(this->character, character);
        this->age=age;
        this->marriageStatus=marriageStatus;
    }
};


class Younghee{
private:
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriageStatus;
public:
    void introduce(){
        cout<<"이름: "<<name<<endl;
        cout<<"성별: "<<sex<<endl;
        cout<<"직업: "<<job<<endl;
        cout<<"성격: "<<character<<endl;
        cout<<"나이: "<<age<<endl;
        cout<<"결혼여부: "<<(marriageStatus? "YES":"NO")<<endl;
    }
    void eat(char *food){
        cout<<"영희는"<<food<<"를 먹는다"<<endl;
    }
    void sleep(){
        cout<<"영희는 잔다"<<endl;
    }
    void shopping(){
        cout<<"영희는 쇼핑을 한다"<<endl;
    }

    void constructor(const char* name,const char* sex, const char* job,const char* character, const int age, bool marriageStatus){
        strcpy(this->name, name);
        strcpy(this->sex, sex);
        strcpy(this->job, job);
        strcpy(this->character, character);
        this->age=age;
        this->marriageStatus=marriageStatus;
    }
};



int main(void)
{
    Howon howon;
    Younghee younghee;
    howon.constructor("철수","남성","작가","diligent", 32, true);
    younghee.constructor("영희","여성","주부","diligent", 32, true);

    howon.drive("레스토랑");
    howon.eat("스테이크");
    younghee.eat("스테이크");
    howon.drive("집");
    younghee.sleep();
    howon.write();
    howon.read();
    howon.sleep();
    cout<<endl;
    howon.introduce();
    cout<<endl;
    younghee.introduce();
    
    return 0;
}




##include <iostream>
#include <cstring>
using namespace std;

#define NAME_LEN       20
#define SEX_LEN        10
#define JOB_LEN        20
#define CHARACTER_LEN   20

class Chulsoo{
private:
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriageStatus;
public:
    Chulsoo(const char* name, const char* sex, const char* job, const char* character, int age, bool marriageStatus){
        cout<<"Chulsoo::Chulsoo()생성자 시작"<<endl; 
        strcpy(this->name,name);
        strcpy(this->sex,sex);
        strcpy(this->job,job);
        strcpy(this->character,character);
        this->age = age;
        this->marriageStatus = marriageStatus;
        cout<<"Chulsoo::Chulsoo()생성자 완료"<<endl;
        }
        Chulsoo(){
        cout<<"Chulsoo::Chulsoo()생성자 완료"<<endl;
        }

     void introduce();
     void eat(char* food);
     void sleep();
     void drive(char* destination);
     void write();
     void read();
};


class Younghee{
private:
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriageStatus;
public:
    Younghee(const char* name, const char* sex, const char* job, const char* character, int age, bool marriageStatus){
        cout<<"Younghee::Younghee()생성자 시작"<<endl;
        strcpy(this->name,name);
        strcpy(this->sex,sex);
        strcpy(this->job,job);
        strcpy(this->character,character);
        this->age = age;
        this->marriageStatus = marriageStatus;
        cout<<"Younghee::Younghee()생성자 완료"<<endl;
        }
        Younghee(){
        cout<<"Younghee::Younghee()생성자 완료"<<endl;
        }

        void introduce();
        void eat(char* food);
        void sleep();
        void shopping();

};

class Dailylife{
private:
    Chulsoo chulsoo;
    Younghee younghee;
public:
    Dailylife(Chulsoo chulsooObject, Younghee YoungheeObject){
        cout<<"DailyLife::DailyLife(chulsooObject, YoungheeObject)생성자 시작"<<endl;
        chulsoo =chulsooObject;
        younghee = YoungheeObject;
        cout<<"DailyLife::DailyLife(chulsooObject, YoungheeObject)생성자 완료"<<endl;
    }
    void run(){
    chulsoo.drive((char*)"레스토랑");
    chulsoo.eat((char*)"스테이크");
    younghee.eat((char*)"스테이크");
    chulsoo.drive((char*)"집");
    younghee.sleep();
    chulsoo.write();
    chulsoo.read();
    chulsoo.sleep();

    cout << endl;
    chulsoo.introduce();

    cout << endl;
    younghee.introduce();
    }
};

int main(void){
    Chulsoo chulsoo("철수", "남성", "작가", "diligent", 32, true);
    Younghee younghee("영희", "여성", "주부", "impatient", 32, true);
    Dailylife dailylife(chulsoo, younghee);
    dailylife.run();
    return 0;
}

void Chulsoo::introduce(){
    cout << "이름 : " << name << endl;
    cout << "성별 : " << sex << endl;
    cout << "직업 : " << job << endl;
    cout << "캐릭터 : " << character << endl;
    cout << "나이 : " << age << endl;
    cout << "결혼여부 : " << (marriageStatus?"YES":"NO") << endl;
}
void Chulsoo::eat(char* food){
    cout << "철수는 " << food << "먹는다." << endl;
}
void Chulsoo::sleep(){
    cout << "철수는 잔다." << endl;
}
void Chulsoo::drive(char* destination){
    cout << destination << "으로 운전해라" << endl;
}
void Chulsoo::write(){
    cout << "철수는 책을 쓴다" << endl;
}
void Chulsoo::read(){
    cout << "철수는 책을 읽는다." << endl;
}


void Younghee::introduce(){
    cout << "이름 : " << name << endl;
    cout << "성별 : " << sex << endl;
    cout << "직업 : " << job << endl;
    cout << "캐릭터 : " << character << endl;
    cout << "나이 : " << age << endl;
    cout << "결혼여부 : " << (marriageStatus?"YES":"NO") << endl;
}

void Younghee::eat(char* food){
    cout << "영희는 " << food << "먹는다." << endl;
}
void Younghee::sleep(){
    cout << "영희는 잔다." << endl;
}
void Younghee::shopping(){
    cout <<"영희는 쇼핑을 한다." << endl;
}