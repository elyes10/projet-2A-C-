#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <afficher.h>
#include <QPushButton>
#include <ajouter_passager.h>
#include <modifier_passager.h>
#include <supprimer_passager.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    afficher d;
    d.setModal(true);
    d.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    modifier_passager modif;
    modif.setModal(true);
    modif.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    supprimer_passager supp;
    supp.setModal(true);
    supp.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    ajouter_passager ajout;
    ajout.setModal(true);
    ajout.exec();
}
