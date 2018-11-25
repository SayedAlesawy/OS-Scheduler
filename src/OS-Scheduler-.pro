#-------------------------------------------------
#
# Project created by QtCreator 2018-11-04T22:10:31
#
#-------------------------------------------------

QT       += core gui widgets charts

TARGET = OS-Scheduler-
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    ProcessGenerator.cpp \
    Source.cpp \
    IO.cpp \
    SchedulerFCFS.cpp \
    TaskManager.cpp \
    Broadcaster.cpp \
    Scheduler.cpp \
    SchedulerHPF.cpp \
    SchedulerRR.cpp \
    SchedulerSRTN.cpp \
    Main.cpp \
    MainWindow.cpp \
    StatsDialog.cpp

HEADERS += \
    Process.h \
    ProcessGenerator.h \
    Scheduler.h \
    GenerationParams.h \
    IO.h \
    Broadcaster.h \
    SchedulerFCFS.h \
    TaskManager.h \
    Event.h \
    SchedulerHPF.h \
    SchedulerRR.h \
    Subscriber.h \
    SchedulerSRTN.h \
    MainWindow.h \
    StatsDialog.h \
    ProcessStat.h

FORMS += \
    mainwindow.ui \
    statsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    OS-Scheduler-.pro \
    OS-Scheduler-.pro

DISTFILES += \
    OS-Scheduler-.pro.user \
    OS-Scheduler-.pro.user
