#include "collaborateur.h"
#include <QSqlQuery>
#include <QDebug>
#include<QString>
#include "connexion.h"


Collaborateur::Collaborateur()
{
 id=0;
 marque="";
 adresse="";
 mail="";
 numero=0;
}

Collaborateur::Collaborateur(int id,QString marque,QString adresse,QString mail,int numero)
{
        this->id=id;
        this->marque=marque;
        this->adresse=adresse;
        this->mail=mail;
        this->numero=numero;
 }


void Collaborateur::setId(int id){this->id=id;}
void Collaborateur::setMarque(QString marque){this->marque=marque;}
void Collaborateur::setAdresse(QString adresse){this->adresse=adresse;}
void Collaborateur::setMail(QString mail){this->mail=mail;}



int Collaborateur::getId(){return id;}
QString Collaborateur::getMarque(){return marque;}
QString Collaborateur::getAdresse(){return adresse;}
QString Collaborateur::getMail(){return mail;}
int Collaborateur::getNumero(){return numero;}


bool Collaborateur::ajouter_collab()
{
QSqlQuery query;

QString res= QString::number(id);
query.prepare("INSERT INTO COLLABORATEURS (ID, MARQUE, ADRESSE,MAIL,NUMERO) "

                    "VALUES (:id,:marque,:adresse,:mail,:numero)");
query.bindValue(":id", res);
query.bindValue(":marque", marque);
query.bindValue(":adresse", adresse);
query.bindValue(":mail", mail);
query.bindValue(":numero", numero);

return    query.exec();

}


QSqlQueryModel* Collaborateur::afficher_collab()

{
    QSqlQueryModel* model= new QSqlQueryModel();
model->setQuery("select * from COLLABORATEURS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMERO"));

    return model;
}


bool Collaborateur::supprimer_collab(int id)
{
QSqlQuery query;

QString res= QString::number(id);

query.prepare("Delete from COLLABORATEURS where ID = :id ");

query.bindValue(":id", res);

return    query.exec();
}

bool Collaborateur::modifier_collab()
{
    QSqlQuery query ;
           QString res= QString::number(id);
           query.prepare("update COLLABORATEURS set MARQUE=:marque,ADRESSE=:adresse,MAIL=:mail,NUMERO=:numero where ID=:id ");

           query.bindValue(":id",res);
           query.bindValue(":marque",marque);
           query.bindValue(":adresse",adresse);
           query.bindValue(":mail",mail);
           query.bindValue(":numero",numero);

           return query.exec();
}


QSqlQueryModel* Collaborateur::trier_collab_id()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from COLLABORATEURS ORDER BY id");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMERO"));

        return model ;
}

QSqlQueryModel* Collaborateur::trier_collab_marque()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from COLLABORATEURS ORDER BY marque");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMERO"));

        return model ;
}

QSqlQueryModel* Collaborateur::trier_collab_adresse()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from COLLABORATEURS ORDER BY adresse");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMERO"));

        return model ;
}


QSqlQueryModel* Collaborateur::afficher_collaborateur(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("SELECT * FROM COLLABORATEURS WHERE ID=:id ");
    query.bindValue(":id", res);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMERO"));
return model ;
}





bool Collaborateur::rechercher_collab(int id)
{
    QSqlQuery query ;
        QString res = QString::number(id);
        query.prepare("SELECT ID FROM COLLABORATEURS WHERE ID=:id");
        query.bindValue(":id", res);
        query.exec();

        if(query.size()!=id){return false;}
        else return true;
}






