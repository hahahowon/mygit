#include "widget.h"

#include <QDir>
#include <QFile>
#include <QListWidget>
#include <QLineEdit>
#include <QFileInfo>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QMenu>
#include <QContextMenuEvent>
#include <QApplication>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    directory = new QDir(".");// 현재 디렉토리의 내용을 저장하는 객체
    /*메뉴를 위한 액션 정의*/


    QAction*mkdirAction=new QAction("&Make Directory", this);
    connect(mkdirAction,SIGNAL(triggered()),this, SLOT(makeDir()));//세 번째 인자인 디스는 생략 가능

    QAction*copyAction=new QAction("&Copy", this);
    connect(copyAction,SIGNAL(triggered()), SLOT(copyDir()));

    QAction*removeAction=new QAction("&Remove", this);
    connect(removeAction,SIGNAL(triggered()), SLOT(removeDir()));

    QAction*renameAction=new QAction("&Rename", this);
    connect(renameAction,SIGNAL(triggered()), SLOT(renameDir()));

    QAction*quitAction=new QAction("&Quit", this);
    connect(quitAction,SIGNAL(triggered()), SLOT(quitDir()));

    /*액션을 메뉴에 추가*/
    m_menu= new QMenu(this);
    m_menu->addSection("&Directory");
    m_menu->addAction(mkdirAction);
    m_menu->addSeparator();
    m_menu->addSection(("&File"));
    m_menu->addAction(copyAction);
    m_menu->addSeparator();
    m_menu->addAction(quitAction);


    /*화면표시 위젯 정의 레이아웃*/

    dirListWidget=new QListWidget(this);
    filenameLineEdit = new QLineEdit(this);

    outputEdit = new QTextEdit(this);
    outputEdit->setReadOnly(true);

    QPushButton *actionButton = new QPushButton("Action",this);
    actionButton ->setMenu(m_menu);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(dirListWidget);
    layout->addWidget(filenameLineEdit);
    layout->addWidget(actionButton);
    layout->addWidget(outputEdit);

    /*시그널 슬롯 연결*/

    connect(dirListWidget, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(selectItem(QListWidgetItem*)));
    connect(dirListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), SLOT(changeDir()));
    refreshDir();

}

Widget::~Widget() {}

void Widget::refreshDir()//디렉토리 갱신
{
    dirListWidget->clear();//현재 QListWidget의 내용을 모두 삭제
    /*QDir 클래스에 저장된 현재 파일의 목록을 QListWidget에 아이템으로 추가*/
    for(int index=0; index<directory->entryList().count();index++){
        dirListWidget->addItem(directory->entryList().at(index));
    }
}
/*마우스 더블클릭 컨텍스트 메뉴 표시*/
void Widget::selectItem(QListWidgetItem* item){
    filenameLineEdit->setText(item->text());
}
/*파일 복사*/
void Widget::copyFile(){
    QString filename = directory->absoluteFilePath(
        dirListWidget->currentItem()->text());

    QFileInfo checkDir(filename);
    if(checkDir.isFile()&&filenameLineEdit->text().length()){
        QString newFile = directory->absoluteFilePath(filenameLineEdit->text());
        QFile::copy(filename, newFile);
    }
    directory->refresh();
    refreshDir();
}

/*QListWidget을 더블클릭하면 호출*/
void Widget::changeDir(){
    /*현재파일의 경로를 절대 경로로 변경*/
    QString filename = directory->absoluteFilePath(dirListWidget->currentItem()->text());
    QFileInfo checkDir(filename);
    if(checkDir.isDir()){
        directory->cd(filename);
        directory->refresh();
    }
}









