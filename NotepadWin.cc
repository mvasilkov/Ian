#include <QCloseEvent>

#include "NotepadWin.h"

NotepadWin::NotepadWin()
{
        setAttribute(Qt::WA_DeleteOnClose);
        setWindowTitle("Ian");
        resize(400, 300);
        show();
}

void NotepadWin::closeEvent(QCloseEvent *event)
{
        emit closed();
        event->accept();
}
