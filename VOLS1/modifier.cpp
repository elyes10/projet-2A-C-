#include "modifier.h"
#include "ui_modifier.h"
#include "vols.h"
#include <QMessageBox>

modifier::modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier)
{
    ui->setupUi(this);
}

modifier::~modifier()
{
    delete ui;
}

void modifier::on_validation_accepted()
{
   /* action_effectue action_effectue;
    action_effectue.setModal(true);
    action_effectue.exec();*/

    int num_unique= ui->valeur1->text().toInt();
    QString dest_depart1= ui->valeur2_2->text();
    QString dest_arrive1= ui->valeur3_2->text();
    QString date_depart1= ui->valeur4_2->text();
    QString date_arrive1= ui->valeur5_2->text();
    QString dure_vol1=ui->valeur6_2->text();
    int nbr_passagers1=ui->valeur7_2->text().toInt();



       bool test=tmpvol.Modifier(num_unique,dest_depart1,dest_arrive1,date_depart1,date_arrive1,dure_vol1,nbr_passagers1);

        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Modifier un vol"),
                          QObject::tr("Vol modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
            else
              QMessageBox::critical(nullptr, QObject::tr("Modifier un vol"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


}
