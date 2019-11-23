#include "action_effectue.h"
#include "ui_action_effectue.h"

action_effectue::action_effectue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::action_effectue)
{
    ui->setupUi(this);
}

action_effectue::~action_effectue()
{
    delete ui;
}
