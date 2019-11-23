#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowTitle("Gestion des billets");
    QPixmap pix("C:/Users/HP/Desktop/jj.jpg");
    ui->label->setPixmap(pix);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_affichier_clicked()
{
    ui->tableView->setModel(tmpbillet.afficher());
}






void Dialog::on_pushButton_clicked()
{  QString idd=ui->id->text();
   ui->tableView->setModel(tmpbillet.afficher_par_id(idd));
}
