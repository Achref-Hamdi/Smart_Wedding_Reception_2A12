#include "connexion.h"

connexion::connexion()
{

}

bool connexion::createconnect()
{
    bool test =false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test");
    db.setUserName("system");
    db.setPassword("system");
    if(db.open())
    {
        test=true;
    }
    return test;
}
