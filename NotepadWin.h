#pragma once

#include <QMainWindow>

class NotepadWin: public QMainWindow {
        Q_OBJECT

public:
        NotepadWin();

signals:
        void closed();

protected:
        void closeEvent(QCloseEvent *) override;
};
