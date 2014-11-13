#include <QApplication>

#include "NotepadWin.h"

int main(int argc, char *argv[])
{
        QApplication app(argc, argv);

        NotepadWin *win = new NotepadWin;
        win->show();

        return app.exec();
}
