#include "conge.h"

conge::conge()
{

}

conge::conge(QString a,QString b,QString c,QString d,QString e)
{ num_conge=a;
  date_debut=b;
  date_fin=c;
  type=d;
  cin_employer=e;
}

void conge:: setnum_conge(QString a)
{
  num_conge=a;
}

void conge :: setdate_debut(QString a)
{
    date_debut=a;
}

void conge:: setdate_fin(QString a)
{
    date_fin=a;
}
void conge ::settype(QString a)
{
    type=a;
}

void conge ::setcin_employer(QString a)
{
   cin_employer=a;
}

QString conge:: getnum_conge()
{
    return num_conge;
}

QString conge:: getdate_debut()
{
    return date_debut;
}
QString conge:: getdate_fin()
{
    return date_fin;
}

QString conge:: gettype()
{
    return type;
}

QString conge:: getcin_employer()
{
    return cin_employer;
}

bool conge:: ajouter_conge()
{
    QSqlQuery query;

    query.prepare("INSERT INTO conge (num_conge,date_debut,date_fin,type,cin_employer) " "VALUES  (:num_conge,:date_debut,:date_fin,:type,:cin_employer)");
    query.bindValue(":num_conge",num_conge);
    query.bindValue(":date_debut",date_debut);
    query.bindValue(":date_fin",date_fin);
    query.bindValue(":type",type);
    query.bindValue(":cin_employer", cin_employer);
    return    query.exec();
}
bool conge:: modifier_conge()
{
    QSqlQuery query;
       query.prepare("update conge set date_debut=:date_debut,date_fin=:date_fin,type=:type,cin_employer=:cin_employer where num_conge=: num_conge");
       query.bindValue(":num_conge",num_conge);
       query.bindValue(":date_debut",date_debut);
       query.bindValue(":date_fin",date_fin);
       query.bindValue(":type",type);
       query.bindValue(":cin_employer",cin_employer);


       return    query.exec();

}
bool conge:: supprimer_conge()
{
    QSqlQuery query;
    query.prepare("Delete from conge where num_conge = :num_conge ");
    query.bindValue(":num_conge",num_conge);
    return    query.exec();
}
QSqlQueryModel * conge ::afficher_conge()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from conge");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_conge"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_debut"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_fin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("cin_employer"));

        return model;
}
QSqlQueryModel * conge:: afficher_list()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select num_conge from conge");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_conge"));


            return model;

}
void conge:: chercher()
{
    QSqlQuery query1;
       query1.prepare("SELECT date_debut,date_fin,type,cin_employer FROM conge WHERE num_conge=:num_conge");
       query1.bindValue(":num_conge",num_conge);
       query1.exec();
       while(query1.next())
       {
       date_debut = query1.value(0).toString();
       date_fin = query1.value(1).toString();
       type = query1.value(2).toString();
       cin_employer = query1.value(3).toString();

          }
}
QSqlQueryModel * conge:: recherche(QString valeur, int etat)
{    QSqlQueryModel * model=new QSqlQueryModel();

     QSqlQuery query;
     if(etat==0)
    { query.prepare("SELECT * FROM conge WHERE (NUM_CONGE  like :valeur) order by NUM_CONGE");}
     else   { query.prepare("SELECT * FROM employer WHERE (NUM_CONGE like :valeur) order by NUM_CONGE desc");}
     valeur="%"+valeur+"%";
     query.bindValue(":valeur",valeur);
     query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_CONGE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_debut"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_fin"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("cin_employer"));

     return model;

}

 void conge:: statistique(QVector<double>* ticks,QVector<QString> *labels)
 {  QSqlQuery q;
     int i=0;
     q.exec("select type from conge");
     while (q.next()) {
         QString type = q.value(0).toString();
         i++;
         *ticks<<i;
         *labels <<type;
     }

 }
