#include <QApplication>
#include <QDesktopWidget>
#include <QMetaObject>

#include "NotepadWin.h"
#include "Util.h"
#include "Hacks.h"

NotepadWin::NotepadWin(const char *name): QMainWindow(nullptr)
{
        doc_path = fmt_doc_path(name);
        qDebug("Make NotepadWin: %s", qPrintable(*doc_path));

        QMetaObject::invokeMethod(this, "init", Qt::QueuedConnection);
}

void NotepadWin::init()
{
        setAttribute(Qt::WA_DeleteOnClose);
        setWindowTitle("Ian");

        const QRect rekt = QApplication::desktop()->screenGeometry();
        const int left = rekt.width() * 0.3333;
        const int top = rekt.height() * 0.3333;
        setGeometry(left, top, left, top);

        editor = make_unique_noargs<QTextEdit>();
        editor->setAcceptRichText(false);
        editor->installEventFilter(this);
        setCentralWidget(editor.get());

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

bool NotepadWin::eventFilter(QObject *target, QEvent *event)
{
        if (target != editor.get())
                return super::eventFilter(target, event);
        return false;
}
