QT       += core gui sql printsupport multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accueil.cpp \
    client.cpp \
    connexion.cpp \
    main.cpp \
    dialog.cpp \
    reservation.cpp \
    statistique.cpp

HEADERS += \
    accueil.h \
    client.h \
    connexion.h \
    dialog.h \
    reservation.h \
    statistique.h

FORMS += \
    accueil.ui \
    dialog.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc