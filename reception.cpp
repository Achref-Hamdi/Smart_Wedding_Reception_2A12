#include "reception.h"
#include <QDebug>
#include"connexion.h"

reception::reception()
{
    id_recep=0;
    ville_recep="";

    salle_reservee="";
    nombre_des_invites=0;

}


reception::reception(int id_recep,QString ville_recep,QString salle_reservee,int nombre_des_invites)
{
    this->id_recep=id_recep;
    this->ville_recep=ville_recep;

    this->salle_reservee=salle_reservee;
    this->nombre_des_invites=nombre_des_invites;
}

int reception::get_id_recep(){return id_recep;}
QString reception::get_ville_recep(){return ville_recep;}

QString reception::get_salle_reservee(){return salle_reservee;}
int reception::get_nombre_des_invites(){return nombre_des_invites;}


bool reception::ajouter_reception()
{
    QSqlQuery query;
    QString res= QString::number(id_recep);
    query.prepare("INSERT INTO reception (ID_RECEP, VILLE_RECEP, SALLE_RESERVEE, NOMBRE_DES_INVITES)"
                        "VALUES (:id_recep, :ville_recep,  :salle_reservee, :nombre_des_invites)");

    query.bindValue(":id_recep", res);
    query.bindValue(":ville_recep", ville_recep);

    query.bindValue(":salle_reservee", salle_reservee);
    query.bindValue(":nombre_des_invites", nombre_des_invites);

    return query.exec();
}

QSqlQueryModel * reception::afficher_reception()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from reception");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RECEP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("VILLE_RECEP"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SALLE_RESERVEE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMBRE_DES_INVITES"));

    return model;
}



bool reception::supprimer_reception(int id_recep)
{
    QSqlQuery query;
    QString res= QString::number(id_recep);
    query.prepare("Delete from reception where   ID_RECEP = :id_recep ");
    query.bindValue(":id_recep", res);
    return query.exec();
}

bool reception::modifier_reception(int id_recep)
{
    QSqlQuery query;
    QString res=QString::number(id_recep);

    query.prepare("UPDATE RECEPTION SET ID_RECEP=:id_recep,VILLE_RECEP=:ville_recep,SALLE_RESERVEE=:salle_reservee,NOMBRE_DES_INVITES=:nombre_des_invites where ID_RECEP=:id_recep ");
    query.bindValue(":ID_RECEP",res);
    query.bindValue(":VILLE_RECEP", ville_recep);
    query.bindValue(":SALLE_RESERVEE",salle_reservee);
   query.bindValue(":NOMBRE_DES_INVITES",nombre_des_invites);

    return query.exec();

}

