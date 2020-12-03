#include "connection.h"


connection::connection()
{

}




bool connection::createConnection(){
    bool test=false;
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet_2A");
    db.setUserName("hama");
    db.setPassword("hama");

    if(db.open())
        test=true;
    return test;
