#include "supprimer_billets.h"
#include "ui_supprimer_billets.h"
#include <QMessageBox>
Supprimer_Billets::Supprimer_Billets(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Supprimer_Billets)
{
    ui->setupUi(this);

    setWindowTitle("Gestion des billets");
    QPixmap pix("C:/Users/HP/Desktop/jj.jpg");
    ui->label->setPixmap(pix);
}

Supprimer_Billets::~Supprimer_Billets()
{
    delete ui;
}

void Supprimer_Billets::on_supp_billets_select_clicked()
{
    int id = ui->lineEdit->text().toInt();
    bool test=tmpbillet.supprimer(id);
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

void Supprimer_Billets::on_supp_billet_nonvalable_clicked()
{
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
