#include "modifier_billets.h"
#include "ui_modifier_billets.h"
#include "modifier_billets.h"
#include <QMessageBox>
#include <QSound>
#include<qdebug.h>
Modifier_billets::Modifier_billets(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifier_billets)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/WSI/Desktop/projet/b.jpg");
    ui->label_10->setPixmap(pix);
}

Modifier_billets::~Modifier_billets()
{
    delete ui;
}

void Modifier_billets::on_enrigistrer_modification_clicked()
{
    int id=ui->id->text().toInt();
    QString type1=ui->type->text();
    QString classe1=ui->classe->text();
    QString datevol1=ui->datevol->text();
    int prix1=ui->prix->text().toInt();
    int numplace1=ui->numplace->text().toInt();
    int idpassager1=ui->id_passager->text().toInt();
    QString etat1=ui->etat->text();
    QString destination1=ui->destination->text();

    bool test=tmpbillet.Modifier(id,type1,classe1,datevol1,prix1,numplace1,idpassager1,etat1,destination1);
qDebug()<<"billet modifier "<<test;
QSound::play("C:/Users/WSI/Desktop/projet/b_modifier.wav");
}
