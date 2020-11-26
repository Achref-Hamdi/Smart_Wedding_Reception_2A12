#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "collaborateur.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->tabcollaborateur->setModel(tmpcollaborateur.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}


/*

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString marque = ui->lineEdit_marque->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString mail = ui->lineEdit_mail->text();
    int num = ui->lineEdit_num->text().toInt();

    Collaborateur c(id, marque, adresse, mail, num);
    bool test= c.ajouter_collab();
    if(test)
    {
        ui->tabcollaborateur->setModel(tmpcollaborateur.afficher_collab());        // refresh

        QMessageBox::information(nullptr, QObject::tr("Ajouter un collaborateur"),
                                 QObject::tr("Collaborateur ajouté. \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un collaborateur"),
                                 QObject::tr("Erreur ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}







void MainWindow::on_pb_supprimer_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    bool test=tmpcollaborateur.supprimer_collab(id);
    if(test)
    {
        ui->tabcollaborateur->setModel(tmpcollaborateur.afficher_collab());         // refresh
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






