#include "employer.h"
#include "connexion.h"
employer::employer()
{

}
employer::employer(QString c,QString n,QString p,QString m,int a,int nc)
{
    cin=c;
    nom=n;
    prenom=p;
    matricule=m;
    age=a;
    num_contrat=nc;

}
void employer::setcin(QString c)
{
    cin=c;
}
void employer::setnom(QString n)
{
    nom=n;
}
void employer::setprenom(QString p)
{
    prenom=p;
}
void employer:: setmatricule(QString m)
{
    matricule=m;
}
void employer:: setage(int a)
{
    age=a;
}
void employer::setnumcontrat(int n)
{
    num_contrat=n;
}
QString employer:: getcin()
{
    return  cin;
}
QString employer:: getnom()
{
    return nom;
}
QString employer:: getprenom()
{
    return prenom;
}
QString employer:: getmatricule()
{
    return matricule;
}
int employer:: getage()
{
    return age;
}
int employer::getnumcontrat()
{
    return num_contrat;
}
bool employer:: ajouter_employer()
{
    QSqlQuery query;

    query.prepare("INSERT INTO employer (cin,nom,prenom,age,matricule,num_contrat) " "VALUES (:cin,:nom,:prenom,:age,:matricule,:num_contrat)");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
  query.bindValue(":matricule", matricule);

query.bindValue(":num_contrat", num_contrat);
    return    query.exec();

}


bool employer::supprimer_employer()
{

    QSqlQuery query;
    query.prepare("Delete from employer where cin = :cin ");
    query.bindValue(":cin",cin);
    return    query.exec();

}
QSqlQueryModel * employer:: afficher_employer()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from employer");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("num_contart"));
    return model;
}

 bool employer::modifier_employer()
 {      QSqlQuery query;
        query.prepare("update employer set nom=:nom,prenom=:prenom,matricule=:matricule,age=:age,num_contrat=:num_contrat where cin=:cin");
        query.bindValue(":cin",cin);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":matricule", matricule);
        query.bindValue(":age", age);
        query.bindValue(":num_contrat", num_contrat);


        return    query.exec();

}

QSqlQueryModel * employer:: afficher_list()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select cin from employer");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));


            return model;
}
void employer:: chercher()
{    QSqlQuery query1;
     query1.prepare("SELECT nom,prenom,matricule,age,num_contrat FROM employer WHERE cin =:cin");
     query1.bindValue(":cin",cin);
     query1.exec();
     while(query1.next())
     {
     nom = query1.value(0).toString();
     prenom = query1.value(1).toString();
     matricule = query1.value(2).toString();
     age = query1.value(3).toInt();
     num_contrat = query1.value(4).toInt();
     }

}
QSqlQueryModel * employer:: recherche(QString valeur, int etat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat==0)
   { query.prepare("SELECT * FROM employer WHERE (cin LIKE :valeur) order by cin");}
    else   { query.prepare("SELECT * FROM employer WHERE (cin LIKE :valeur) order by cin desc");}
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
