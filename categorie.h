#ifndef CATEGORIE_H
#define CATEGORIE_H
#include "connexion.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Categorie
{
private:
    int id;
    QString date_Dc;
    QString date_Fc;
    QString domaine;

public:
    Categorie();
    Categorie(int,QString,QString,QString);
   /* ~Categorie();*/

    void setId(int);
    void setDate_Dc(QString);
    void setDate_Fc(QString );
    void setDomaine(QString);

    int getId();
    QString getDate_Dc();
    QString getDate_Fc();
    QString getDomaine();


bool ajouter_cat();
QSqlQueryModel* afficher_cat();
bool supprimer_cat(int);
bool modifier_cat();

};

#endif // CATEGORIE_H
