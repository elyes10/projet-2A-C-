#include "ajouter_passager.h"
#include "ui_ajouter_passager.h"
#include"passager.h"
#include <QMessageBox>

ajouter_passager::ajouter_passager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter_passager)
{
    ui->setupUi(this);
}

ajouter_passager::~ajouter_passager()
{
    delete ui;
}

void ajouter_passager::on_pushButton_clicked()
{

}

void ajouter_passager::on_pushButton_2_clicked()
{
    int cin = ui->lineEdit->text().toInt();
    int age= ui->lineEdit_4->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString prenom= ui->lineEdit_3->text();

 passager b(cin,nom,prenom,age);
 bool test=b.ajouter();
 if(test)
 {
     QMessageBox::information(nullptr, QObject::tr("Ajouter un passager"),
                       QObject::tr("passager ajouté.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
 }
 else
     QMessageBox::critical(nullptr, QObject::tr("Ajouter un passager"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}
