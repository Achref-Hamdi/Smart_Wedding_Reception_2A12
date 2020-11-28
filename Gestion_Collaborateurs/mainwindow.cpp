#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "collaborateur.h"
#include <QMessageBox>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpcollaborateur.afficher_collab());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
    int id = ui->lineEdit_id_collab->text().toInt();
    QString marque = ui->lineEdit_marque_collab->text();
    QString adresse = ui->lineEdit_adresse_collab->text();
    QString mail = ui->lineEdit_mail_collab->text();
    int num = ui->lineEdit_num_collab->text().toInt();

    Collaborateur c(id, marque, adresse, mail, num);
    bool test= c.ajouter_collab();
    if(test)
    {
        ui->tableView->setModel(tmpcollaborateur.afficher_collab());

        QMessageBox::information(nullptr, QObject::tr("Ajouter un collaborateur"),
                                 QObject::tr("Collaborateur ajouté. \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un collaborateur"),
                                 QObject::tr("Erreur ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}


















/*
void MainWindow::on_supprimer_clicked()
{
    int id = ui->lineEdit_id_collab_2->text().toInt();
    bool test=tmpcollaborateur.supprimer_collab(id);
    if(test)
    {
        ui->tableView->setModel(tmpcollaborateur.afficher_collab());
        QMessageBox::information(nullptr, QObject::tr("supprimer un collaborateur"),
                                 QObject::tr("Collaborateur supprimé. \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer un collaborateur"),
                                 QObject::tr("Erreur ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}



*/



/*
void MainWindow::on_modifier_clicked()
{
    int id = ui->lineEdit_id_collab_2->text().toInt();
    QString marque = ui->lineEdit_marque_collab_2->text();
    QString adresse = ui->lineEdit_adresse_collab_2->text();
    QString mail = ui->lineEdit_mail_collab_2->text();
    int num = ui->lineEdit_num_collab_2->text().toInt();

    void modifier_collab();

    ui->tabCollaborateur->setModel(tmpcollaborateur.afficher_collab());
    QMessageBox::information(nullptr, QObject::tr("modifier collaborateur"),
                             QObject::tr("Collaborateur modifié. \n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

}




void MainWindow::on_rechercher_clicked()
{
    int id = ui->lineEdit_id_collab_2->text().toInt();



}

*/


