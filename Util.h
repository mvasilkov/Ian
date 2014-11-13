#pragma once

#include <memory>

#include <QString>

enum bad_things
{
        baww_not_a_directory = 1,
        baww_no_HOME
};

QString &get_docs_dir();
int ensure_docs_dir();
std::shared_ptr<QString> fmt_doc_path(const char *);
