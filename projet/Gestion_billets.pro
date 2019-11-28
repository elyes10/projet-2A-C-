QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport multimedia

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ajouter_billets.cpp \
    billet.cpp \
    connection.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    modifier_billets.cpp \
    qcustomplot.cpp \
    statistiques.cpp \
    supprimer_billets.cpp

HEADERS += \
    ajouter_billets.h \
    billet.h \
    connection.h \
    dialog.h \
    mainwindow.h \
    modifier_billets.h \
    qcustomplot.h \
    statistiques.h \
    supprimer_billets.h

FORMS += \
    ajouter_billets.ui \
    dialog.ui \
    mainwindow.ui \
    modifier_billets.ui \
    statistiques.ui \
    supprimer_billets.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
