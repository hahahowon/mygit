#include "widget.h"
#include <QLabel>
#include <QPushButton>


Widget::Widget(QWidget *parent) : QWidget(parent), m_isFirst(true)//m_isFirst(true): 멤버 변수 초기화 리스트를 통해 true값이면 초기화.
{
    m_label =new QLabel("0", this);
    //Qlabel을 heap 메모리에 동적 생성, 초기 텍스트 "0", 부모위젯을 자기 자신으로 설정
    m_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);//라벨에 표시할 텍스트 정렬 설정
    m_label->setGeometry(10, 5, 230, 40);// 라벨의 위치 및 크기 설정

    const char ButtonChar[16][2]={
        "7", "8", "9", "/",
        "4", "5", "6", "x",
        "1", "2", "3", "-",
        "0", "C", "=", "+",
    };
    /* WIDTH = 4 */
    for(int y=0; y<WIDTH; y++){//세로 반복줄
        for(int x=0; x<WIDTH; x++){//가로 반복줄
            m_buttons.append(new QPushButton(ButtonChar[x+y*WIDTH], this));
            // m_buttons.append(...): 생성된 QPushButton 객체의 포인터를 m_buttons라는 QVector(동적 배열)에 추가
            //[x + y * WIDTH] : 2차원 좌표 (x, y)를 1차원 배열 ButtonChar의 인덱스로 변환
            m_buttons.at(x+y*WIDTH)->setGeometry(5+60*x, 50+60*y, 60, 60);
        }
    }

    connect(m_buttons.at(0),SIGNAL(clicked()), this, SLOT(setNum()));// 수신받는 객체가 자기 자신인 this일 경우 생략 가능
    //connect(시그널 보내느 객체 포인터, 보낼 시그널의 시그니처, 슬롯을 받는 객체의 포인터(여기서는 자기 자신), 받을 슬롯의 시그니처(여기서는 setNum슬롯이 호출된다))
    connect(m_buttons.at(1),SIGNAL(clicked()), SLOT(setNum()));// connet()함수를 사용해서 시그널과
    connect(m_buttons.at(2),SIGNAL(clicked()), SLOT(setNum()));// 사용자 정의 슬롯 setNum 연결
    connect(m_buttons.at(4),SIGNAL(clicked()), SLOT(setNum()));
    connect(m_buttons.at(5),SIGNAL(clicked()), SLOT(setNum()));
    connect(m_buttons.at(6),SIGNAL(clicked()), SLOT(setNum()));
    connect(m_buttons.at(8),SIGNAL(clicked()), SLOT(setNum()));
    connect(m_buttons.at(9),SIGNAL(clicked()), SLOT(setNum()));
    connect(m_buttons.at(10),SIGNAL(clicked()), SLOT(setNum()));
    connect(m_buttons.at(12),SIGNAL(clicked()), SLOT(setNum()));

    connect(m_buttons.at(13),&QPushButton::clicked, this, [=](){m_label->setText("0");});
    //Qt5 이상에서 사용가능한 람다 표현식
    //
    connect(m_buttons.at(3),SIGNAL(clicked()), SLOT(setOp()));// connet()함수를 사용해서 시그널과
    connect(m_buttons.at(7),SIGNAL(clicked()), SLOT(setOp()));// 사용자 정의 슬롯 setOp 연결
    connect(m_buttons.at(11),SIGNAL(clicked()), SLOT(setOp()));
    connect(m_buttons.at(15),SIGNAL(clicked()), SLOT(setOp()));

    connect(m_buttons.at(14), &QPushButton::clicked, this, [this](){//계산 식 구현(람다함수 사용)
        //[this] this포인터를 캡처하여 람다 함수 내에서 widget클래스 내의 멤버변수들을 접근할 수 있게 함
        qreal result =0; //계산 결과 result를 qreal type으로 선언하고 0으로 초기화
        m_isFirst = true;//C 버튼: 생성자 초기화
        if(m_op =="+")//m_op에 저장된 연산자가 +인지 확인
            result = m_num1.toDouble()+ m_label->text().toDouble();
        //첫 번째 입력된 숫자 m_num1(double type)와 라벨에 표기된 숫자(double type)을 연산한 값 = result
        else if(m_op =="-")//m_op에 저장된 연산자가 -인지 확인
            result = m_num1.toDouble()- m_label->text().toDouble();
        else if(m_op =="x")//m_op에 저장된 연산자가 x인지 확인
            result = m_num1.toDouble()* m_label->text().toDouble();
        else if(m_op =="/"){//m_op에 저장된 연산자가 /인지 확인
            if(m_label->text().toDouble()){//0으로 나누는 경우 error 처리를 위한 if문 선언
                result = m_num1.toDouble()/ m_label->text().toDouble();
            }else{
                m_label->setText("Error:Cannot Divide by Zero");//0으로 나누는 경우 에러 처리
                return;

            }
        }
        m_label->setText(QString::number(result));
        // setText qreal type의 result를 QString으로 변환 -> 라벨에 변환된 문자열 표기(setText),

    });
    setMinimumSize(250, 295);
    setMaximumSize(250, 295);
    setWindowTitle("Calculator");
}

Widget::~Widget() {
    delete m_label;
    m_buttons.clear();
    //Q_FOREACH(auto b, m_buttons)delete b;
}

void Widget::setNum(){ //사용자 정의 슬롯 정의 및 구현(일반 멤버 함수처럼 구현)
    QPushButton *button = dynamic_cast<QPushButton*>(sender());
    //다운캐스팅을 통해 부모 클래스 포인터가 실제로 특정 자식 클래스 객체를 가리키는지 확인(다형성)
    //sender()를 통해 누른 버튼 객체 확인
    QString bStr;//버튼 텍스트 추출
    if(button != nullptr){  //*C++11 이후 0 대신 nullptr 사용, 캐스팅 성공 확인용 문장
        bStr = button->text();
    }
    if(m_label != nullptr){
        QString lStr = m_label->text();//라벨 텍스트 추출
        m_label->setText((lStr == "0" | m_isFirst) ? bStr : lStr+bStr);
        //m_label이 "0"이거나 m_isFirst가 true면, 버튼 텍스트로 m_label의 초기값인 "0"으로 덮어씀.
        //아니라면 라벨텍스트 뒤에 버튼에서 입력된 텍스트를 추가하여 라벨에 출력
        m_isFirst = false;//그리고 false로 설정하여 초기화 x
    }
}

void Widget::setOp(){// 연산자 버튼이 눌리면 호출
    QPushButton *button = dynamic_cast<QPushButton*>(sender());
    if(button != nullptr){//연산자 버튼에 표시된 텍스트를 m_op 멤버변수에 저장(저장된 연산자 텍스트는 위의 계산식에서 문자 비교를 통해 동일한 문자의 연산 수행
        m_op = button->text();
        //연산자 버튼에 표시된 텍스트를 m_op 멤버변수에 저장

    }
    if(m_label != nullptr){
        m_op = button -> text();
    }
    if(m_label != nullptr){
        m_num1 = m_label -> text();//연산자 버튼을 눌렀을 때 라벨에 표시된 숫자 m_num1에 저장
        m_isFirst = true;// 두 번째 피연산자 입력을 위한 라벨 초기화
    }
}
//반복연산 하면 결과값이 이상함
