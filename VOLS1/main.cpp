#include "mainwindow.h"
#include "connection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection c;
    try {
       bool t= c.ouvrirconnetion();
        qDebug()<<"hhhhhh"<<t;
    w.show();
        }
    catch(QString s)
    {
        qDebug()<<s;
    }

    return a.exec();
}
