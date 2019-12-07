 #include "avion.h"
#include "connexion.h"
avion::avion()
{

}
avion::avion(QString c,QString n,QString p,QString m,QString a)
{
    id=c;
    nom=n;
    model=p;
    etat=m;
    matricule=a;


}
void avion::setid(QString c)
{
    id=c;
}
void avion::setnom(QString n)
{
    nom=n;
}
void avion::setmodel(QString p)
{
    model=p;
}
void avion:: setetat(QString m)
{
    etat=m;
}
void avion:: setmatricule(QString a)
{
    matricule=a;
}

QString avion:: getid()
{
    return  id;
}
QString avion:: getnom()
{
    return nom;
}
QString avion:: getmodel()
{
    return model;
}
QString avion:: getetat()
{
    return etat;
}
QString avion:: getmatricule()
{
    return matricule;
}

bool avion:: ajouter_avion()
{
    QSqlQuery query;

    query.prepare("INSERT INTO avion (id,nom,model,etat,matricule) " "VALUES (:id,:nom,:model,:etat,:matricule)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":model",model);
    query.bindValue(":etat", etat);
    query.bindValue(":matricule",matricule);
    return    query.exec();

}


bool avion::supprimer_avion()
{

    QSqlQuery query;
    query.prepare("Delete from avion where id = :id ");
    query.bindValue(":id",id);
    return    query.exec();

}
QSqlQueryModel * avion:: afficher_avion()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from avion");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("model"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));
    return model;
}

 bool avion::modifier_avion()
 {      QSqlQuery query;
        query.prepare("update avion set nom=:nom,model=:model,etat=:etat,matricule=:matricule where id=:id");
        query.bindValue(":id",id);
        query.bindValue(":nom",nom);
        query.bindValue(":model",model);
        query.bindValue(":etat", etat);
        query.bindValue(":matricule", matricule);


        return    query.exec();

}

QSqlQueryModel * avion:: afficher_list()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select id from avion");
        //model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
            return model;
}

void avion:: chercher()
{    QSqlQuery query1;
     query1.prepare("SELECT nom,model,etat,matricule FROM avion WHERE id =:id");
     query1.bindValue(":id",id);
     query1.exec();
     while(query1.next())
     {
     nom = query1.value(0).toString();
     model = query1.value(1).toString();
     etat = query1.value(2).toString();
     matricule = query1.value(3).toString();
     }
}

QSqlQueryModel * avion:: recherche(QString valeur, int etat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat==0)
   { query.prepare("SELECT * FROM avion WHERE id LIKE :valeur order by id");}
    else   { query.prepare("SELECT * FROM avion WHERE id LIKE :valeur order by id desc");}
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("model"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("matricule"));
    return model;
}

bool avion::existe(QString id)
{
    QSqlQuery query;
    query.prepare("select * from avion where id like :id");
    QString id1="%"+id+"%";
    query.bindValue(":id",id1);
   if(query.exec())
       return true;
   else
       return false;
}
