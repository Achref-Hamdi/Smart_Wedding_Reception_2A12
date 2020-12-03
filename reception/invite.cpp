#include "invite.h"
#include <QDebug>

invite::invite()
{
   id_inv=0;
   nbplacereservee=0;
   num_table=0;
}

invite::invite(int id_inv,int nbplacereservee ,  int num_table )
{
  this->id_inv=id_inv;
  this->nbplacereservee=nbplacereservee;
  this->num_table=num_table;

}
int invite::get_nbplacereservee(){return  nbplacereservee;}
int invite::id_inv(){return  id_inv;}
int invite::num_table(){return  num_table;}

bool invite::ajouterI()
{

QSqlQuery query;
QString res= QString::int(id_inv);
query.prepare("INSERT INTO INVITE(ID_INV, NOMBRE_DE_PLACE_RESERVE, NUMERO_TABLE)"
              "VALUES (:id_inv,  :nbplacereservee,:num_table )");
query.bindValue(":id_inv", res);
query.bindValue(":nbplacereservee", nbplacereservee);
query.bindValue(":num_table", num_table);

return    query.exec();
}

QSqlQueryModel * invite::afficherI()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from INVITE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_INV"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE_DE_PLACE_RESERVE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO_TABLE"));
    return model;
}

bool invite::supprimerI(int id_inv)
{
QSqlQuery query;
QString res= QString::int(id_inv);
query.prepare("Delete from INVITE where ID_INV = :id_inv ");
query.bindValue(":id_inv", res);
return    query.exec();
}
bool invite::modifierI(invite i)
{
    QSqlQuery query;

       query.prepare("UPDATE INVITE SET NOMBRE_DE_PLACE_RESERVE =:nbplacereservee  , NUMERO_TABLE =:num_table , WHERE ID_INV =:id_inv ");
       query.bindValue(":id_inv", i.get_id_inv());
       query.bindValue(":nbplacereservee", p.get_nbplacereservee());
       query.bindValue(":num_table", I.get_num_table());
    return query.exec();
}
QSqlQueryModel *invite::rechercher_invite(const QString &id_inv)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from dep where(ID_INV LIKE '"+id_inv+"%')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_INV"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE DE PLACE RESERVEE"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMERO_TABLE"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMBRE_DES_MEMBRES"));
   return model;
}

