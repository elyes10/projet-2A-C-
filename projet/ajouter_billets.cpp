#include "ajouter_billets.h"
#include "ui_ajouter_billets.h"
#include"billet.h"
#include <QMessageBox>
#include <QSound>
Ajouter_billets::Ajouter_billets(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajouter_billets)
{
    ui->setupUi(this);
    setWindowTitle("Gestion des billets");
    QPixmap pix("C:/Users/WSI/Desktop/projet/b.jpg");
    ui->label_2->setPixmap(pix);
}

Ajouter_billets::~Ajouter_billets()
{
    delete ui;
}


void Ajouter_billets::on_ajouter_clicked()
{QSound::play("C:/Users/WSI/Desktop/projet/click.wav");
   int id = ui->lineEdit_id->text().toInt();
   int numplace = ui->lineEdit_numplace->text().toInt();
   int idpassager = ui->lineEdit_idpassager->text().toInt();
   float prix= ui->lineEdit_prix->text().toInt();
   QString destination= ui->lineEdit_destination->text();
   QString datevol= ui->lineEdit_datevol->text();
   QString type= ui->lineEdit_type->text();
   QString classe= ui->lineEdit_classe->text();
   QString etat= ui->lineEdit_10->text();
billet b(id,destination,datevol,type,classe,numplace,idpassager,prix,etat);
bool test=b.ajouter();
if(test)
{
    QMessageBox::information(nullptr, QObject::tr("Ajouter une billet"),
                      QObject::tr("billet ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("Ajouter une billett"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}
