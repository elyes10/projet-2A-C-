#ifndef BILLET_H
#define BILLET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class billet
{
public:
    billet();
    billet(int,QString,QString,QString,QString,int,int,int,QString);
    QString get_destination();
     QString get_datevol();
      QString get_type();
       QString get_classe();
        QString get_etat();
        int get_prix();
        int get_id();
        int get_numplace();
        int get_idpassager();
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool Modifier(int,QString,QString,QString,int,int,int,QString,QString);
        bool supprimer_tout();
       QSqlQueryModel * afficher_par_id(QString);
private:
    int id,numplace,idpassager, prix;
     QString destination,datevol,type,classe,etat;
};

#endif // BILLET_H
