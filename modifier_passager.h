#ifndef MODIFIER_PASSAGER_H
#define MODIFIER_PASSAGER_H
#include "passager.h"
#include <QDialog>

namespace Ui {
class modifier_passager;
}

class modifier_passager : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_passager(QWidget *parent = nullptr);
    ~modifier_passager();

private slots:
    void on_pushButton_clicked();

private:
    Ui::modifier_passager *ui;
     passager tmp;
};

#endif // MODIFIER_PASSAGER_H
