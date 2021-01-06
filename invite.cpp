#include "invite.h"
#include <QDebug>
#include"connexion.h"

invite::invite()
{
    id_inv=0;
    nombre_de_places_reserves=0;
    numero_table=0;
    mail_invite="";

}


invite::invite(int id_inv,int nombre_de_places_reserves,int numero_table,QString mail_invite)
{
    this->id_inv=id_inv;
    this->nombre_de_places_reserves=nombre_de_places_reserves;

    this->numero_table=numero_table;
    this->mail_invite=mail_invite;
}

int invite::get_id_inv(){return id_inv;}
int invite::get_nombre_de_places_reserves(){return nombre_de_places_reserves;}
int invite::get_numero_table(){return numero_table;}

QString invite::get_mail_invite(){return mail_invite;}


bool invite::ajouter_invite()
{
    QSqlQuery query;
    QString res= QString::number(id_inv);
    query.prepare("INSERT INTO invite (ID_INV, NOMBRE_DE_PLACES_RESERVES, NUMERO_TABLE, MAIL_INVITE)"
                        "VALUES (:id_inv, :nombre_de_places_reserves,  :numero_table, :mail_invite)");

    query.bindValue(":id_inv", res);
    query.bindValue(":nombre_de_places_reserves", nombre_de_places_reserves);

    query.bindValue(":numero_table", numero_table);
    query.bindValue(":mail_invite", mail_invite);

    return query.exec();
}

QSqlQueryModel * invite::afficher_invite()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from invite");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_INV"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE_DE_PLACES_RESERVES"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMERO_TABLE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL_INVITE"));

    return model;
}



bool invite::supprimer_invite(int id_inv)
{
    QSqlQuery query;
    QString res= QString::number(id_inv);
    query.prepare("Delete from invite where   ID_INV = :id_inv ");
    query.bindValue(":id_inv", res);
    return query.exec();
}
bool invite::modifier_invite(int id_inv)
{
    QSqlQuery query;
    QString res=QString::number(id_inv);

    query.prepare("UPDATE INVITE SET ID_INV=:id_inv,NOMBRE_DE_PLACES_RESERVES=:nombre_de_places_reserves,NUMERO_TABLE=:numero_table,MAIL_INVITE=:mail_invite where ID_INV=:id_inv ");
    query.bindValue(":ID_INV",res);
    query.bindValue(":NOMBRE_DE_PLACES_RESERVES", nombre_de_places_reserves);
    query.bindValue(":NUMERO_TABLE",numero_table);
   query.bindValue(":MAIL_INVITE",mail_invite);


    return query.exec();

}


QSqlQueryModel* invite::afficher_invite(int id_inv)
{
    QSqlQuery query;
    QString res= QString::number(id_inv);
    query.prepare("SELECT * FROM INVITE WHERE ID_INV=:id_inv ");
    query.bindValue(":id_inv", res);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_INV"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE_DE_PLACES_RESERVES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMERO_TABLE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL_INV"));

    return model;
}

bool invite::rechercher_invite(int id_inv)
{
    QSqlQuery query;
    QString res = QString::number(id_inv);
    query.prepare("SELECT ID FROM INVITE WHERE ID_INV=:id_inv");
    query.bindValue(":id_inv", res);
    query.exec();
    if(query.size()!=id_inv){return false;}
    else return true;
}

