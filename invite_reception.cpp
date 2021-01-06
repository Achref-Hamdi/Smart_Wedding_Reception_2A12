#include "invite_reception.h"
#include "ui_invite_reception.h"
#include"invite.h"
#include"reception.h"
#include <QMessageBox>
#include <QPushButton>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/qprintdialog.h>
#include <QPainter>
#include<QDialog>
#include<QSqlQuery>

invite_reception::invite_reception(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::invite_reception)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpreception.afficher_reception());
       ui->tableView_2->setModel(tmpinvite.afficher_invite());

}

invite_reception::~invite_reception()
{
    delete ui;
}

void invite_reception::on_ajouter_clicked()
{
    int id_recep = ui->lineEdit_id_recep->text().toInt();
    QString ville_recep = ui->lineEdit_ville_recep->text();

    QString salle_reservee = ui->lineEdit_salle_reservee->text();
    int nombre_des_invites = ui->lineEdit_nombre_des_invites->text().toInt();

    reception r(id_recep, ville_recep, salle_reservee, nombre_des_invites);




bool test= r.ajouter_reception();
    if(test)
    {

        ui->tableView->setModel(tmpreception.afficher_reception());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("reception ajoutée. \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                 QObject::tr("reception non-ajoutéé ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}


void invite_reception::on_supprimer_clicked()
{
    int id_recep = ui->lineEdit_supprimer->text().toInt();
    bool test=tmpreception.supprimer_reception(id_recep);
    if(test)
    {
ui->tableView->setModel(tmpreception.afficher_reception());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("reception supprimée. \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                 QObject::tr("reception n'existe pas ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}


void invite_reception::on_modifier_clicked()
{

    int id_recep = ui->lineEdit_id_recep->text().toInt();
    QString ville_recep = ui->lineEdit_ville_recep->text();

    QString salle_reservee = ui->lineEdit_salle_reservee->text();
    int nombre_des_invites = ui->lineEdit_nombre_des_invites->text().toInt();

    reception r(id_recep, ville_recep, salle_reservee, nombre_des_invites);
       bool test= r.modifier_reception(id_recep);
         if (test)
         {
             ui->tableView->setModel(tmpreception.afficher_reception());
             QMessageBox::information(nullptr,QObject::tr("Modifier une reception"),
                                              QObject::tr("reception Modifiée .\n"
                                                          "Click Cancel to exit ."),QMessageBox::Cancel);

          }
     else
     {
             QMessageBox::critical(nullptr,QObject::tr("Modifier une reception"),
                                              QObject::tr("Erreur.\n"
                                                          "Click Cancel to exit ."),QMessageBox::Cancel);
        }


}


void invite_reception::on_imprimer_clicked()
{
   QString num1 = ui->lineEdit1->text();
    int num = ui->lineEdit1->text().toInt();

    QSqlQuery query1;
   QString id_recep="";
   QString ville_recep="";
    QString salle_reservee="";
   QString   nombre_des_invites="";

    if(num1!=""){
    query1.prepare("select * from reception where ID_RECEP=:id_recep");
   query1.bindValue(":id_recep", num);

    if (query1.exec())
    {

        while (query1.next()) {

             id_recep = query1.value(0).toString();
             ville_recep = query1.value(1).toString();
             salle_reservee = query1.value(2).toString();
             nombre_des_invites = query1.value(3).toString();


        }
    }
          QPrinter printer(QPrinter::HighResolution);
              printer.setPageSize(QPrinter::A4);
             QPrintDialog *dialog = new QPrintDialog(&printer);
              if (dialog->exec() == QDialog::Accepted)
              {               QPainter painter (&printer);
                              painter.begin(&printer);
                              QFont f;
                               f.setPointSize(20);
                               f.setBold(true);
                               painter.setFont(f);
                               painter.drawText(100, 500, " la fiche du reception,num°:");
                               painter.drawText(2000, 520, id_recep);
                               f.setPointSize(15);
                               f.setBold(true);
                               painter.setFont(f);
                               painter.drawText(100, 1000, "ville_recep :");
                               painter.drawText(1000, 1000, ville_recep);
                               painter.drawText(100, 1200, "salle_reservee :");
                               painter.drawText(1200, 1200, salle_reservee);
                               painter.drawText(100, 1400, "nombre_des_invites :");
                               painter.drawText(1500, 1400, nombre_des_invites);


                              painter.end();

              }}
    else
        QMessageBox::critical(nullptr, QObject::tr("Imprimer une reception"),
                    QObject::tr("Erreur !.\n"
                                "Veuillez selectionner une reception à imprimer .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void invite_reception::on_ajouterr_clicked()
{
    int id_inv = ui->lineEdit_id_inv->text().toInt();
    int nombre_de_places_reserves = ui->lineEdit_nomre_de_places_reserves->text().toInt();
    int numero_table = ui->lineEdit_numero_table->text().toInt();

    QString mail_invite = ui->lineEdit_mail_invite->text();

    invite i(id_inv, nombre_de_places_reserves, numero_table, mail_invite);




bool test= i.ajouter_invite();
    if(test)
    {

        ui->tableView_2->setModel(tmpinvite.afficher_invite());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("invite ajouté. \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                 QObject::tr("invite non-ajouté ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}


void invite_reception::on_supprimerr_clicked()
{
    int id_inv = ui->lineEdit_supprimer_2->text().toInt();
    bool test=tmpinvite.supprimer_invite(id_inv);
    if(test)
    {
        ui->tableView_2->setModel(tmpinvite.afficher_invite());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("invite supprimé. \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                 QObject::tr("invite n'existe pas ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

}


void invite_reception::on_modifierr_clicked()
{
    int id_inv = ui->lineEdit_id_inv->text().toInt();
    int nombre_de_places_reserves = ui->lineEdit_nomre_de_places_reserves->text().toInt();
    int numero_table = ui->lineEdit_numero_table->text().toInt();

    QString mail_invite = ui->lineEdit_mail_invite->text();

    invite i(id_inv, nombre_de_places_reserves, numero_table, mail_invite);

       bool test= i.modifier_invite(id_inv);
         if (test)
         {
             ui->tableView_2->setModel(tmpinvite.afficher_invite());
             QMessageBox::information(nullptr,QObject::tr("Modifier un invite"),
                                              QObject::tr("invite Modifié .\n"
                                                          "Click Cancel to exit ."),QMessageBox::Cancel);

          }
     else
     {
             QMessageBox::critical(nullptr,QObject::tr("Modifier un invite"),
                                              QObject::tr("Erreur.\n"
                                                          "Click Cancel to exit ."),QMessageBox::Cancel);
        }


}

void invite_reception::on_rechercher_clicked()
{
int id_inv = ui->lineEdit_rechercher_invite->text().toInt();
ui->tableView_2->setModel(tmpinvite.afficher_invite(id_inv));

}


void invite_reception::on_pushButton_10_clicked()
{
    hide();
}
