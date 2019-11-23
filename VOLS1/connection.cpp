#include "connection.h"
#include <exception>

connection::connection()
{}

bool connection::ouvrirconnetion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("ajouter vols");
db.setUserName("Soumaya");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur
if (db.open())
    test=true;
else
    throw QString ("Erreur Paramétres");
return  test;
}
void connection::fermerconnetion()
{db.close();}



