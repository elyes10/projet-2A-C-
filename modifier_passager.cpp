#include "modifier_passager.h"
#include "ui_modifier_passager.h"
#include <QMessageBox>

modifier_passager::modifier_passager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_passager)
{
    ui->setupUi(this);
}

modifier_passager::~modifier_passager()
{
    delete ui;
}

void modifier_passager::on_pushButton_clicked()
{
    int cin = ui->lineEdit->text().toInt();
    bool test=tmp.supprimer(cin);
    if(test)
    {
    int cin = ui->lineEdit_2->text().toInt();
    int age= ui->lineEdit_5->text().toInt();
    QString nom= ui->lineEdit_3->text();
    QString prenom= ui->lineEdit_4->text();

 passager b(cin,nom,prenom,age);
 b.ajouter();
    }
}


