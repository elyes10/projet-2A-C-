#include "ajouter_billets.h"
#include "ui_ajouter_billets.h"
#include"billet.h"
#include <QMessageBox>
#include <QSound>
#include <QDebug>
Ajouter_billets::Ajouter_billets(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajouter_billets)
{
    ui->setupUi(this);
    setWindowTitle("Gestion des billets");

}

Ajouter_billets::~Ajouter_billets()
{
    delete ui;
}


void Ajouter_billets::on_ajouter_clicked()
{
   int id = ui->lineEdit_id->text().toInt();
   int numplace = ui->lineEdit_numplace->text().toInt();
   int idpassager = ui->lineEdit_idpassager->text().toInt();
   int prix= ui->lineEdit_prix->text().toInt();
   QString destination= ui->lineEdit_destination->text();
   QString datevol= ui->lineEdit_datevol->text();
   QString type= ui->lineEdit_type->text();
   QString classe= ui->lineEdit_classe->text();
   QString etat= ui->lineEdit_10->text();

   QSqlQuery q;
   QString res= QString::number(id);
    q.prepare("SELECT COUNT (*) FROM BILLETS where id = :id");
            q.bindValue(":id", res);
    q.exec();
    int unique= 0;
    if (q.next()) {
           unique= q.value(0).toInt();
 qDebug()<<"unique"<<unique;
    }

  if(unique==0)

  {
billet b(id,destination,datevol,type,classe,numplace,idpassager,prix,etat);
bool test=b.ajouter();
if(test)
{    QSound::play("C:/Users/WSI/Desktop/projet/b_ajouter.wav");
    QMessageBox::information(nullptr, QObject::tr("Ajouter une billet"),
                      QObject::tr("billet ajouté.\n"
                                  ), QMessageBox::Ok);
}
else
    QMessageBox::critical(nullptr, QObject::tr("Ajouter une billett"),
                     QObject::tr("Erreur !.\n"
                                 ), QMessageBox::Ok);
  }else
     if(unique!=0) {QSound::play("C:/Users/WSI/Desktop/projet/idexiste.wav");
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une billett"),
                       QObject::tr("ID de billet existe \n"
                                   "billet non ajouté\n"), QMessageBox::Ok);
}
}
