#include <memory>
#include <forward_list>

#include <QApplication>
#include <QSystemTrayIcon>

#include "Hacks.h"
#include "NotepadWin.h"

using namespace std;
using MBIcon = QSystemTrayIcon;

unique_ptr<MBIcon> init_menu_bar_icon()
{
        if (!MBIcon::isSystemTrayAvailable())
                return nullptr;
        auto mbicon = make_unique_noargs<MBIcon>();
        mbicon->setIcon(QIcon(":/Ian_mb.png"));
        mbicon->show();
        return mbicon;
}

int main(int argc, char *argv[])
{
        QApplication app(argc, argv);
        unique_ptr<MBIcon> mbicon;
        forward_list<unique_ptr<NotepadWin>> win;

        if (!(mbicon = init_menu_bar_icon()))
        {
                qCritical("Catastrophic error: "
                          "could not init_menu_bar_icon()");
                return 1;
        }

        QApplication::setQuitOnLastWindowClosed(false);

        QObject::connect(mbicon.get(), &MBIcon::activated, [&]
        {
                win.emplace_front(make_unique_noargs<NotepadWin>());

                auto &w = win.front();

                QObject::connect(w.get(), &NotepadWin::closed, [&]
                {
                        win.remove(w);
                });
        });

        return app.exec();
}
