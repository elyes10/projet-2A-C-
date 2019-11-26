#include "connection.h"
#include <exception>
Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("passager");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("esprit");//inserer mot de passe de cet utilisateur
if (db.open())
    test=true;
else
    throw QString ("Erreur Paramétres");
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
