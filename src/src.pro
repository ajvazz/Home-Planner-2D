QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = src
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

# Disables all the APIs deprecated before Qt 6.0.0
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

CONFIG += c++11

SOURCES += \
        source/main.cpp \
        source/main_menu_window.cpp \
        source/template_window.cpp \
        source/design_window.cpp \
        source/centered_window.cpp \
        source/furniture.cpp

HEADERS += \
        headers/main_menu_window.hpp \
        headers/template_window.hpp \
        headers/design_window.hpp \
        headers/centered_window.hpp \
        headers/furniture.hpp

FORMS += \
        ui/main_menu_window.ui \
        ui/template_window.ui \
        ui/design_window.ui \
        ui/centered_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += resources.qrc
