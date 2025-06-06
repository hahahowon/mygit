#ifndef BREAKOUT_H
#define BREAKOUT_H

#include "ball.h"
#include "brick.h"
#include "paddle.h"
#include <QWidget>
#include <QMouseEvent>
#include <QkeyEvent>
#include <QMediaPlayer>//사운드 추가
class QLabel;
class QWidget;
class Breakout : public QWidget
{

    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent*) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void timerEvent(QTimerEvent*) override;
    void moveObject();
    void checkCollision();//bool 값으로 교집합 있는지 알려줌
    void s_Num(); // score 점수 구현

protected:
    static const int MOVE_SPEED = 3;  //패들의 이동 속도

private:
    static const int NO_OF_BRICKS = 30;
    int timerld;
    int xDir, yDir;
    QLabel *ball;
    QLabel *paddle;
    QLabel *bricks[NO_OF_BRICKS];

    QLabel *s_label;
    QString *score;

    QMediaPlayer *bgPlayer;
    QMediaPlayer *effectPlayer;
public:
    Breakout(QWidget *parent = nullptr);
    ~Breakout();
};
#endif // BREAKOUT_H
