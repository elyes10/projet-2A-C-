#include "afficher.h"
#include "ui_afficher.h"
#include "vols.h"
#include "ajouter.h"
afficher::afficher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afficher)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpvol.afficher());//refresh
}

afficher::~afficher()
{
    delete ui;
}

void afficher::on_pushButton_2_clicked()
{

}

void afficher::on_pushButton_clicked()
{


    QString num_unique= ui->valeur1->text();
    ui->tableView->setModel(tmpvol.afficherparnum(num_unique));

}
