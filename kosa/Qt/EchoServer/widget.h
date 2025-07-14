#ifndef WIDGET_H
#define WIDGET_H
#include <QLabel>
#include <QTcpServer>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);

private slots:
    void clientConnect();
    void echoData();
    void userlist();
private:
    QLabel *infoLabel;
    QTcpServer *tcpServer;
    void incomingConnection(int socketfd);
};
#endif // WIDGET_H
