QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    scene.cpp \
    tool.cpp \
    toolwindow.cpp \
    widget.cpp

HEADERS += \
    mainwindow.h \
    scene.h \
    tool.h \
    toolwindow.h \
    widget.h

FORMS += \
    mainwindow.ui \
    toolwindow.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/1.1.png \
    images/1.1a.png \
    images/1.1b.png \
    images/1.1.001.png \
    images/1.1.002.png \
    images/1.4.001.png \
    images/1.2.png \
    images/1.2.001.png \
    images/1.2.002.png \
    images/1.4.png \
    images/1.4.001.png \
    images/2.1.png \
    images/2.2.png \
    images/2.3.png \
    images/2.4.png \
    images/2.4.001.png \
    images/3.1.png \
    images/3.1.001.png \
    images/3.2.png \
    images/3.2.001.png \
    images/3.3.1.png \
    images/3.3.1.001.png \
    images/3.3.2.png \
    images/3.3.2.001.png \
    images/3.4.1.png \
    images/3.4.2.png \
    images/3.4.2.001.png \
    images/3.4.2.002.png \
    images/3.4.2.003.png \
    images/3.5.1.png \
    images/3.5.1.001.png \
    images/3.5.2.png \
    images/3.5.2.001.png \
    images/3.5.3.png \
    images/4.1.png \
    images/4.1.001.png \
    images/4.2.png \
    images/4.3.png \
    images/5.1.png \
    images/5.1.001.png \
    images/tools.png \
    images/menu.png \
    images/green_key.png \
    images/gray_key.png \
    images/tools_10.png \
    images/pink_key.png \
    images/blue_key.png \
    images/yellow_key.png \
    images/lighter.png \
    images/meat.png \
    images/plane.png \
    images/silver_key.png \
    images/stick.png \
    images/signal.png



RESOURCES += \
    Resources.qrc
