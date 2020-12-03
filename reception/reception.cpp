#include "reception.h"
#include <QDebug>

reception::reception()
{
   id_recep=0;
   ville="";
  date_recep="";
  salle_reservee="";
   nb_invite=0;
}

reception::reception(int id_recep,QString ville,QString date_recep,QQtring salle_reservee,int nb_invite )
{
  this->id_recep=id_recep;
this->ville=ville;
   this->date_recep=date_recep;
   his->salle_reservee=salle_reservee;
  this->nb_invite=nb_invite;

}
int reception::get_id_recep(){return  id_recep;}
QString reception::get_ville(){return  ville;}
QString reception::get_date_recep(){return  date_recep;}
QString reception::salle_reservee(){return  salle_reservee;}
int reception::nb_invite(){return  nb_invite;}

bool reception::ajouterR()
{

QSqlQuery query;
QString res= QString::int(id_recep);
query.prepare("INSERT INTO INVITE(ID_RECEP, VILLE, DATE , SALLE_RESERVEE , NOMBRE_INVITE)"
              "VALUES (:id_recep, :ville,:date_recep,:salle_reservee ,:nbinvite )");
query.bindValue(":id_recep", res);
query.bindValue(":ville", ville);
query.bindValue(":date_recep", date_recep);
query.bindValue(":salle_reservee", salle_reservee);
query.bindValue(":nb_invite", nb_invite);

return    query.exec();
}

QSqlQueryModel * reception::afficherR()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from RECEPTION");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RECEP"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("VILLE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_RECEP"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALLE_RESERVEE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NB_INVITE"));
    return model;
}

bool reception::supprimerI(int id_recep)
{
QSqlQuery query;
QString res= QString::int(id_recep);
query.prepare("Delete from INVITE where ID_REEP = :id_recep ");
query.bindValue(":id_recep", res);
return    query.exec();
}
bool reception::modifierR(reception r)
{
    QSqlQuery query;

       query.prepare("UPDATE RECEPTION SET VILLE =:ville , DATE_RECEP =:date_recep , SALLE_RESERVEE=: salle_reservee,NB_INVITE=:nb_invite, WHERE ID_RECEP =:id_recep ");
       query.bindValue(":id_recep", r.get_id_recep());
       query.bindValue(":ville", r.get_ville());
       query.bindValue(":date_recep", r.date_recep());
query.bindValue(":salle_reservee", r.salle_reservee());
query.bindValue(":nb_invite", r.nb_invite());
    return query.exec();

}


