#ifndef COLLABORATEUR_H
#define COLLABORATEUR_H
#include "connexion.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Collaborateur
{
private :
    int id;
    QString marque;
    QString adresse;
    QString mail;
    int numero;


public:
    Collaborateur();
    Collaborateur(int,QString,QString,QString,int);
   /* ~Collaborateur();*/

    void setId(int);
    void setMarque(QString);
    void setAdresse(QString );
    void setMail(QString);
    void setNumero(int);

    int getId();
    QString getMarque();
    QString getAdresse();
    QString getMail();
    int getNumero();


bool ajouter_collab();
QSqlQueryModel* afficher_collab();
bool supprimer_collab(int);
bool modifier_collab();

QSqlQueryModel* trier_collab_id();
QSqlQueryModel* trier_collab_marque();
QSqlQueryModel* trier_collab_adresse();


QSqlQueryModel* afficher_collaborateur(int id);
bool rechercher_collab(int id);







/*
bool rechercher_collab_marque(QString);
bool rechercher_collab_adresse(QString);
*/
};

#endif // COLLABORATEUR_H
