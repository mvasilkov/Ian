#pragma once

#include <memory>

#include <QCloseEvent>
#include <QMainWindow>
#include <QString>

class NotepadWin: public QMainWindow {
        Q_OBJECT

public:
        explicit NotepadWin(const char *name = nullptr);
        ~NotepadWin();

signals:
        void closed();

protected:
        void closeEvent(QCloseEvent *) override;

private:
        std::shared_ptr<QString> doc_path;
};
