#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "avion.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    refresh();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::refresh()
{
  ui->avion->setModel(tmpavion.afficher_avion());
  ui->comboBox_3->setModel(tmpavion.afficher_list());
  ui->comboBox_5->setModel(tmpavion.afficher_list());
}

void MainWindow::on_ajouter_clicked()
{
    QString cin=ui->cin->text();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    int age=ui->age->text().toInt();
    QString matricule=ui->matricule->text();
    int num_contrat=ui->numcontart->text().toInt();
    avion e(cin,nom,prenom,matricule,age,num_contrat);
    bool test=e.ajouter_avion();

    ui->tabavion->setModel(tmpavion.afficher_avion());
    refresh();
}



void MainWindow::on_supprimer_clicked()
{
    QString cin = ui->cin->text();
     avion e;
     e.setcin(cin);
     bool test=e.supprimer_avion();
    ui->tabavion->setModel(tmpavion.afficher_avion());
    refresh();

}



void MainWindow::on_modifier_2_clicked()
{
    tmpavion.setnom(ui->nom_4->text());
    tmpavion.setprenom(ui->prenom_4->text());
    tmpavion.setmatricule(ui->matricule_4->text());
    tmpavion.setage(ui->age_4->text().toInt());
    tmpavion.setnumcontrat(ui->num_contrat->text().toInt());

    bool test=tmpavion.modifier_avion();
 if(test){
    refresh();
}

}



void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
    tmpavion.setcin(arg1);
    tmpavion.chercher();
    ui->nom_4->setText(tmpavion.getnom());
    ui->prenom_4->setText(tmpavion.getprenom());
    ui->matricule_4->setText(tmpavion.getmatricule());
    ui->age_4->setText(QString::number(tmpavion.getage()));
    ui->num_contrat->setText(QString::number(tmpavion.getnumcontrat()));
    refresh();


}

void MainWindow::on_comboBox_5_activated(const QString &arg1)
{
    ui->sup->setText(arg1);
    refresh();
}



void MainWindow::on_lineEdit_19_textChanged(const QString &arg1)
{
    ui->tabavion->setModel(tmpavion.recherche(arg1,etat));
    valeur=arg1;
    refresh();
}



void MainWindow::on_checkBox_2_stateChanged(int arg1)
{

    etat=arg1;
    ui->tabavion->setModel(tmpavion.recherche(valeur,etat));
    refresh();
}
