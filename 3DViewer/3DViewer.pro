include(./QtGifImage/src/gifimage/qtgifimage.pri)
QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


#QMAKE_CXXFLAGS += -Wno-enum-compare

DESTDIR = ../../build/
OBJECTS_DIR = ../../build/obj
TARGET = 3DViewer

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    oglviewerwidget.cpp \
    source/afin.c \
    source/parser.c

HEADERS += \
    mainwindow.h \
    oglviewerwidget.h \
    source/parser.h \
    source/afin.h \
    source/models.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
