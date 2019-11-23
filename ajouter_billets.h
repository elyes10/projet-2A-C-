#ifndef AJOUTER_BILLETS_H
#define AJOUTER_BILLETS_H

#include <QDialog>

namespace Ui {
class Ajouter_billets;
}

class Ajouter_billets : public QDialog
{
    Q_OBJECT

public:
    explicit Ajouter_billets(QWidget *parent = nullptr);
    ~Ajouter_billets();

private slots:
    void on_annuler_clicked();



    void on_ajouter_clicked();

private:
    Ui::Ajouter_billets *ui;
};

#endif // AJOUTER_BILLETS_H
