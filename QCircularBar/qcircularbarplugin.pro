QT          += widgets designer
TARGET      = $$qtLibraryTarget($$TARGET)
TEMPLATE    = lib
QTDIR_build:DESTDIR     = $$QT_BUILD_TREE/plugins/designer

VERSION = 0.1.0

HEADERS     += qcircularbar.h \
               qcircularbarplugin.h \
               qcircularbartaskmenu.h \
               dialogqcircularbar.h
SOURCES     += qcircularbar.cpp \
               qcircularbarplugin.cpp \
               qcircularbartaskmenu.cpp \
               qcircularbardrawfunctions.cpp \
               dialogqcircularbar.cpp

FORMS        += dialogqcircularbar.ui

RESOURCES    = qcircularbar.qrc
# install
target.path = $$[QT_INSTALL_PLUGINS]/designer
sources.files = $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer/qcircularbarplugin
INSTALLS += target sources
