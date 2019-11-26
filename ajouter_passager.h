#ifndef AJOUTER_PASSAGER_H
#define AJOUTER_PASSAGER_H

#include <QDialog>

namespace Ui {
class ajouter_passager;
}

class ajouter_passager : public QDialog
{
    Q_OBJECT

public:
    explicit ajouter_passager(QWidget *parent = nullptr);
    ~ajouter_passager();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ajouter_passager *ui;
};

#endif // AJOUTER_PASSAGER_H
