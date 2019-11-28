#ifndef EMPLOYER_H
#define EMPLOYER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class employer
{
public:
    employer();
    employer(QString,QString,QString,QString,int,int);
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
    bool ajouter_employer();
    bool modifier_employer();
    bool supprimer_employer();
    QSqlQueryModel * afficher_employer();
    QSqlQueryModel * afficher_list();
    void chercher();
    QSqlQueryModel * recherche(QString valeur, int etat);

private:
    QString cin,nom,prenom,matricule;
    int age,num_contrat;

};

#endif // EMPLOYER_H
