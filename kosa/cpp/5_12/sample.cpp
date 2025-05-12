#include <iostream>
#include <string.h>
using namespace std;

enum{
    NAME_LEN = 20,
    SEX_LEN = 10,
    JOB_LEN = 20,
    CHARACTER_LEN = 20
};

class Chulsoo{
private:
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriageStatus;
public:
    void introduce(){
        cout << "이름 : " << name << endl;
        cout << "성별 : " << sex << endl;
        cout << "직업 : " << job << endl;
        cout << "캐릭터 : " << character << endl;
        cout << "나이 : " << age << endl;
        cout << "결혼여부 : " << (marriageStatus?"YES":"NO") << endl;
    }
    void eat(const char* food){
        cout << "철수는 " << food << "먹는다." << endl;
    }
    void sleep(){
        cout << "철수는 잔다." << endl;
    }
    void drive(const char* destination){
        cout << destination << "으로 운전해라" << endl;
    }
    void write(){
        cout << "철수는 책을 쓴다" << endl;
    }
    void read(){
        cout << "철수는 책을 읽는다." << endl;
    }
    void constructor(const char* name, const char* sex, const char* job, const char* character, int age, bool marriageStatus){
        strcpy(this->name,name);
        strcpy(this->sex,sex);
        strcpy(this->job,job);
        strcpy(this->character,character);
        this->age = age;
        this->marriageStatus = marriageStatus;
    }
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
    void introduce(){
        cout << "이름 : " << name << endl;
        cout << "성별 : " << sex << endl;
        cout << "직업 : " << job << endl;
        cout << "캐릭터 : " << character << endl;
        cout << "나이 : " << age << endl;
        cout << "결혼여부 : " << (marriageStatus?"YES":"NO") << endl;
    }
    void eat(const char* food){
        cout << "영희는 " << food << "먹는다." << endl;
    }
    void sleep(){
        cout << "영희는 잔다." << endl;
    }
    void drive(const char* destination){
        cout << destination << "으로 운전해라" << endl;
    }
    void write(){
        cout << "영희는 책을 쓴다" << endl;
    }
    void read(){
        cout << "영희는 책을 읽는다." << endl;
    }
    void constructor(const char* name, const char* sex, const char* job, const char* character, int age, bool marriageStatus){
        strcpy(this->name,name);
        strcpy(this->sex,sex);
        strcpy(this->job,job);
        strcpy(this->character,character);
        this->age = age;
        this->marriageStatus = marriageStatus;
    }
};



int main(void){
    Chulsoo chulsoo;
    Younghee younghee;

    chulsoo.constructor("철수", "남성", "작가", "diligent", 32, true);
    younghee.constructor("영희", "여성", "주부", "impatient", 32, true);

    chulsoo.drive("레스토랑");
    chulsoo.eat("스테이크");
    younghee.eat("스테이크");
    chulsoo.drive("집");
    younghee.sleep();
    chulsoo.write();
    chulsoo.read();
    chulsoo.sleep();
    cout << endl;
    chulsoo.introduce();
    cout << endl;
    younghee.introduce();


    return 0;
}



