#include "afficher.h"
#include "ui_afficher.h"
#include <QDebug>

afficher::afficher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afficher)
{
    ui->setupUi(this);
}

afficher::~afficher()
{
    delete ui;
}

void afficher::on_pushButton_clicked()
{
    QString CIN=ui->lineEdit->text();
      ui->tableView->setModel(tmp.afficher_par_cin(CIN));
}

void afficher::on_pushButton_2_clicked()
{
    ui->tableView->setModel(tmp.afficher());
}


