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
    FIndSmallest.cpp \
    WineryImplementation.cpp \
    WineImplementation.cpp \
    customtour.cpp \
    fulltour.cpp \
    shorttour.cpp \
    adminportal.cpp \
    intour.cpp

HEADERS  += mainwindow.h \
    Wine.h \
    List.h \
    Winery.h \
    customtour.h \
    fulltour.h \
    shorttour.h \
    adminportal.h \
    intour.h

FORMS    += customtour.ui \
    fulltour.ui \
    shorttour.ui \
    mainwindow.ui \
    adminportal.ui \
    intour.ui

RESOURCES += \
    Images.qrc

OTHER_FILES += \
