#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "avion.h"
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    refresh();
    //ui->tabemployer->setModel(tmp.afficher_avion());
    ui->tabemployer_2->setModel(tmp.afficher_avion());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::refresh()
{
  ui->tabemployer->setModel(tmp.afficher_avion());
  ui->comboBox_3->setModel(tmp.afficher_list());
  ui->comboBox_5->setModel(tmp.afficher_list());
}

void MainWindow::on_ajouter_clicked()
{
    QString id=ui->id->text();
    QString nom=ui->nom->text();
    QString model=ui->model->text();
    QString etat=ui->etat->text();
    QString matricule=ui->matricule->text();
    if(id=="")
    {
     QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Champ vide"),QMessageBox::Ok);}
     else {

     avion e(id,nom,model,etat,matricule);
     if(!e.existe(e.getid()))
         QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("avion existe"),QMessageBox::Ok);
     else {

           bool test=e.ajouter_avion();
          ui->tabemployer->setModel(tmp.afficher_avion());
          QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("avion ajouté"),QMessageBox::Ok);


    }
}
    refresh();
}


void MainWindow::on_supprimer_clicked()
{
    QString id = ui->sup->text();
     avion e;
     e.setid(id);
     bool test=e.supprimer_avion();
     if(test)
   { ui->tabemployer->setModel(tmp.afficher_avion());
         QMessageBox::information(nullptr,QObject::tr("suppression"),QObject::tr("avion supprime"),QMessageBox::Ok);
    refresh();}
    else {
        QMessageBox::information(nullptr,QObject::tr("suppression"),QObject::tr("avion non supprime"),QMessageBox::Ok);
    }

}



void MainWindow::on_modifier_2_clicked()
{
    tmp.setnom(ui->nom_modif->text());
    tmp.setmodel(ui->model_modif->text());
    tmp.setetat(ui->etat_modif->text());
    tmp.setmatricule(ui->matricule_modif->text());
    bool test=tmp.modifier_avion();
 if(test){
    refresh();
    QMessageBox::information(nullptr,QObject::tr("modification"),QObject::tr("avion modifié"),QMessageBox::Ok);
 }else {
     QMessageBox::information(nullptr,QObject::tr("modification"),QObject::tr("avion non supprime"),QMessageBox::Ok);
 }

}


/*
void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
    tmp.setid(arg1);
    tmp.chercher();
    ui->nom->setText(tmp.getnom());
    ui->model->setText(tmp.getmodel());
    ui->etat->setText(tmp.getetat());
    ui->matricule->setText(tmp.getmatricule());
    refresh();
}
*/
void MainWindow::on_comboBox_5_activated(const QString &arg1)
{
    ui->sup->setText(arg1);
    refresh();
}



void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->tabemployer_2->setModel(tmp.recherche(arg1,etat));
    valeur=arg1;
    refresh();
}





void MainWindow::on_pushButton_8_clicked()
{
    QString id=ui->lineEdit_3->text();
    QSqlQueryModel *m;
    avion e;
    e.setid(id);
    m=e.recherche(id,0);
    ui->tabemployer_2->setModel(m);
}





void MainWindow::on_pushButton_clicked()
{

ui->tabemployer->setModel(tmp.afficher_avion());
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tabemployer->setModel(tmp.afficher_avion());
}

void MainWindow::on_radioButton_clicked()
{
    etat= 0;
    ui->tabemployer_2->setModel(tmp.recherche(valeur,etat));
    refresh();
}


void MainWindow::on_radioButton_2_clicked()
{
    etat = 1;
    ui->tabemployer_2->setModel(tmp.recherche(valeur,etat));
    refresh();
}

void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    tmp.setid(ui->comboBox_3->currentText());
    tmp.chercher();
    ui->nom_modif->setText(tmp.getnom());
    ui->model_modif->setText(tmp.getmodel());
    ui->etat_modif->setText(tmp.getetat());
    ui->matricule_modif->setText(tmp.getmatricule());
    //refresh();
}
