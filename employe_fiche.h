#ifndef EMPLOYE_FICHE_H
#define EMPLOYE_FICHE_H
#include"arduino.h"
#include "employes.h"
#include "fiches.h"
#include <QMainWindow>
#include <QPainter>
#include <QPrintDialog>
#include <QPrinter>
#include<QDebug>
#include"arduino.h"

#include <QDialog>

namespace Ui {
class employe_fiche;
}

class employe_fiche : public QDialog
{
    Q_OBJECT

public:
    explicit employe_fiche(QWidget *parent = nullptr);
     void update_label();
    ~employe_fiche();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_modif_clicked();

    void on_pushButton_modi_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_imprimer_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_ajout_fiches_clicked();

    void on_pushButton_supp_fiches_clicked();

    void on_pushButton_modif_fiche_clicked();
  void readdata();
   void detect();
   void detect2();


    void on_pushButton_close_clicked();

    void on_pushButton_open_destroyed();

    void on_pushButton_close_2_clicked();

    void on_pushButton_moin_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::employe_fiche *ui;
    Employes tmpEmpl;
    Fiches tmp;
  arduino Ard;
          QByteArray data1;
          QByteArray data2;
};

#endif // EMPLOYE_FICHE_H
