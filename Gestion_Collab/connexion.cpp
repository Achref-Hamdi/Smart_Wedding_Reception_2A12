#include "connexion.h"

Connexion::Connexion(){}


bool Connexion::ouvrirConnexion()
{
    bool test=false;
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("base");
    db.setUserName("SYSTEM");
    db.setPassword("SYSTEM");

    if(db.open())
        test=true;

    return test;
}

void Connexion::fermerConnexion()
{
    db.close();
}
