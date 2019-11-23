#ifndef VOLS_H
#define VOLS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMediaPlayer>
#include <QThread>
class vols
{
public:
    vols();
    vols(int,QString,QString,QString,QString,QString,int);
    int get_num_unique();
    QString get_dest_depart();
    QString get_dest_arrive();
    QString get_date_depart();
    QString get_date_arrive();
    QString get_dure_vol();
    int get_nbr_passagers();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel *afficherparnum(QString);
    bool supprimer(int);
    bool Modifier(int,QString,QString,QString,QString,QString,int);

private :
    QString dest_depart,dest_arrive,date_depart,date_arrive,dure_vol;
    int nbr_passagers,num_unique;
    //float dure_vol;

};

#endif // VOLS_H
