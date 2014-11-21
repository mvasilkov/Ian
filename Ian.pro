CONFIG += c++11
QT = widgets
HEADERS = Hacks.h NotepadWin.h Util.h
SOURCES = Ian.cc NotepadWin.cc Util.cc
RESOURCES = Resources.qrc

HEADERS += Http/Route.h Http/Server.h Http/Ui.h Http/Util.h
SOURCES += Http/Server.cc Http/Ui.cc

BASE_BSON = /usr/local/Cellar/libbson/1.0.2
LIBS += -L$${BASE_BSON}/lib -lbson-1.0
INCLUDEPATH += $${BASE_BSON}/include/libbson-1.0

BASE_HTTP = /usr/local/Cellar/libmicrohttpd/0.9.38
LIBS += -L$${BASE_HTTP}/lib -lmicrohttpd
INCLUDEPATH += $${BASE_HTTP}/include
