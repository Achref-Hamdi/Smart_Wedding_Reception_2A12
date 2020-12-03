#include "mainwindow.h"
#include<QApplication>
#include <QMessageBox>
#include<QDebug>
#include"connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection c ;
    bool test=c.createConnection();
    if(test)
// w.show();

           // qDebug() <<"Connection reussite";
                     QMessageBox::information(nullptr,QObject::tr("database is open "),
                               QObject::tr("connection successful\n"
                                           "click ok to exit"),QMessageBox::Ok);




        else
           // qDebug()<<"erreur de connexion";
                             QMessageBox::critical(nullptr,QObject::tr("database is not open "),
                                        QObject::tr("connection failed \n"
                                                     "click cancel to exit"),QMessageBox::Cancel);
            return a.exec();
        }
