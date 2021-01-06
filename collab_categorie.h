#ifndef COLLAB_CATEGORIE_H
#define COLLAB_CATEGORIE_H
#include "collaborateur.h"
#include <QSqlQuery>
#include <QMainWindow>
#include "connexion.h"
#include <QDialog>
#include"categorie.h"

namespace Ui {
class collab_categorie;
}

class collab_categorie : public QDialog
{
    Q_OBJECT

public:
    explicit collab_categorie(QWidget *parent = nullptr);
    ~collab_categorie();

private slots:
private slots:

    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_collab_clicked();

    void on_pb_ajouter_cat_clicked();
    void on_pb_supprimer_cat_clicked();
    void on_pb_modifier_cat_clicked();

    void on_radioB_tri_id_clicked();
    void on_radioB_tri_marque_clicked();
    void on_radioB_tri_adresse_clicked();


    void on_pb_rechercher_id_clicked();
    void on_pb_rechercher_marque_clicked();
    void on_pb_rechercher_adresse_clicked();


    void on_pb_imprimer_clicked();
    void on_pushButton_10_clicked();

private:
    Ui::collab_categorie *ui;

    Collaborateur tmpcollaborateur;
        Categorie tmpcategorie;

};

#endif // COLLAB_CATEGORIE_H
