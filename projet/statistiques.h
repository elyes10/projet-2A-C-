#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QDialog>
#include "billet.h"
namespace Ui {
class statistiques;
}

class statistiques : public QDialog
{
    Q_OBJECT

public:
    explicit statistiques(QWidget *parent = nullptr);
    ~statistiques();

private slots:
    void makePlot();

private:
    Ui::statistiques *ui;
};

#endif // STATISTIQUES_H
