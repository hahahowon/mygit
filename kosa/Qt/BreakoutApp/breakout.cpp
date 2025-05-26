#include "breakout.h"
#define WIDTH       50
#define HEIGHT      12
#define SCR_WIDTH   300
#define SCR_HEIGHT  400
#include <QLabel>
#include <QtMultimedia>
#include<QDebug>
//점수 넣기 추가
// 필요하다고 생각하는것  s_label -> setText(QLabel::score(result)); 스코어 레이블을 setText로 초기화
// 구현 -- 블럭 하나를 삭제할 때 마다 카운트를 통해 점수 상승
//        while문으로 블럭 갯수가 0이 될 때 까지 반복시키는 함수 만들기
/******생성자******/
Breakout::Breakout(QWidget *parent) : QWidget(parent), xDir(1), yDir(-1)
{


    s_label = new QLabel("0", this);
    s_label -> setAlignment(Qt::AlignRight | Qt::AlignVCenter);//라벨에 표시할 텍스트 정렬 설정
    s_label -> setGeometry(5, 5, 20, 20);
    /*ball*/
    ball = new Ball(this);// 수정중
    ball->setGeometry(SCR_WIDTH *0.8, SCR_HEIGHT *0.875, 10, 10);
    ball->setStyleSheet("QLabel{background-color:transparent; border-radius: 5px;}");

    /*paddle*/
    paddle = new Paddle(this);
    paddle -> setGeometry(SCR_WIDTH *0.7, SCR_HEIGHT *0.9, WIDTH, HEIGHT);
    paddle->setStyleSheet("QLabel{background-color:blue;}");
    /*벽돌 생성*/
    for(int y=0, i=0; y<5; y++){
        for(int x=0; x<6; x++, i++){
            bricks[i]= new Brick(this);
            bricks[i]->setStyleSheet("QLabel{background-color:cyan;" "border:1px solid black;}");
            bricks[i]->setGeometry(x*WIDTH, y*HEIGHT+30, WIDTH, HEIGHT );
        }
    }
    resize(SCR_WIDTH, SCR_HEIGHT);

    setMouseTracking(true);//이동감지

    timerld = startTimer(10);

    /*사운드 출력을 위한 미디어 플레이어의 초기화 배경음악*/
    QAudioOutput *bgAudioOutput = new QAudioOutput;
    bgAudioOutput->setVolume(1);

    bgPlayer = new QMediaPlayer();
    bgPlayer -> setAudioOutput(bgAudioOutput);
    bgPlayer -> setLoops(QMediaPlayer::Infinite);
    bgPlayer -> setSource(
        QUrl::fromLocalFile(QFileInfo("\\Users\\kosa\\Documents\\BreakoutApp\\background.wav").absoluteFilePath()));
    bgPlayer -> play();


    QAudioOutput *bgEffectOutput = new QAudioOutput;
    bgEffectOutput->setVolume(200);

    effectPlayer = new QMediaPlayer();
    effectPlayer -> setAudioOutput(bgEffectOutput);
    effectPlayer -> setLoops(QMediaPlayer::Once);
    effectPlayer -> setSource(
        QUrl::fromLocalFile(QFileInfo("C:\\Users\\kosa\\Downloads\\effect.mp3").absoluteFilePath()));

}

/******소멸자******/
Breakout::~Breakout()
{
    delete ball;
    delete paddle;

    for(int i=0; i<NO_OF_BRICKS; i++){
        delete bricks[i];
    }
}

void Breakout::moveObject()
{
    ball->move(ball->x()+xDir,ball->y()+yDir);
    if((ball->x()<=0)||(ball->x()+10>=SCR_WIDTH)){
            xDir*=-1;
    }
    // if(ball->y() <=0||(ball->y()+10>=SCR_HEIGHT)){
    //     yDir *= -1;
    // }
    if(ball->y() <=0) yDir = 1;//볼이 밑에 경계를 넘어가면 다시 리스타드
}



//창 안넘어가게 브레이크 구현
void Breakout::keyPressEvent(QKeyEvent *e)
{
    //키보드 경계검사 만들기
    switch (e->key()){

    case Qt::Key_Left:
        paddle->move(paddle->x()-MOVE_SPEED, paddle->y());
        break;
    case Qt::Key_Right:
        paddle->move(paddle->x()+MOVE_SPEED, paddle->y());

        break;
    case Qt::Key_Escape:
        qApp->exit();
        break;
    default:
        QWidget::keyPressEvent(e);
    }
}

void Breakout::mouseMoveEvent(QMouseEvent *e)
{
    int x= e->pos().x();
    x = (x<0) ? 0 : (WIDTH>width())?width()-WIDTH:x;
    paddle->move(x, paddle->y());
}


void Breakout::checkCollision()
{
    int result =0;
    //공 아래로 가면 종료
    if(ball->geometry().bottom()> height()){
        killTimer(timerld);
        qDebug("Game lost");
    }
    int j = 0;
    for(int i=0; i<NO_OF_BRICKS; i++){
        if(bricks[i]->isHidden()) j++;
    }
    if(j==NO_OF_BRICKS){
        killTimer(timerld);
        qDebug("Victory");
    }


    /*사용자(패들과)와 충돌 처리 */
    if((ball->geometry()).intersects(paddle->geometry())){
        int paddleLPos = paddle->geometry().left();
        int ballLPos = ball->geometry().left();
        int first= paddleLPos+8;
        int second= paddleLPos+16;
        int third= paddleLPos+24;
        int fourth= paddleLPos+32;

        if(ballLPos<first) xDir = -1; yDir = -1;
        if(ballLPos>=first&&ballLPos <second) xDir      = -1;   yDir *= -1;
        if(ballLPos>=second && ballLPos < third) xDir   = 0;  yDir  = -1;
        if(ballLPos>=third && ballLPos <fourth) xDir    = 1;    yDir *= -1;
        if(ballLPos>fourth) xDir= 1; yDir= -1;
        effectPlayer -> stop();
        effectPlayer -> play();
    }

    for(int i = 0; i < NO_OF_BRICKS; i++){
        if((ball->geometry()).intersects(bricks[i]->geometry())){
            int ballLeft = ball->geometry().left();
            int ballHeight = ball->geometry().height();
            int ballWidth = ball->geometry().width();
            int ballTop = ball->geometry().top();

            QPoint pointRight(ballLeft + ballWidth +1, ballTop);
            QPoint pointLeft(ballLeft - 1, ballTop);
            QPoint pointTop(ballLeft, ballTop-1);
            QPoint pointBottom(ballLeft, ballTop + ballHeight + 1);

            if(!bricks[i]->isHidden()){
                if(bricks[i]->geometry().contains(pointRight))   xDir = -1;
                else if(bricks[i]->geometry().contains(pointLeft))xDir=  1;
                if(bricks[i]->geometry().contains(pointTop)) yDir=  1;
                else if(bricks[i]->geometry().contains(pointBottom))  yDir = -1;
                bricks[i]->setHidden(true);
                s_label -> setText(QString::number(result));

                effectPlayer -> play();
            }
        }
    }
}

void Breakout::s_Num()
{
    //외부의 멤버변수를 사용할 수 있게 해야한다
    //s_Num에서 결과 값 계산 후 보내기,
    //checkCollision() 함수에서 써야하나..?

}


void Breakout::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    moveObject();
    checkCollision();

}

