#ifndef AJOUTER_PASSAGERR_H
#define AJOUTER_PASSAGERR_H

#include <QDialog>

namespace Ui {
class ajouter_passagerr;
}

class ajouter_passagerr : public QDialog
{
    Q_OBJECT

public:
    explicit ajouter_passagerr(QWidget *parent = nullptr);
    ~ajouter_passagerr();

private:
    Ui::ajouter_passagerr *ui;
};

#endif // AJOUTER_PASSAGERR_H
