#ifndef RECEPTION_H
#define RECEPTION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class reception
{
public:
   reception();
    reception(int ,Qstring,Qstring,Qstring ,int);

    int get_id_recep();
    QString get_ville();
    QString get_date_recep();
    QString get_salle_reservee();
    int get_nb_invite();

    bool ajouterR();
    bool modifierR(reception r);
    QSqlQueryModel * afficherR();
    bool supprimerR(int);


private :
     int id_recep();
    QString ville();
    QString date_recep();
    QString salle_reservee();
    int nb_invite();
};

#endif // INVITE_H
