#-------------------------------------------------
#
# Project created by QtCreator 2015-02-12T19:47:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RapeGrape
TEMPLATE = app

SOURCES += adminportal.cpp \
    FIndSmallest.cpp \
    main.cpp \
    mainwindow.cpp \
    intour.cpp \
    WineImplementation.cpp \
    WineryImplementation.cpp \
    shorttour.cpp \
    customtour.cpp \
    newwine.cpp \
    responsewindow.cpp \
    adminlogin.cpp \
    instructions.cpp \
    end.cpp \
    fulltour.cpp

HEADERS  += mainwindow.h \
    adminportal.h \
    Winery.h \
    Wine.h \
    List.h \
    intour.h \
    shorttour.h \
    customtour.h \
    newwine.h \
    responsewindow.h \
    adminlogin.h \
    instructions.h \
    end.h \
    fulltour.h

FORMS    += adminportal.ui \
    mainwindow.ui \
    intour.ui \
    shorttour.ui \
    customtour.ui \
    newwine.ui \
    responsewindow.ui \
    adminlogin.ui \
    instructions.ui \
    end.ui \
    fulltour.ui

RESOURCES += \
