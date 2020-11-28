#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>



class Connection
{
public:
    Connection();
    bool ouvrirConnection();
    ~Connection();




/*private:
    QSqlDatabase db;
public:
    Connection();
    ~Connection();
    bool ouvrirConnection();
    void fermerConnection(); */
};

#endif // CONNECTION_H
