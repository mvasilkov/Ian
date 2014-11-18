#pragma once

#include <memory>

#include <QString>

enum bad_things
{
        baww_not_a_directory = 1,
        baww_no_HOME
};

const QString &get_docs_dir();
int ensure_docs_dir();
std::unique_ptr<QString> fmt_doc_path(const char *);
