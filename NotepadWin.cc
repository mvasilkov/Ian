#include <QApplication>
#include <QDesktopWidget>

#include "NotepadWin.h"
#include "Util.h"

NotepadWin::NotepadWin(const char *name): QMainWindow(nullptr)
{
        doc_path = fmt_doc_path(name);
        qDebug("Make NotepadWin: %s", qPrintable(*doc_path));

        setAttribute(Qt::WA_DeleteOnClose);
        setWindowTitle("Ian");

        const QRect rekt = QApplication::desktop()->screenGeometry();
        const int left = rekt.width() * 0.3333;
        const int top = rekt.height() * 0.3333;
        setGeometry(left, top, left, top);

        show();
}

NotepadWin::~NotepadWin()
{
        qDebug("Raze NotepadWin: %s", qPrintable(*doc_path));
}

void NotepadWin::closeEvent(QCloseEvent *event)
{
        emit closed();
        event->accept();
}
