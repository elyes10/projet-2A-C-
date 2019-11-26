#ifndef SUPPRIMER_PASSAGER_H
#define SUPPRIMER_PASSAGER_H
#include "passager.h"
#include <QDialog>

namespace Ui {
class supprimer_passager;
}

class supprimer_passager : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer_passager(QWidget *parent = nullptr);
    ~supprimer_passager();

private slots:
    void on_pushButton_clicked();

private:
    Ui::supprimer_passager *ui;
    passager tmp;
};

#endif // SUPPRIMER_PASSAGER_H
