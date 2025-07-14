#include "widget.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTreeWidget treeWidget;
    treeWidget.setColumnCount(2);
    treeWidget.setHeaderLabels(QStringList()<<"Col One"<<"Col Two");

    for(int i = 0; i<3; i++){
        QTreeWidgetItem *pItem = new QTreeWidgetItem(&treeWidget);
        pItem->setText(0, QString::number(i));
        pItem->setText(1, "Hello");
        //->treeWidget->addTopLevelItem(pItem); 이렇게 가능
        for(int j = 0; j < 3; j++){
            QTreeWidgetItem *itm = new QTreeWidgetItem(pItem);
            itm->setText(0, QString::number(j));
            itm->setText(1, "world");
            //pItem->addChild(itm); 부모 자식으로 추가 가능
        }
    }
    treeWidget.resize(250,180);
    treeWidget.show();

    return a.exec();
}
