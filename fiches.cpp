#include "fiches.h"
#include "dialog.h"
Fiches::Fiches()
{

    idf=0;
    fonction="";
    salaire=0;
    dateE="";
    nba=0;

    connexion c;
    bool v=c.createconnect();



}

Fiches::Fiches(int id_em,QString fonction_em,int salaire_em,QString dateE_em,int nba_em)
{
    this->idf=id_em;
    this->fonction=fonction_em;
    this->salaire=salaire_em;
    this->dateE=dateE_em;
    this->nba=nba_em;
}

bool Fiches::ajouterF(){
    QSqlQuery query ;
    QString res=QString::number(idf);
    QString res1=QString::number(nba);
    QString res2=QString::number(salaire);
    query.prepare("INSERT INTO Fiches " "VALUES(:res,:fonction,:salaire,:dateE,:nba)");
    query.bindValue(":res",res);
    query.bindValue(":fonction",fonction);
    query.bindValue(":salaire",res2);

    query.bindValue(":dateE",dateE);
    query.bindValue(":nba",res1);
    return query.exec();

}


QSqlQueryModel * Fiches::afficherF()
 {
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from Fiches");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("Fonction"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("Salaire"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date d'embauche"));
     // model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nba"));


      return model;
}

bool Fiches::supprimerF(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);//ids ide
    query.prepare("Delete from Fiches where   idf=:idf ");//id id
    query.bindValue(":idf", res);//id ids
    return  query.exec();
}
bool Fiches::modifierF(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);

    query.prepare("UPDATE Fiches SET IDF= :idf , fonction= :fonction , salaire = :salaire , dateE = :dateE , nba = :nba WHERE IDF= :idf");

    query.bindValue(":idf",res);
    query.bindValue(":fonction",fonction);
    query.bindValue(":salaire",salaire);

    query.bindValue(":dateE",dateE);
    query.bindValue(":nba",nba);

    return query.exec();

}

