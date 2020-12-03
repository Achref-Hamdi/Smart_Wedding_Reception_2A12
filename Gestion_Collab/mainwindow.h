#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "collaborateur.h"
#include "categorie.h"
#include <QSqlQuery>
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "connexion.h"

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

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
    //void on_pb_rechercher_marque_clicked();
    //void on_pb_rechercher_adresse_clicked();

private:

    Ui::MainWindow *ui;

    Collaborateur tmpcollaborateur;
    Categorie tmpcategorie;
};



#endif // MAINWINDOW_H
