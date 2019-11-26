#include "ajouter_passagerr.h"
#include "ui_ajouter_passagerr.h"
#include "passager.h"
#include <QMessageBox>
ajouter_passagerr::ajouter_passagerr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter_passagerr)
{
    ui->setupUi(this);

      setWindowTitle("Gestion des passagers");
      ui->label_2->setPixmap(pix);
}

ajouter_passagerr::~ajouter_passagerr()
{
    delete ui;
}
