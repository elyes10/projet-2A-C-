#include "supprimer_billets.h"
#include "ui_supprimer_billets.h"
#include <QMessageBox>
#include <QSound>
#include <qdebug.h>
#include "notification.h"
Supprimer_Billets::Supprimer_Billets(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Supprimer_Billets)
{
    ui->setupUi(this);
ui->tableView->setModel(tmpbillet.afficher());
    setWindowTitle("Gestion des billets");
  QPixmap pix("C:/Users/WSI/Desktop/projet/b.jpg");
    ui->label_2->setPixmap(pix);
}

Supprimer_Billets::~Supprimer_Billets()
{
    delete ui;
}

void Supprimer_Billets::on_supp_billets_select_clicked()
{
    int id = ui->lineEdit->text().toInt();
    QSqlQuery q;
    QString res= QString::number(id);
     q.prepare("SELECT COUNT (*) FROM BILLETS where id = :id");
             q.bindValue(":id", res);
     q.exec();
     int existe= 0;
     if (q.next()) {
            existe= q.value(0).toInt();
  qDebug()<<"existance"<<existe;
     }


    bool test=tmpbillet.supprimer(id);
    if(test and (existe!=0))
    {QSound::play("C:/Users/WSI/Desktop/projet/b_supp.wav");
       ui->tableView->setModel(tmpbillet.afficher());
       QMessageBox::information(nullptr, QObject::tr("Supprimer un billet"),
                       QObject::tr("billet supprimé.\n"
                                   ""), QMessageBox::Ok);
       QString okd="";
        notification ok;
        ok.notification_sup_billet(okd);

    }
    else
       if(existe==0){
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un billet"),
                    QObject::tr("id nexiste pas\n"
                                ""), QMessageBox::Ok);}
}

void Supprimer_Billets::on_supp_billet_nonvalable_clicked()
{QSound::play("C:/Users/WSI/Desktop/projet/click.wav");
    bool test=tmpbillet.supprimer_tout();
    if(test)
    {
       ui->tableView->setModel(tmpbillet.afficher());
       QMessageBox::information(nullptr, QObject::tr("Supprimer un billet"),
                       QObject::tr("billet supprimé.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un billet"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
