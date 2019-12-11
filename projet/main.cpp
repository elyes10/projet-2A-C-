#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connexion c;
    try {
          bool t= c.ouvrirConnexion();
           qDebug()<<"hhhhhh"<<t;
           w.show();
       } catch (QString s) {
           qDebug()<<s;

       }

    return a.exec();
}
