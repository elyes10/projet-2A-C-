#include "avion.h"
#include "connexion.h"
avion::avion()
{

}
avion::avion(QString c,QString n,QString p,QString m,int a,int nc)
{
    cin=c;
    nom=n;
    prenom=p;
    matricule=m;
    age=a;
    num_contrat=nc;

}
void avion::setcin(QString c)
{
    cin=c;
}
void avion::setnom(QString n)
{
    nom=n;
}
void avion::setprenom(QString p)
{
    prenom=p;
}
void avion:: setmatricule(QString m)
{
    matricule=m;
}
void avion:: setage(int a)
{
    age=a;
}
void avion::setnumcontrat(int n)
{
    num_contrat=n;
}
QString avion:: getcin()
{
    return  cin;
}
QString avion:: getnom()
{
    return nom;
}
QString avion:: getprenom()
{
    return prenom;
}
QString avion:: getmatricule()
{
    return matricule;
}
int avion:: getage()
{
    return age;
}
int avion::getnumcontrat()
{
    return num_contrat;
}
bool avion:: ajouter_avion()
{
    QSqlQuery query;

    query.prepare("INSERT INTO avion (cin,nom,prenom,age,matricule,num_contrat) " "VALUES (:cin,:nom,:prenom,:age,:matricule,:num_contrat)");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
  query.bindValue(":matricule", matricule);

query.bindValue(":num_contrat", num_contrat);
    return    query.exec();

}


bool avion::supprimer_avion()
{

    QSqlQuery query;
    query.prepare("Delete from avion where cin = :cin ");
    query.bindValue(":cin",cin);
    return    query.exec();

}
QSqlQueryModel * avion:: afficher_avion()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from avion");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("num_contart"));
    return model;
}

 bool avion::modifier_avion()
 {      QSqlQuery query;
        query.prepare("update avion set nom=:nom,prenom=:prenom,matricule=:matricule,age=:age,num_contrat=:num_contrat where cin=:cin");
        query.bindValue(":cin",cin);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":matricule", matricule);
        query.bindValue(":age", age);
        query.bindValue(":num_contrat", num_contrat);


        return    query.exec();

}

QSqlQueryModel * avion:: afficher_list()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select cin from avion");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));


            return model;
}
void avion:: chercher()
{    QSqlQuery query1;
     query1.prepare("SELECT nom,prenom,matricule,age,num_contrat FROM avion WHERE cin =:cin");
     query1.bindValue(":cin",cin);
     query1.exec();
     while(query1.next())
     {
     nom = query1.value(0).toString();
     prenom = query1.value(0).toString();
     matricule = query1.value(0).toString();
     age = query1.value(1).toInt();
     num_contrat = query1.value(2).toInt();
     }

}
QSqlQueryModel * avion:: recherche(QString valeur, int etat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat==0)
   { query.prepare("SELECT * FROM avion WHERE cin LIKE :valeur order by cin");}
    else   { query.prepare("SELECT * FROM avion WHERE cin LIKE :valeur order by cin desc");}
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("num_contrat"));
    return model;

}
