#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <dialog.h>
#include <QPushButton>
#include <ajouter_billets.h>
#include <modifier_billets.h>
#include <supprimer_billets.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  setWindowTitle("Gestion des billets");
  QPixmap pix("C:/Users/HP/Desktop/tt.jpg");
  ui->label->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Affichiermain_clicked()
{
  Dialog d;
  d.setModal(true);
  d.exec();
}

void MainWindow::on_modifiermain_clicked()
{
  Modifier_billets modif;
  modif.setModal(true);
  modif.exec();
}

void MainWindow::on_supprimermain_clicked()
{
 Supprimer_Billets supp;
 supp.setModal(true);
 supp.exec();
}

void MainWindow::on_ajoutermain_clicked()
{
  Ajouter_billets ajout;
  ajout.setModal(true);
  ajout.exec();
}
