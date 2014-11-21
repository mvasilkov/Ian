#include <memory>
#include <forward_list>

#include <QApplication>
#include <QSystemTrayIcon>

#include "Hacks.h"
#include "NotepadWin.h"
#include "Util.h"
#include "Http/Ui.h"

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

        qDebug("Initializing storage: %s", qPrintable(get_docs_dir()));

        if (ensure_docs_dir())
        {
                qCritical("Total disaster: "
                          "could not ensure_docs_dir()");
                return 1;
        }

        QApplication::setQuitOnLastWindowClosed(false);

        QObject::connect(mbicon.get(), &MBIcon::activated, [&]
        {
                win.emplace_front(make_unique_noargs<NotepadWin>());

                auto& w = win.front();

                QObject::connect(w.get(), &NotepadWin::closed, [&]
                {
                        win.remove(w);
                });
        });

        const int ui_port = 9096;
        qDebug("Giving rise to the HTTP server on port %d", ui_port);

        if (start_http_ui(ui_port))
        {
                qCritical("Fuck this thing in particular: "
                          "could not start_http_ui()");
                return 1;
        }

        int ret = app.exec();

        qDebug("Laying waste to the HTTP server");
        stop_http_ui();

        return ret;
}
