#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QDialog>
#include<dialog.h>
#include"collab_categorie.h"
#include"employe_fiche.h"
#include"invite_reception.h"
#include<QPropertyAnimation>

namespace Ui {
class accueil;
}

class accueil : public QDialog
{
    Q_OBJECT

public:
    explicit accueil(QWidget *parent = nullptr);
    ~accueil();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::accueil *ui;
    Dialog *dialog;
    collab_categorie *Collab_categorie;
    employe_fiche *employe ;
    invite_reception *Invite_reception;
    QPropertyAnimation *animation;




};

#endif // ACCUEIL_H
