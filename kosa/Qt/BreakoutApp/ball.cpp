#include <QPainter>
#include "ball.h"

#define RADIUS         10
Ball::Ball(QWidget *parent) : QWidget(parent)
{
    resize(RADIUS, RADIUS);
    //setPixmap(QPixmap("C:\\Users\\kosa\\Documents\\BreakoutApp\\ball.png").scaled(10, 10));
    setStyleSheet("background-color:rgaba(0, 0, 0, 0)");

}

void Ball::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter p(this);
    p.setPen(QColor(Qt::transparent));
    p.setBrush(QColor(Qt::red));
    p.drawEllipse(0, 0, RADIUS, RADIUS);
}
