#ifndef SUPPRIMER_H
#define SUPPRIMER_H
#include "action_effectue.h"
#include <QDialog>
#include "vols.h"

namespace Ui {
class supprimer;
}

class supprimer : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer(QWidget *parent = nullptr);
    ~supprimer();

private slots:
    void on_validation_accepted();

private:
    Ui::supprimer *ui;
    vols tmpvol;
    QMediaPlayer* player;
};

#endif // SUPPRIMER_H
