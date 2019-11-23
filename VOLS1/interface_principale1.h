#ifndef INTERFACE_PRINCIPALE1_H
#define INTERFACE_PRINCIPALE1_H

#include <QDialog>

namespace Ui {
class interface_principale1;
}

class interface_principale1 : public QDialog
{
    Q_OBJECT

public:
    explicit interface_principale1(QWidget *parent = nullptr);
    ~interface_principale1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::interface_principale1 *ui;
};

#endif // INTERFACE_PRINCIPALE1_H
