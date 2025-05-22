#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QDir;
class QListWidget;
class QListWidgetItem;
class QLineEdit;
class QTextEdit;
class QMenu;
class QContextMenuEvent;



class Widget : public QWidget
{
    Q_OBJECT
protected:
    /*Context 메뉴를 위한 이벤트 헨들러*/
    void contextMenuEvent(QContextMenuEvent*);
private:
    void refreshDir();
    QDir *directory;
    QListWidget *dirListWidget;
    QLineEdit *filenameLineEdit;
    QTextEdit *outputEdit;
    QMenu *m_menu;

public slots:
    void selectItem(QListWidgetItem*);
    void changeDir();
    void copyFile();
    void makeDir();
    void removeDir();
    void renameDir();


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

};


#endif // WIDGET_H
