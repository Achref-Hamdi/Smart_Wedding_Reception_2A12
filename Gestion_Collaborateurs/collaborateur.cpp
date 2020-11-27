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
    Connection C;
    bool v=C.ouvrirConnection();
}


Collaborateur::Collaborateur(int id,QString marque,QString adresse,QString mail,int num)
{
    this->id=id;
    this->marque=marque;
    this->adresse=adresse;
    this->mail=mail;
    this->num=num;
}


int Collaborateur::get_id(){return id;}
QString Collaborateur::get_marque(){return marque;}
QString Collaborateur::get_adresse(){return adresse;}
QString Collaborateur::get_mail(){return mail;}
int Collaborateur::get_num(){return num;}

void Collaborateur::set_id(int id){ this->id=id ;}
void Collaborateur::set_marque(QString marque){ this->marque=marque ;}
void Collaborateur::set_adresse(QString adresse){this->adresse=adresse;}
void Collaborateur::set_mail(QString mail){ this->mail=mail ;}
void Collaborateur::set_num(int num){ this->num= num ;}






bool Collaborateur::ajouter_collab()
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(num);
    query.prepare("INSERT INTO Collaborateur (ID, MARQUE, ADRESSE, MAIL, NUM)"
                        "VALUES (:res, :marque, :adresse, :mail, :num)");                // id

    query.bindValue(":res", res);          // id
    query.bindValue(":marque", marque);
    query.bindValue(":adresse", adresse);
    query.bindValue(":mail", mail);
    query.bindValue(":num", res1);           // num

    return query.exec();
}



QSqlQueryModel * Collaborateur::afficher_collab()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Collaborateur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM"));

    return model;
}
























/*
bool Collaborateur::supprimer_collab(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from collaborateur where   ID = :id ");
    query.bindValue(":id", res);
    return query.exec();
}






void Collaborateur::modifier_collab()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE collaborateur SET ID = :id WHERE ID = :id "
                  "UPDATE collaborateur SET MARQUE = :marque WHERE ID = :id"
                  "UPDATE collaborateur SET ADRESSE = :adresse WHERE ID = :id"
                  "UPDATE collaborateur SET MAIL = :mail WHERE ID = :id"
                  "UPDATE collaborateur SET NUM = :num WHERE ID = :id" );

    query.bindValue(":id", res);
    query.bindValue(":marque", marque);
    query.bindValue(":adresse", adresse);
    query.bindValue(":mail", mail);
    query.bindValue(":num", num);
}






int Collaborateur::rechercher_collab(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare(" select ID from collaborateur WHERE ID= :id ");

    query.bindValue(":id", res);
}

*/





