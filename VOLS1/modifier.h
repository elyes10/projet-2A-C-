#ifndef MODIFIER_H
#define MODIFIER_H
#include "action_effectue.h"
#include <QDialog>
#include "vols.h"

namespace Ui {
class modifier;
}

class modifier : public QDialog
{
    Q_OBJECT

public:
    explicit modifier(QWidget *parent = nullptr);
    ~modifier();

private slots:
    void on_validation_accepted();

private:
    Ui::modifier *ui;
    vols tmpvol;
    QMediaPlayer* player;
};

#endif // MODIFIER_H
