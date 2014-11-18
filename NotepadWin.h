#pragma once

#include <memory>

#include <QCloseEvent>
#include <QMainWindow>
#include <QString>
#include <QTextEdit>

class NotepadWin: public QMainWindow {
        Q_OBJECT

public:
        explicit NotepadWin(const char *name = nullptr);
        ~NotepadWin();
        typedef QMainWindow super;

signals:
        void closed();

protected:
        void closeEvent(QCloseEvent *) override;
        bool eventFilter(QObject *, QEvent *) override;

private:
        std::unique_ptr<QString> doc_path;
        std::unique_ptr<QTextEdit> editor;

        Q_INVOKABLE void init();
};
