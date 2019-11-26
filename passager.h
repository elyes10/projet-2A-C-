#ifndef PASSAGER_H
#define PASSAGER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class passager
{

public:
    passager();
    passager(int,QString,QString,int);
     int get_cin();
    QString get_nom();
     QString get_prenom();
     int get_age();
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool Modifier(int,QString,QString,int);
         QSqlQueryModel * afficher_par_cin(QString);

private:
    int cin,age;
     QString nom,prenom;

};

#endif // PASSAGER_H
