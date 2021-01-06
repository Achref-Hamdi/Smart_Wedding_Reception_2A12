#ifndef INVITE_H
#define INVITE_H
#include<QString>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QSqlQueryModel>
#include<QDebug>
#include"connexion.h"

class invite
{
private :
    int id_inv,nombre_de_places_reserves,numero_table;
        QString mail_invite;

public:
  invite(int,int,int,QString);
    invite();

        bool ajouter_invite();
        QSqlQueryModel * afficher_invite();
        bool supprimer_invite(int);
        bool modifier_invite(int);
        QSqlQueryModel* afficher_invite(int );
        bool rechercher_invite(int );
        void set_id_inv(int);
        void set_nombre_de_places_reserves(int );
        void set_numero_table(int);
        void set_mail_invite(QString );


        int get_id_inv();
        int get_nombre_de_places_reserves();

        QString get_mail_invite();
        int get_numero_table();




};


#endif // INVITE_H
