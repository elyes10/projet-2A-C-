#include "vols.h"
#include <QDebug>
vols::vols()
{
    dest_depart="";
    dest_arrive="";
    date_depart="";
    date_arrive="";
    dure_vol="";
    nbr_passagers=0;
    num_unique=0;

}

vols::vols(int num_unique,QString dest_depart,QString dest_arrive,QString date_depart,QString date_arrive,QString dure_vol,int nbr_passagers)
{
    this->num_unique=num_unique;
    this->date_depart=date_depart;
    this->date_arrive=date_arrive;
    this->dest_depart=dest_depart;
    this->dest_arrive=dest_arrive;
    this->dure_vol=dure_vol;
    this->nbr_passagers=nbr_passagers;
}
int vols::get_num_unique(){return num_unique;}
QString vols::get_date_depart(){return date_depart;}
QString vols::get_date_arrive(){return date_arrive;}
QString vols::get_dest_depart(){return dest_depart;}
QString vols::get_dest_arrive(){return dest_arrive;}
QString vols::get_dure_vol(){return dure_vol;}
int vols::get_nbr_passagers(){return nbr_passagers;}


bool vols::ajouter()
{
QSqlQuery query;
QString res = QString::number(num_unique);
query.prepare("INSERT INTO VOLS (NUM_UNIQUE,DEST_DEPART,DEST_ARRIVE,DATE_DEPART,DATE_ARRIVE,DURE_VOL,NBR_PASSAGERS)"
                    "VALUES (:num_unique, :dest_depart, :dest_arrive, :date_depart, :date_arrive, :dure_vol, :nbr_passagers)");
query.bindValue(":num_unique", res);
query.bindValue(":dest_depart", dest_depart);
query.bindValue(":dest_arrive", dest_arrive);
query.bindValue(":date_depart", date_depart);
query.bindValue(":date_arrive", date_arrive);
query.bindValue(":dure_vol", dure_vol);
query.bindValue(":nbr_passagers", nbr_passagers);
return    query.exec();
}



QSqlQueryModel * vols::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOLS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_UNIQUE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_DEPART"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ARRIVE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DEST_DEPART"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DEST_ARRIVE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("DURE_VOL"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("NBR_PASSAGERS"));
    return model;
}

QSqlQueryModel *vols::afficherparnum(QString num_unique)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from VOLS WHERE NUM_UNIQUE = '"+num_unique+"' ") ;


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_UNIQUE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_DEPART"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ARRIVE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DEST_DEPART"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DEST_ARRIVE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DURE_VOL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("NBR_PASSAGERS"));
       return model;
}

bool vols::supprimer(int num_unique)
{
QSqlQuery query;
QString res= QString::number(num_unique);
query.prepare("Delete from VOLS where NUM_UNIQUE = :num_unique ");
query.bindValue(":num_unique", res);
return    query.exec();
}


bool vols::Modifier(int num_unique,QString dest_depart1,QString dest_arrive1,QString date_depart1,QString date_arrive1,QString dure_vol1,int nbr_passagers1)
{
    QSqlQuery query;
    QString res= QString::number(num_unique);
      query.bindValue(":num_unique", res);
    query.prepare("UPDATE VOLS SET DEST_DEPART = :dest_depart, DEST_ARRIVE = :dest_arrive,DATE_DEPART = :date_depart,DATE_ARRIVE = :date_arrive,DURE_VOL= :dure_vol ,NBR_PASSAGERS = :nbr_passagers WHERE(NUM_UNIQUE = :num_unique)");
    query.bindValue(":dest_depart", dest_depart1);
    //query.prepare("UPDATE VOLS SET DEST_ARRIVE = :dest_arrive WHERE(NUM_UNIQUE = :num_unique)");
    query.bindValue(":dest_arrive", dest_arrive1);
    //query.prepare("UPDATE VOLS SET DATE_DEPART = :dest_depart WHERE(NUM_UNIQUE = :num_unique)");
    query.bindValue(":date_depart", date_depart1);
    //query.prepare("UPDATE VOLS SET DATE_ARRIVE = :dest_arrive WHERE(NUM_UNIQUE = :num_unique)");
    query.bindValue(":date_arrive", date_arrive1);
    //query.prepare("UPDATE VOLS SET DURE_VOL = :dure_vol WHERE(NUM_UNIQUE = :num_unique)");
    query.bindValue(":dure_vol", dure_vol1);
    //query.prepare("UPDATE VOLS SET NBR_PASSAGERS = :nbr_passagers WHERE(NUM_UNIQUE = :num_unique)");
    query.bindValue(":nbr_passagers", nbr_passagers1);

    query.bindValue(":num_unique", res);
    /**query.bindValue(":dest_depart", dest_depart1);
    query.bindValue(":dest_arrive", dest_arrive1);
    query.bindValue(":date_depart", date_depart1);
    query.bindValue(":date_arrive", date_arrive1);
    query.bindValue(":dure_vol", dure_vol1);
    query.bindValue(":nbr_passagers", nbr_passagers1);*/
    return    query.exec();
}




