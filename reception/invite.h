#ifndef INVITE_H
#define INVITE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class invite
{
public:
   invite();
    invite(int ,int ,int);

    int get_id_inv();
    int get_nbplacereservee();
    int get_num_table();

    bool ajouterI();
    bool modifierI(invite i);
    QSqlQueryModel * afficherI();

    bool supprimerI(int);
QSqlQueryModel * rechercherI();


private :
    int id_inv;
    int nbplacereservee;
    int nume_table;

};

#endif // INVITE_H
