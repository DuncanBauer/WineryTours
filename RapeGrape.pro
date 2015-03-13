#-------------------------------------------------
#
# Project created by QtCreator 2015-02-12T19:47:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RapeGrape
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    shorttour.cpp \
    main.cpp \
    mainwindow.cpp \
    customtour.cpp \
    fulltour.cpp

HEADERS  += mainwindow.h \
    shorttour.h \
    mainwindow.h \
    Wine.h \
    List.h \
    customtour.h \
    fulltour.h

FORMS    += \
    shorttour.ui \
    mainwindow.ui \
    customtour.ui \
    fulltour.ui

RESOURCES += \
    Images.qrc
