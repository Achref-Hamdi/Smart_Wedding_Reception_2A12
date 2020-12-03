#include "categorie.h"
#include <QSqlQuery>
#include <QDebug>
#include<QString>
#include "connexion.h"

Categorie::Categorie()
{
    id=0;
    date_Dc="";
    date_Fc="";
    domaine="";
}

Categorie::Categorie(int id,QString date_Dc,QString date_Fc,QString domaine)
{
        this->id=id;
        this->date_Dc=date_Dc;
        this->date_Fc=date_Fc;
        this->domaine=domaine;
}

void Categorie::setId(int id){this->id=id;}
void Categorie::setDate_Dc(QString date_Dc){this->date_Dc=date_Dc;}
void Categorie::setDate_Fc(QString date_Fc){this->date_Fc=date_Fc;}
void Categorie::setDomaine(QString domaine){this->domaine=domaine;}

int Categorie::getId(){return id;}
QString Categorie::getDate_Dc(){return date_Dc;}
QString Categorie::getDate_Fc(){return date_Dc;}
QString Categorie::getDomaine(){return domaine;}



bool Categorie::ajouter_cat()
{
QSqlQuery query;

QString res= QString::number(id);
query.prepare("INSERT INTO CATEGORIEES (ID, DATE_DC, DATE_FC,DOMAINE) "

                    "VALUES (:id,:date_Dc,:date_Fc,:domaine)");
query.bindValue(":id", res);
query.bindValue(":date_Dc", date_Dc);
query.bindValue(":date_Fc", date_Fc);
query.bindValue(":domaine", domaine);

return    query.exec();

}


QSqlQueryModel* Categorie::afficher_cat()

{
    QSqlQueryModel* model= new QSqlQueryModel();
model->setQuery("select * from CATEGORIEES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_DC"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_FC"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DOMAINE"));

    return model;
}


bool Categorie::supprimer_cat(int id)
{
QSqlQuery query;

QString res= QString::number(id);

query.prepare("Delete from CATEGORIEES where ID = :id ");

query.bindValue(":id", res);

return    query.exec();
}


bool Categorie::modifier_cat()
{
    QSqlQuery query ;
           QString res= QString::number(id);
           query.prepare("update CATEGORIEES set DATE_DC=:date_Dc,DATE_FC=:date_Fc,DOMAINE=:domaine where ID=:id ");

           query.bindValue(":id",res);
           query.bindValue(":date_Dc",date_Dc);
           query.bindValue(":date_Fc",date_Fc);
           query.bindValue(":domaine",domaine);

           return query.exec();
}
