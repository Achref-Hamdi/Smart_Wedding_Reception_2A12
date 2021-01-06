#ifndef FICHES_H
#define FICHES_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "ui_employe_fiche.h"
#include<QString>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<QFileInfo>
#include<QMessageBox>
#include<QSqlQueryModel>
#include<QDebug>
#include<QFileDialog>
#include<QDialog>

#include "connexion.h"
class Fiches
{
public:
    Fiches();
    Fiches(int,QString,int,QString,int);

    //Getters
    int getID(){return idf;}
    QString getfonction(){return  fonction;}
    int getsalaire(){return salaire;}
    QString getdateE(){return dateE;}
    int getnba(){return nba;}

    //fonctionalités de bases relatives a l'entité Employés
    bool ajouterF();
    QSqlQueryModel *afficherF();
    bool supprimerF(int);
    bool modifierF(int);
//bool supprimer(Ui::MainWindow *ui);


private:
     int idf,nba,salaire;
     QString fonction,dateE;
     //float salaire;
     bool v;
};


#endif // FICHES_H
