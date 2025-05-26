#ifndef PADDLE_H
#define PADDLE_H
#include <QLabel>
#include <QWidget>
class QWidget;

class Paddle : public QWidget
{
       Q_OBJECT
public:
   Paddle(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent*)override;
};

#endif // PADDLE_H
