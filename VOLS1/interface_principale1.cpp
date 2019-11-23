#include "interface_principale1.h"
#include "ui_interface_principale1.h"
#include "mainwindow.h"
#include <QDialog>
interface_principale1::interface_principale1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interface_principale1)
{
    ui->setupUi(this);
}

interface_principale1::~interface_principale1()
{
    delete ui;
}

void interface_principale1::on_pushButton_clicked()//GESTION VOLS

{
    MainWindow mainwindow;
    //mainwindow.setModal(true);
    //mainwindow.exec();
}

void interface_principale1::on_pushButton_2_clicked()//GESTION BILLETS

{

}

void interface_principale1::on_pushButton_3_clicked()//GESTION AVIONS

{

}

void interface_principale1::on_pushButton_4_clicked()//GESTION AGENTS

{

}

void interface_principale1::on_pushButton_5_clicked()//GESTION PASSAGERS
{

}
