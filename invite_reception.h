#ifndef INVITE_RECEPTION_H
#define INVITE_RECEPTION_H
#include"reception.h"
#include"invite.h"

#include <QDialog>

namespace Ui {
class invite_reception;
}

class invite_reception : public QDialog
{
    Q_OBJECT

public:
    explicit invite_reception(QWidget *parent = nullptr);
    ~invite_reception();
private slots:
  void on_ajouter_clicked();
  void on_supprimer_clicked();
  void on_modifier_clicked();
  void on_imprimer_clicked();
  void on_ajouterr_clicked();
  void on_supprimerr_clicked();
  void on_modifierr_clicked();
  void on_rechercher_clicked();

  void on_pushButton_10_clicked();

private:
    Ui::invite_reception *ui;
    reception tmpreception  ;
        invite tmpinvite  ;
};

#endif // INVITE_RECEPTION_H
