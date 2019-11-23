#ifndef AFFICHER_H
#define AFFICHER_H
#include"vols.h"
#include <QDialog>

namespace Ui {
class afficher;
}

class afficher : public QDialog
{
    Q_OBJECT

public:
    explicit afficher(QWidget *parent = nullptr);
    ~afficher();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::afficher *ui;
    vols tmpvol;
};

#endif // AFFICHER_H

