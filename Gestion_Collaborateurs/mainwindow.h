#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "collaborateur.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Collaborateur tmpcollaborateur;
};
#endif // MAINWINDOW_H
