#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "avion.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void refresh();

private slots:
    void on_ajouter_clicked();



    void on_supprimer_clicked();

    void on_modifier_2_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_5_activated(const QString &arg1);

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    avion tmp;
    int etat=0;
    QString valeur = "",a;
};
#endif // MAINWINDOW_H
