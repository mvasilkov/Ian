#include <memory>

#include <QApplication>
#include <QSystemTrayIcon>

#include "Hacks.h"
#include "NotepadWin.h"

using namespace std;

unique_ptr<QSystemTrayIcon> init_menu_bar_icon()
{
        if (!QSystemTrayIcon::isSystemTrayAvailable())
                return nullptr;
        auto icon = make_unique_noargs<QSystemTrayIcon>();
        icon->setIcon(QIcon(":/Ian_mb.png"));
        icon->show();
        return icon;
}

int main(int argc, char *argv[])
{
        QApplication app(argc, argv);
        unique_ptr<QSystemTrayIcon> icon;

        if (!(icon = init_menu_bar_icon()))
        {
                qCritical("Catastrophic error: "
                          "could not init_menu_bar_icon()");
                return 1;
        }

        NotepadWin *win = new NotepadWin;
        win->show();

        return app.exec();
}
