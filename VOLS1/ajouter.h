#ifndef AJOUTER_H
#define AJOUTER_H
#include "action_effectue.h"
#include "vols.h"
#include <QDialog>

namespace Ui {
class ajouter;
}

class ajouter : public QDialog
{
    Q_OBJECT

public:
    explicit ajouter(QWidget *parent = nullptr);
    ~ajouter();

private slots:


    void on_validation_accepted();

private:
    Ui::ajouter *ui;
    vols tmpvol;
    QMediaPlayer* player;

};

#endif // AJOUTER_H
