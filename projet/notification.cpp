#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{
num=0;
}
void notification::notification_sup_billet(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/WSI/Desktop/projet/icon.png"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Une billet a ete supprimer de la base !",QSystemTrayIcon::Information,15000);
//num++;
}
