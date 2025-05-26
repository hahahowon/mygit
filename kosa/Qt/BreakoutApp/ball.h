#ifndef BALL_H
#define BALL_H

#include <QLabel>
#include <QWidget>
class QLabel;

class Ball: public QWidget
{       Q_OBJECT
public:
   Ball(QWidget *parent = nullptr);
private:
   void paintEvent(QPaintEvent*)override;
};

#endif // BALL_H
