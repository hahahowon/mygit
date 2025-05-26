#include "brick.h"
#include <QPainter>
#define WIDTH   50
#define HEIGHT  12

Brick::Brick(QWidget *parent) : QWidget(parent)
{
    resize(WIDTH, HEIGHT);
    //setPixmap(QPixmap("C:\\Users\\kosa\\Documents\\BreakoutApp\\brick.png").scaled(WIDTH, HEIGHT));
    setStyleSheet("background-color:rgaba(0, 0, 0, 0)");

}

void Brick::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter p(this);
    p.setPen(QColor(Qt::transparent));
    p.setBrush(QColor(Qt::red));
    p.drawRect(0, 0, WIDTH, HEIGHT);
}
