#include "supprimer.h"
#include "ui_supprimer.h"
#include <QMessageBox>
supprimer::supprimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer)
{
    ui->setupUi(this);
}

supprimer::~supprimer()
{
    delete ui;
}

void supprimer::on_validation_accepted()
{

    int num_unique= ui->valeur1->text().toInt();
    bool test= tmpvol.supprimer(num_unique);
    if(test)
    {//ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un vol"),
                    QObject::tr("vol supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un vol"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}
