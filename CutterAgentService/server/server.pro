TARGET   = httpservice
TEMPLATE = app
CONFIG   += console qt
QT = core network 

SOURCES  = main.cpp \
    Utility.cpp \
    Global.cpp \
    CutterSerializer.cpp \
    cutterrptparser.cpp \
    CutterOptPrc.cpp \
    cutteroptlog.cpp \
    cuttermonthlyrpt.cpp \
    cutterdailyrpt.cpp \
    CutterAltPrc.cpp \
    cutteraltlog.cpp \
    utiities/JSonRpcSvc.cpp \
    utiities/HttpGetFile.cpp \
    processor/CutterSyncPrc.cpp \
    data/HYLicMO.cpp

include(../../src/qtservice.pri)

HEADERS += \
    Utility.h \
    Global.h \
    CutterSerializer.h \
    cutterrptparser.h \
    CutterOptPrc.h \
    cutteroptlog.h \
    cuttermonthlyrpt.h \
    cutterlogprc.h \
    cutterdailyrpt.h \
    CutterAltPrc.h \
    cutteraltlog.h \
    utiities/JSonRpcSvc.h \
    utiities/HttpGetFile.h \
    processor/CutterSyncPrc.h







