#ifndef DIALOG_H
#define DIALOG_H
#include <QDebug>
#include <QDialog>
#include"billet.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_affichier_clicked();



    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    billet tmpbillet;
};

#endif // DIALOG_H
