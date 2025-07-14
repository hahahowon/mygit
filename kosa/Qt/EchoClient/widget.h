#ifndef WIDGET_H
#define WIDGET_H
#include <QTextEdit>
#include <QLineEdit>
#include <QTcpSocket>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
private slots:
    void echoData();
    void sendData();
private:
    QTextEdit *message;
    QLineEdit *inputLine;
    QTcpSocket *clientSocket;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
