#ifndef COLLABORATEUR_H
#define COLLABORATEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Collaborateur
{
private:
    int id,num;
    QString marque,adresse,mail;

public:
    Collaborateur();
    Collaborateur(int,QString,QString,QString,int);
    ~Collaborateur();
    int get_id(){return id;}
    QString get_marque(){return marque;}
    QString get_adresse(){return adresse;}
    QString get_mail(){return mail;}
    int get_num(){return num;}

    bool ajouter_collab();
    QSqlQueryModel * afficher_collab();
    bool supprimer_collab(int);
};

#endif // COLLABORATEUR_H
