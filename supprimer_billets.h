#ifndef SUPPRIMER_BILLETS_H
#define SUPPRIMER_BILLETS_H

#include <QDialog>
#include "billet.h"
namespace Ui {
class Supprimer_Billets;
}

class Supprimer_Billets : public QDialog
{
    Q_OBJECT

public:
    explicit Supprimer_Billets(QWidget *parent = nullptr);
    ~Supprimer_Billets();

private slots:
    void on_supp_billets_select_clicked();

    void on_supp_billet_nonvalable_clicked();

private:
    Ui::Supprimer_Billets *ui;
    billet tmpbillet;
};

#endif // SUPPRIMER_BILLETS_H
