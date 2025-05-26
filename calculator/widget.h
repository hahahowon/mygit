#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>

/*
+-----------------------------------------------------------------------------+
| 사용자 입력 (버튼 클릭)                                                       |
+-----------------------------------------------------------------------------+
       |                                |                 |               |
       | 숫자 키 (0-9)                  | 연산자 키       |  = 키         |  C 키
       |                                | (+, -, x, /)    |               |
       ▼                                ▼                 ▼               ▼
+-----------------------------------------------------------------------------+
| Widget 클래스 (계산기 로직 및 UI 관리)                                           |
|                                                                             |
|   +--------------------------+     +-------------------------------------+  |
|   | 멤버 변수 (상태 저장)        |     | 슬롯 및 람다 함수 (동작 처리)           |  |
|   |--------------------------|     |-------------------------------------|  |
|   | QLabel* m_label          |<----| setNum()                            |  |
|   |   (화면 표시)              |----▶|   - m_label 갱신                     |  |
|   |                          |     |   - m_isFirst = false               |  |
|   | QString m_num1           |<----|                                     |  |
|   |   (첫 번째 피연산자)        |----▶| setOp()                             |  |
|   |                          |     |   - m_num1 = m_label 값              |  |
|   | QString m_op             |<----|   - m_op = 눌린 연산자                 |  |
|   |   (선택된 연산자)           |----▶|   - m_isFirst = true                |  |
|   |                          |     |                                      |  |
|   | bool m_isFirst           |<----| '=' 버튼 람다                         |  |
|   |   (새 숫자 입력 여부)       |----▶|   - 계산 (m_num1, m_op, m_label 값)   |  |
|   |                          |     |   - m_label = 결과                    |  |
|   | (QVector<QPushButton*>   |     |   - m_isFirst = true                |  |
|   |  m_buttons - 생략)        |     |                                      |  |
|   +--------------------------+     | 'C' 버튼 람다                         |  |
|                                    |   - m_label = "0"                    |  |
|                                    |   (- m_isFirst, m_num1, m_op 초기화)  |  |
|                                    +-------------------------------------+  |
|                                                                             |
+-----------------------------------------------------------------------------+
       ▲                                ▲                 ▲               ▲
       | (시그널 발생)                  | (시그널 발생)     | (시그널 발생)   | (시그널 발생)
       |                                |                 |               |
+-----------------------------------------------------------------------------+
| m_buttons 배열 내의 각 QPushButton 객체들                                      |
+-----------------------------------------------------------------------------+

└──────────────────────┘

m_buttons는 버튼 객체 전체를 저장하고, 인덱스를 통해 시그널-슬롯 연결.

setNum(): 숫자 입력.

setOp(): 입력한 수 저장 및 연산자 기억



= 클릭 시 현재 입력된 숫자와 저장된 숫자(m_num1)를 연산하여 출력.

*/
class QLabel;//텍스트 표시용 위젯 클래스
class QPushButton;

class Widget : public QWidget
{
    Q_OBJECT            //Q_OBJECT 메크로: 사용자 정의 슬롯을 위함
                        //메타 오브젝트 코드(moc)가 생성될 수 있도록 지정
                        //qmake가 moc 컴파일러 수행할 수 있도록 함
    public:
             Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QLabel *m_label;//QLabel객체를 가리키는 포인터인 m_label을 멤버변수로 가진다.
        //화면에 텍스트 숫자, 계산결과를 표시하는 역할
    QVector<QPushButton*>m_buttons;
    //Qvector<...> : Qt의 동적배열
    //<QPushButton*> : QPushButton 객체에 대한 포인터(QPushButton 객체의 포인터를 저장하는 배열의미)
    //m_buttons : QVector 의 멤버변수 이름
    //정리: 이 QVector 클래스는 QPushButton 객체의 포인터를 여러개 저장할 수 있는 동적배열 m_button을 멤버변수로 가진다
    QString m_num1, m_op;
    bool m_isFirst;//생성자 초기화 설정
    const qint32 WIDTH = 4;
public slots:
    void setNum(); //사용자 정의 슬롯
    //접근지정자 void, slot = setNum 선언
    // -> 소스코드(.cpp)에서 구현(정의) 필요
    // widget.cpp파일에 void Widget::setNum(){}으로 함수 구현
    void setOp();// widget.cpp파일에 void Widget::setOp(){}으로 함수 구현
};
#endif // WIDGET_H
