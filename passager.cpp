#include "passager.h"
#include <QDebug>
passager::passager()
{
    cin=0;
    nom="";
    prenom="";
    age=0;
}
passager::passager(int cin,QString nom,QString prenom,int age)
{
     this->cin=cin;
     this->nom=nom;
     this->prenom=prenom;
     this->age=age;

}
QString passager::get_nom()
{
    return nom;
}
QString passager::get_prenom()
{
    return prenom;
}
int passager::get_cin()
{return cin;}
int passager::get_age()
{return age;}
bool passager::ajouter()
{
  QSqlQuery query;
  QString res= QString::number(cin);
  query.prepare("INSERT INTO PASSAGER (cin,nom,prenom,age) "
                      "VALUES (:cin,:nom,:prenom,:age)");
  query.bindValue(":cin", cin);
  query.bindValue(":nom", nom);
  query.bindValue(":prenom", prenom);
  query.bindValue(":age",age);
  return    query.exec();
}
QSqlQueryModel * passager::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PASSAGER");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    return model;
}
QSqlQueryModel * passager::afficher_par_cin(QString CIN)
{  QSqlQueryModel * model= new QSqlQueryModel();


    model->setQuery("select * from PASSAGER WHERE cin = '"+CIN+"' ") ;


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));

       return model;

}

bool passager::supprimer(int CIN)
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("Delete from PASSAGER where cin = :cin ");
query.bindValue(":cin", res);
return    query.exec();
}
bool passager::Modifier(int cin, QString nom, QString prenom,int age)
{
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("Delete from PASSAGER where cin = :cin ");
    query.bindValue(":cin", res);
    query.prepare("INSERT INTO PASSAGER (cin,nom,prenom,age) "
                        "VALUES (:cin,:nom,:prenom,:age)");
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":age",age);
    return    query.exec();
}
