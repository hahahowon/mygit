#include <iostream>

using namespace std;

void plus1(int n) { n++; }
void plus2(int &n) { n+=2; }
//void plus3(const int n) { n+=3; }
//void plus4(const int &n) { n+=4; }
int main(void)
{
  int num1 = 1;
  plus1(num1); cout << "1 : " << num1 << endl;
  plus2(num1); cout << "2 : " << num1 << endl;
  //plus3(num1); cout << "3 : " << num1 << endl;
  //plus4(num1); cout << "4 : " << num1 << endl;
  return 0;
}

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
