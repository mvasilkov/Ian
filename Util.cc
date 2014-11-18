#include <bson.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "Util.h"
#include "Hacks.h"

using namespace std;

static int make_dir(const char *path)
{
        struct stat buf;

        if (stat(path, &buf))
                return mkdir(path, 0755);

        return S_ISDIR(buf.st_mode)? 0: baww_not_a_directory;
}

static QString docs_dir;

const QString &get_docs_dir()
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
        const QString &dir = get_docs_dir();
        return dir.isNull()? baww_no_HOME:
               make_dir(dir.toLocal8Bit().constData());
}

unique_ptr<QString> fmt_doc_path(const char *name)
{
        if (!name)
        {
                bson_oid_t objectid;
                char new_name[25];

                bson_oid_init(&objectid, nullptr);
                bson_oid_to_string(&objectid, new_name);
                name = new_name;
        }

        auto path = _make_unique<QString>(get_docs_dir());
        (*path).append('/').append(name).append(".md");
        return move(path);
}
