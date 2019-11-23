#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player= new QMediaPlayer(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_ajouter_clicked()
{
    player->setMedia(QUrl::fromLocalFile("G:/2019-2020/Projet C++/MON MODULE/VOLS1/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);
    ajouter ajouter;
    ajouter.setModal(true);
    ajouter.exec();
}

void MainWindow::on_supprimer_clicked()
{
    player->setMedia(QUrl::fromLocalFile("G:/2019-2020/Projet C++/MON MODULE/VOLS1/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);
    supprimer supprimer;
    supprimer.setModal(true);
    supprimer.exec();
}

void MainWindow::on_modifier_clicked()
{
    player->setMedia(QUrl::fromLocalFile("G:/2019-2020/Projet C++/MON MODULE/VOLS1/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);
    modifier modifier;
    modifier.setModal(true);
    modifier.exec();
}

void MainWindow::on_afficher_clicked()
{
    player->setMedia(QUrl::fromLocalFile("G:/2019-2020/Projet C++/MON MODULE/VOLS1/click.mp3"));
    player->play();
    qDebug()<<player->errorString();
    QThread::sleep(1);
    afficher afficher;
    afficher.setModal(true);
    afficher.exec();
}


