QT          += widgets designer
TARGET      = $$qtLibraryTarget($$TARGET)
TEMPLATE    = lib
QTDIR_build:DESTDIR     = $$QT_BUILD_TREE/plugins/designer

VERSION = 0.5.1

HEADERS     += qmeter.h \
              qmeterplugin.h \
              qmetertaskmenu.h \
    dialogqmeter.h
SOURCES     += qmeter.cpp \
              qmeterplugin.cpp \
              qmetertaskmenu.cpp \
              qmeterdrawfunctions.cpp \
    dialogqmeter.cpp

FORMS        += \
    dialogqmeter.ui

RESOURCES    = qmeter.qrc
# install
target.path = $$[QT_INSTALL_PLUGINS]/designer
sources.files = $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer/qmeterplugin
INSTALLS += target sources
