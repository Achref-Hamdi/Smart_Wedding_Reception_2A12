#ifndef RECEPTION_H
#define RECEPTION_H

#include<QString>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QSqlQueryModel>
#include<QDebug>
#include"connexion.h"

class reception
{
private :
    int id_recep,nombre_des_invites;
        QString ville_recep,salle_reservee;

public:
    reception(int,QString,QString,int);
    reception();

        bool ajouter_reception();
        QSqlQueryModel * afficher_reception();
        bool supprimer_reception(int);
        bool modifier_reception(int);

        void set_id_recep(int);
        void set_ville_recep(QString );

        void set_salle_reservee(QString );
        void set_nombre_des_invites(int);

        int get_id_recep();
        QString get_ville_recep();

        QString get_salle_reservee();
        int get_nombre_des_invites();




};


#endif // RECEPTION_H
