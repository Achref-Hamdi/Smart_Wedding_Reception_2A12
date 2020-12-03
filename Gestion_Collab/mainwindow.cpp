#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "collaborateur.h"
#include "categorie.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);

ui->tabcollaborateur->setModel(tmpcollaborateur.afficher_collab());
ui->tabcategorie->setModel(tmpcategorie.afficher_cat());

connect(ui->pb_ajouter, SIGNAL(clicked(bool)), this, SLOT(on_pb_ajouter_clicked())); //ajout

connect(ui->pb_supprimer, SIGNAL(clicked(bool)), this, SLOT(on_pb_supprimer_clicked())); //suppr

connect(ui->pb_modifier_collab, SIGNAL (clicked(bool)), this, SLOT(on_pb_modifier_collab_clicked())); //modif


connect(ui->pb_rechercher_id, SIGNAL (clicked(bool)), this, SLOT(on_pb_rechercher_id_clicked()));



connect(ui->radioB_tri_id, SIGNAL (clicked(bool)), this, SLOT(on_radioB_tri_id_clicked()));
connect(ui->radioB_tri_marque, SIGNAL (clicked(bool)), this, SLOT(on_radioB_tri_marque_clicked()));
connect(ui->radioB_tri_adresse, SIGNAL (clicked(bool)), this, SLOT(on_radioB_tri_adresse_clicked()));

connect(ui->pb_ajouter_cat, SIGNAL(clicked(bool)), this, SLOT(on_pb_ajouter_cat_clicked()));

connect(ui->pb_supprimer_cat, SIGNAL(clicked(bool)), this, SLOT(on_pb_supprimer_cat_clicked()));

connect(ui->pb_modifier_cat, SIGNAL (clicked(bool)), this, SLOT(on_pb_modifier_cat_clicked()));

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id_collab->text().toInt();
     QString marque= ui->lineEdit_marque_collab->text();
     QString adresse= ui->lineEdit_adresse_collab->text();
     QString mail= ui->lineEdit_mail_collab->text();
     int numero = ui->lineEdit_numero_collab->text().toInt();

    Collaborateur c(id,marque,adresse,mail,numero);
    bool test=c.ajouter_collab();
    ui->tabcollaborateur->setModel(tmpcollaborateur.afficher_collab());

    if(test){
        foreach(QLineEdit* le, findChildren<QLineEdit*>())
        { le->clear(); }

      QMessageBox::information(this, QObject::tr("Ajouter un collaborateur"),
      QObject::tr(" collaborateur ajouté.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::information(this, QObject::tr("Ajouter un collaborateur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
  }

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_collab_2->text().toInt();
bool test=tmpcollaborateur.supprimer_collab(id);
ui->tabcollaborateur->setModel(tmpcollaborateur.afficher_collab());//refresh

 if(test){
foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
     le->clear();}

QMessageBox::information(this, QObject::tr("Supprimer un Collaborateur"),
        QObject::tr("Collaborateur supprimé.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);

}else
QMessageBox::information(this, QObject::tr("Supprimer un Collaborateur"),
        QObject::tr("Erreur !.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pb_modifier_collab_clicked()
{
     int id = ui->lineEdit_id_collab_3->text().toInt();
     QString marque= ui->lineEdit_marque_collab_3->text();
     QString adresse= ui->lineEdit_adresse_collab_3->text();
     QString mail= ui->lineEdit_mail_collab_3->text();
     int numero = ui->lineEdit_numero_collab_3->text().toInt();

    Collaborateur c(id,marque,adresse,mail,numero);

     bool test=c.modifier_collab();
     ui->tabcollaborateur->setModel(tmpcollaborateur.afficher_collab());

     if (test)
     {
         foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
              le->clear();}
         QMessageBox::information(this, QObject::tr("Modifier un Collaborateur"),
                 QObject::tr("Collaborateur modifié.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

     }else
         QMessageBox::critical(this, QObject::tr("Modifier un Collaborateur"),
                 QObject::tr("Erreur !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_ajouter_cat_clicked()
{
     int id = ui->lineEdit_id_cat->text().toInt();
     QString date_Dc= ui->lineEdit_DC_cat->text();
     QString date_Fc= ui->lineEdit_FC_cat->text();
     QString domaine= ui->lineEdit_domaine_cat->text();

    Categorie c(id,date_Dc,date_Fc,domaine);
    bool test=c.ajouter_cat();
    ui->tabcategorie->setModel(tmpcategorie.afficher_cat());

    if(test){
        foreach(QLineEdit* le, findChildren<QLineEdit*>())
        { le->clear(); }

      QMessageBox::information(this, QObject::tr("Ajouter une Catégorie"),
      QObject::tr(" Catégorie ajoutée.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::information(this, QObject::tr("Ajouter une Catégorie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pb_supprimer_cat_clicked()
{
    int id = ui->lineEdit_id_cat_2->text().toInt();
    bool test=tmpcategorie.supprimer_cat(id);
    ui->tabcategorie->setModel(tmpcategorie.afficher_cat());

     if(test){
    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
         le->clear();}

    QMessageBox::information(this, QObject::tr("Supprimer une Catégorie"),
            QObject::tr("Catégorie supprimée.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

    }else
    QMessageBox::information(this, QObject::tr("Supprimer un Catégorie"),
            QObject::tr("Erreur !.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_modifier_cat_clicked()
{
    int id = ui->lineEdit_id_cat_3->text().toInt();
    QString date_Dc= ui->lineEdit_DC_cat_3->text();
    QString date_Fc= ui->lineEdit_FC_cat_3->text();
    QString domaine= ui->lineEdit_domaine_cat_3->text();

   Categorie c(id,date_Dc,date_Fc,domaine);

    bool test=c.modifier_cat();
    ui->tabcategorie->setModel(tmpcategorie.afficher_cat());

    if (test)
    {
        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
             le->clear();}
        QMessageBox::information(this, QObject::tr("Modifier une Catégorie"),
                QObject::tr("Catégorie modifiée.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    }else
        QMessageBox::critical(this, QObject::tr("Modifier une Catégorie"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_radioB_tri_id_clicked()
{
    ui->tabcollaborateur->setModel(tmpcollaborateur.afficher_collab());
    ui->tabcollaborateur->setModel(tmpcollaborateur.trier_collab_id());
}

void MainWindow::on_radioB_tri_marque_clicked()
{
    ui->tabcollaborateur->setModel(tmpcollaborateur.afficher_collab());
    ui->tabcollaborateur->setModel(tmpcollaborateur.trier_collab_marque());
}


void MainWindow::on_radioB_tri_adresse_clicked()
{
    ui->tabcollaborateur->setModel(tmpcollaborateur.afficher_collab());
    ui->tabcollaborateur->setModel(tmpcollaborateur.trier_collab_adresse());
}



void MainWindow::on_pb_rechercher_id_clicked()
{
    int id = ui->lineEdit_id_collab_4->text().toInt();
    ui->collab_trouve->setModel(tmpcollaborateur.afficher_collaborateur(id));
}




/*

void MainWindow::on_pb_rechercher_marque_clicked()
{

}

void MainWindow::on_pb_rechercher_adresse_clicked()
{

}
*/
