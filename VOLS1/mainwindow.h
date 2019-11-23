#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "connection.h"
#include"action_effectue.h"
#include <QMainWindow>
#include "modifier.h"
#include "afficher.h"
#include "ajouter.h"
#include "supprimer.h"
#include <QMediaPlayer>
#include <QDebug>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_afficher_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
};
#endif // MAINWINDOW_H
