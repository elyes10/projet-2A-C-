#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QSound>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowTitle("Gestion des billets");
    QPixmap pix("C:/Users/HP/Desktop/jj.jpg");
    ui->label->setPixmap(pix);
    ui->tableView->setModel(tmpbillet.afficher());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_affichier_clicked()
{QSound::play("C:/Users/WSI/Desktop/projet/click.wav");
    ui->tableView->setModel(tmpbillet.afficher());
}








void Dialog::on_lineEdit_textChanged(const QString &arg1)
{

           if (arg1=="")
        ui->tableView->setModel(tmpbillet.afficher());
        else
        this->ui->tableView->setModel(tmpbillet.afficher_par_id(arg1));
    }

