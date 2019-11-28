#include "billet.h"
#include <QDebug>
billet::billet()
{
  id=0;
  prix=0;
  numplace=0;
  idpassager=0;
  destination="";
  datevol="";
  type="";
  classe="";
  etat="";
}
billet::billet(int id,QString destination,QString datevol,QString type,QString classe,int numplace,int idpassager,int prix,QString etat)
{
     this->id=id;
     this->destination=destination;
     this->datevol=datevol;
     this->type=type;
     this->classe=classe;
     this->numplace=numplace;
     this->idpassager=idpassager;
     this->prix=prix;
     this->etat=etat;
}
QString billet::get_destination()
{
    return destination;
}
QString billet::get_etat()
{
    return etat;
}
int billet::get_id()
{return id;}
QString billet::get_type()
{return type;}
QString billet::get_classe()
{return classe;}
QString billet::get_datevol()
{return datevol;}
int billet::get_prix()
{return  prix;}
int billet::get_numplace()
{return numplace;}
int billet::get_idpassager()
{return  idpassager;}

bool billet::ajouter()
{
  QSqlQuery query;
  QString res= QString::number(id);
  query.prepare("INSERT INTO BILLETS (id, type, classe, datevol, prix, numplace, idpassager, etat, destination) "
                      "VALUES (:id, :type, :classe,:datevol,:prix,:numplace,:idpassager,:etat,:destination)");
  query.bindValue(":id", res);
  query.bindValue(":type", type);
  query.bindValue(":classe", classe);
  query.bindValue(":datevol", datevol);
  query.bindValue(":prix",prix);
  query.bindValue(":numplace",numplace);
  query.bindValue(":idpassager", idpassager);
  query.bindValue(":etat", etat);
  query.bindValue(":destination", destination);
  return    query.exec();
}
QSqlQueryModel * billet::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from BILLETS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("classe"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("datevol"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("numplace"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("idpassager"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("destination"));

    return model;
}

QSqlQueryModel * billet::afficher_par_id(QString idd)
{  QSqlQueryModel * model= new QSqlQueryModel();


    model->setQuery("select * from BILLETS WHERE id like '"+idd+"%' ") ;


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datevol"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("numplace"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("idpassager"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("destination"));
       return model;

}




bool billet::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from BILLETS where id = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool billet::supprimer_tout()
{QSqlQuery query;
   QString res="non valable";
   query.prepare("Delete from BILLETS where etat = :etat ");
   query.bindValue(":etat", res);
   return    query.exec();
}

bool billet::Modifier(int id, QString type1, QString classe1, QString datevol1, int prix1, int numplace1, int idpassager1, QString etat1, QString destination1)
{
     QSqlQuery query;
      QString res= QString::number(id);
      query.bindValue(":id", res);
        query.prepare("update BILLETS SET TYPE = :type,CLASSE= :classe,DATEVOL= :datevol,PRIX= :prix,NUMPLACE= :numplace,IDPASSAGER= :idpassager,ETAT= :etat,DESTINATION= :destination WHERE(ID = :id)");
        query.bindValue(":type", type1);
         query.bindValue(":classe", classe1);
          query.bindValue(":datevol", datevol1);
          query.bindValue(":prix", prix1);
          query.bindValue(":numplace", numplace1);
          query.bindValue(":idpassager", idpassager1);
          query.bindValue(":etat", etat1);
          query.bindValue(":destination", destination1);
          query.bindValue(":id", res);
          return    query.exec();
}
