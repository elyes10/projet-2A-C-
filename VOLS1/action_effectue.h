#ifndef ACTION_EFFECTUE_H
#define ACTION_EFFECTUE_H

#include <QDialog>

namespace Ui {
class action_effectue;
}

class action_effectue : public QDialog
{
    Q_OBJECT

public:
    explicit action_effectue(QWidget *parent = nullptr);
    ~action_effectue();

private:
    Ui::action_effectue *ui;
};

#endif // ACTION_EFFECTUE_H
