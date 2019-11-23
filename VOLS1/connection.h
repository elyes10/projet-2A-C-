#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class connection
{

private:
    QSqlDatabase db;
public:
    connection();

    bool ouvrirconnetion();
    void fermerconnetion();

};

#endif // CONNECTION_H
