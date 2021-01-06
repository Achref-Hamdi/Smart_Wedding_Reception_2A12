QT       += core gui sql printsupport multimedia serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accueil.cpp \
    arduino.cpp \
    categorie.cpp \
    client.cpp \
    collab_categorie.cpp \
    collaborateur.cpp \
    connexion.cpp \
    employe_fiche.cpp \
    employes.cpp \
    fiches.cpp \
    invite.cpp \
    invite_reception.cpp \
    main.cpp \
    dialog.cpp \
    reception.cpp \
    reservation.cpp \
    statistique.cpp

HEADERS += \
    accueil.h \
    arduino.h \
    categorie.h \
    client.h \
    collab_categorie.h \
    collaborateur.h \
    connexion.h \
    dialog.h \
    employe_fiche.h \
    employes.h \
    fiches.h \
    invite.h \
    invite_reception.h \
    reception.h \
    reservation.h \
    statistique.h

FORMS += \
    accueil.ui \
    collab_categorie.ui \
    dialog.ui \
    employe_fiche.ui \
    invite_reception.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc
