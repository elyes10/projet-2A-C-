#ifndef CONGE_H
#define CONGE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "qcustomplot.h"
class conge
{
public:
    conge();
    conge(QString,QString,QString,QString,QString);

    void setnum_conge(QString);
    void setdate_debut(QString);
    void setdate_fin(QString);
    void settype(QString);
    void setcin_employer(QString);

    QString getnum_conge();
    QString getdate_debut();
    QString getdate_fin();
    QString gettype();
    QString getcin_employer();

    bool ajouter_conge();
    bool modifier_conge();
    bool supprimer_conge();
    QSqlQueryModel * afficher_conge();
    QSqlQueryModel * afficher_list();
    void chercher();
    QSqlQueryModel * recherche(QString valeur, int etat);
    void statistique(QVector<double>* ticks,QVector<QString> *labels);

private:
    QString date_debut,date_fin,type,cin_employer, num_conge;

};

#endif // CONGE_H
