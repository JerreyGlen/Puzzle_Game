QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    form.cpp \
    form1.cpp \
    form2.cpp \
    form3.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    form.h \
    form1.h \
    form2.h \
    form3.h \
    mainwindow.h

FORMS += \
    form.ui \
    form1.ui \
    form2.ui \
    form3.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target