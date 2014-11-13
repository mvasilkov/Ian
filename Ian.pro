CONFIG += c++11
QT = widgets
HEADERS = Hacks.h NotepadWin.h Util.h
SOURCES = Ian.cc NotepadWin.cc Util.cc
RESOURCES = Resources.qrc

LIBS += -L/usr/local/Cellar/libbson/1.0.2/lib -lbson-1.0
INCLUDEPATH += /usr/local/Cellar/libbson/1.0.2/include/libbson-1.0
