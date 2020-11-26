#include "collaborateur.h"
#include <QDebug>
#include "connection.h"


Collaborateur::Collaborateur()
{
    id=0;
    marque="";
    adresse="";
    mail="";
    num=0;
}


Collaborateur::Collaborateur(int id,QString marque,QString adresse,QString mail,int num)
{
    this->id=id;
    this->marque=marque;
    this->adresse=adresse;
    this->mail=mail;
    this->num=num;
}


bool Collaborateur::ajouter_collab()
{
    QSqlQuery query;
    QString res= QString::number(id);     // ?
    query.prepare("INSERT INTO collaborateur (ID, MARQUE, ADRESSE, MAIL, NUM)"
                        "VALUES (:id, :marque, :adresse, :mail, :num)");

    query.bindValue(":id", res);
    query.bindValue(":marque", marque);
    query.bindValue(":adresse", adresse);
    query.bindValue(":mail", mail);
    query.bindValue(":num", num);

    return query.exec();
}

QSqlQueryModel * Collaborateur::afficher_collab()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from collaborateur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM"));

    return model;
}

bool Collaborateur::supprimer_collab(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from collaborateur where ID = :id ");
    query.bindValue(":id", res);
    return query.exec();
}















