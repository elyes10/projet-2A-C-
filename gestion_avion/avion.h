#ifndef avion_H
#define avion_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class avion
{
public:
    avion();
    avion(QString,QString,QString,QString,QString);
    void setid(QString);
    void setnom(QString);
    void setmodel(QString);
    void setetat(QString);
    void setmatricule(QString);
    QString getid();
    QString getnom();
    QString getmodel();
    QString getetat();
    QString getmatricule();
    bool ajouter_avion();
    bool modifier_avion();
    bool supprimer_avion();
    QSqlQueryModel * afficher_avion();
    QSqlQueryModel * afficher_list();
    void chercher();
    bool existe(QString);
    QSqlQueryModel * recherche(QString valeur, int etat);

private:
    QString id,nom,model,etat,matricule;


};

#endif // avion_H
