#ifndef COLLABORATEUR_H
#define COLLABORATEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connection.h"

class Collaborateur
{
private:
    int id,num;
    QString marque,adresse,mail;

public:
    Collaborateur();
    Collaborateur(int,QString,QString,QString,int);




    bool ajouter_collab();
    QSqlQueryModel * afficher_collab();
    bool supprimer_collab(int);
    void modifier_collab();
    void rechercher_collab(int);
    void tri_collab();


    int get_id();
    QString get_marque();
    QString get_adresse();
    QString get_mail();
    int get_num();

    void set_id(int);
    void set_marque(QString );
    void set_adresse(QString );
    void set_mail(QString );
    void set_num(int);




};

#endif // COLLABORATEUR_H
