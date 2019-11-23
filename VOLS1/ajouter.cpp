#include "ajouter.h"
#include "ui_ajouter.h"
#include "vols.h"
#include <QMessageBox>

ajouter::ajouter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter)
{
    ui->setupUi(this);
    //ui->TableWidget->setModel(tmpvol.afficher());
   // QPixmap pix("G:/2019-2020/Projet C++/VALIDATION 3 (QT +CAS D'UTILISATION)/vols/ressources pour app qt/ajout/téléchargé.png");
   // ui->
}

ajouter::~ajouter()
{
    delete ui;
}

void ajouter::on_validation_accepted()
{
    int num_unique= ui->valeur1->text().toInt();
    QString dest_depart= ui->valeur2->text();
    QString dest_arrive= ui->valeur3->text();
    QString date_depart= ui->valeur4->text();
    QString date_arrive= ui->valeur5->text();
    QString dure_vol=ui->valeur6->text();
    int nbr_passagers=ui->valeur7->text().toInt();

   vols v(num_unique,dest_depart,dest_arrive,date_depart,date_arrive,dure_vol,nbr_passagers);
   bool test=v.ajouter();
   if (test)
   {
       QMessageBox::information(nullptr, QObject::tr("Ajouter un vol"),
                     QObject::tr("Vol ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter un vol"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);


}



