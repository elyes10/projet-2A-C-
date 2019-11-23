#ifndef MODIFIER_BILLETS_H
#define MODIFIER_BILLETS_H
#include "billet.h"
#include <QDialog>

namespace Ui {
class Modifier_billets;
}

class Modifier_billets : public QDialog
{
    Q_OBJECT

public:
    explicit Modifier_billets(QWidget *parent = nullptr);
    ~Modifier_billets();

private slots:
    void on_enrigistrer_modification_clicked();

private:
    Ui::Modifier_billets *ui;
    billet tmpbillet;
};

#endif // MODIFIER_BILLETS_H
