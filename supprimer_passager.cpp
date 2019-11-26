#include "supprimer_passager.h"
#include "ui_supprimer_passager.h"
#include <QMessageBox>
supprimer_passager::supprimer_passager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer_passager)
{
    ui->setupUi(this);
}

supprimer_passager::~supprimer_passager()
{
    delete ui;
}

void supprimer_passager::on_pushButton_clicked()
{
    int cin = ui->lineEdit->text().toInt();
    bool test=tmp.supprimer(cin);
    if(test)
    {

       QMessageBox::information(nullptr, QObject::tr("Supprimer un passager"),
                       QObject::tr("passager supprimé.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un passager"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

