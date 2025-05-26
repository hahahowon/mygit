#ifndef BRICK_H
#define BRICK_H

#include <QLabel>
#include <QWidget>
class QLabel;

class Brick : public QWidget
{
       Q_OBJECT
public:
   Brick(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent*)override;


};

#endif // BRICK_H
