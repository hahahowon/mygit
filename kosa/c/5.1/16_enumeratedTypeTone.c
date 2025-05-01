//열거형 : 여러가지 것들을 나열하기 위해 사용
//코드의 가독성을 위해 숫자보다 메크로 #define 열거형을 사용하는게 좋다.
#include <stdio.h>

typedef enum syllable //typedef 선언이 추가된 열거형의 정의
{
    Do=1, Re=2, Mi=3, Fa=4, So=5, La=6,Ti=7
}Syllable;

void Sound(Syllable sy)
{
    switch(sy)
    {
        case Do:
        puts("도는 하얀 도라지"); return;
        case Re:
        puts("레는 둥근 레코드"); return;
        case Mi:
        puts("미는 파란 미나리"); return;
        case Fa:
        puts("파는 예쁜 파랑새"); return;
        case So:
        puts("솔은 작은 솔방울"); return;
        case La:
        puts("라는 라디오고요"); return;
        case Ti:
        puts("시는 졸졸 시냇물"); return;
    }
}

int main(void)
{
    Syllable tone;
    for(tone=Do; tone<=Ti;tone+=1){
        Sound(tone);
    }
    return 0;
}

//enum을 타입으로 정의할 수도 있다