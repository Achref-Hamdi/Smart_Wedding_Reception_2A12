#include "mainwindow.h"
#include"connection.h"
#include <QDebug>
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection C;
    bool test=C.ouvrirConnection();
    if(test)
    QMessageBox::information(nullptr , QObject::tr("database is open"),
                                    QObject::tr("Connection successful ! \n"
                                                "click Ok to exist"), QMessageBox::Ok);
    else
    QMessageBox::critical(nullptr , QObject::tr("database is not open"),
                                    QObject::tr("Connection failed ! \n"
                                                "click Cancel to exist"), QMessageBox::Cancel);

    return a.exec();
}
