#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <dialog.h>
#include <QPushButton>
#include <ajouter_billets.h>
#include <modifier_billets.h>
#include <supprimer_billets.h>
#include <statistiques.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  setWindowTitle("Gestion des billets");
  QPixmap pix("C:/Users/WSI/Desktop/projet/b.jpg");
  ui->label->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Affichiermain_clicked()
{ QSound::play("C:/Users/WSI/Desktop/projet/click.wav");
  Dialog d;
  d.setModal(true);
  d.exec();
}

void MainWindow::on_modifiermain_clicked()
{ QSound::play("C:/Users/WSI/Desktop/projet/click.wav");
  Modifier_billets modif;
  modif.setModal(true);
  modif.exec();
}

void MainWindow::on_supprimermain_clicked()
{ QSound::play("C:/Users/WSI/Desktop/projet/click.wav");
 Supprimer_Billets supp;
 supp.setModal(true);
 supp.exec();
}

void MainWindow::on_ajoutermain_clicked()
{QSound::play("C:/Users/WSI/Desktop/projet/click.wav");
  Ajouter_billets ajout;
  ajout.setModal(true);
  ajout.exec();
}

void MainWindow::on_pushButton_clicked()
{QSound::play("C:/Users/WSI/Desktop/projet/click.wav");
    statistiques stat;
    stat.setModal(true);
    stat.exec();
}
