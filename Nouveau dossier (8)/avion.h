#ifndef AVION_H
#define AVION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class avion
{
public:
    avion();
    avion(QString,QString,QString,QString,int,int);
    void setcin(QString);
    void setnom(QString);
    void setprenom(QString);
    void setmatricule(QString);
    void setage(int);
    void setnumcontrat(int);
    QString getcin();
    QString getnom();
    QString getprenom();
    QString getmatricule();
    int getage();
    int getnumcontrat();
    bool ajouter_avion();
    bool modifier_avion();
    bool supprimer_avion();
    QSqlQueryModel * afficher_avion();
    QSqlQueryModel * afficher_list();
    void chercher();
    QSqlQueryModel * recherche(QString valeur, int etat);

private:
    QString cin,nom,prenom,matricule;
    int age,num_contrat;

};

#endif // AVION_H
