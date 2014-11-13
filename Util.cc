#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>

#include <QString>

#include "Util.h"

static int make_dir(const char *path)
{
        struct stat buf;

        if (stat(path, &buf))
                return mkdir(path, 0755);

        return S_ISDIR(buf.st_mode)? 0: baww_not_a_directory;
}

static QString docs_dir;

QString &get_docs_dir()
{
        if (docs_dir.isNull())
        {
                char *home = getenv("HOME");
                if (home)
                        docs_dir.append(home).append("/.ian_docs");
        }

        return docs_dir;
}

int ensure_docs_dir()
{
        QString &dir = get_docs_dir();
        return dir.isNull()? baww_no_HOME:
               make_dir(dir.toLocal8Bit().constData());
}
