#-------------------------------------------------
#
# Project created by QtCreator 2016-09-01T08:21:42
#
#-------------------------------------------------

QMAKE_CXXFLAGS += -std=c++11 -DTEST1

QT       += core gui
#win32:RC_FILE = t.rc

#LINUX
unix {
    message("*using settings for linux")
}
#
#ANDROID
android {
    message("*using settigs for android")

}

#WINDOWS
win32 {
    message("*using settings for windows")
    message ("$$PWD/tipro")

#INCLUDEPATH += C:\\Users\\ilian\\Documents\\tipro-lib\\tipro
#LIBS += -LC:\\Users\\ilian\\Documents\\tipro-lib\\tipro -lTiproHidApi
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



SOURCES += \
    tipro-widget.cpp \
    main.cpp \
    tipro-lib.cpp

TEMPLATE = app

HEADERS += \
    tipro-widget.h \
    tipro-lib.h \
    types.h
