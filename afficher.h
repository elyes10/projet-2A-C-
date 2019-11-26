#ifndef AFFICHER_H
#define AFFICHER_H
#include <QDebug>
#include <QDialog>
#include"passager.h"


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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::afficher *ui;
     passager tmp;
};

#endif // AFFICHER_H
