#include "connection.h"

Connection::Connection()
{}

bool Connection::ouvrirConnection()
{
    bool test=false;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("base");
    db.setUserName("SYSTEM");
    db.setPassword("SYSTEM");

    if(db.open())
        test = true;
    return test;
}

void Connection::fermerConnection()
{db.close();}
