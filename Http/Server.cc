#include <QtGlobal>

#include "Http/Server.h"
#include "Http/Util.h"

static const char chickens[] = "Nobody here but us chickens";

int Server::requestHandler(void *instance, struct MHD_Connection *connection,
                           const char *url, const char *method,
                           const char *, const char *, size_t *, void **)
{
        qDebug("HTTP %s %s", method, url);

        Server *server = static_cast<Server *>(instance);
        Route *route = nullptr;

        for (auto r: server->routes)
        {
                if (r->validPath(url, method))
                {
                        route = r;
                        break;
                }
        }

        if (route)
                return route->handleRequest(connection, url, method);

        qDebug("-- chickens --");
        return send_response(connection, MHD_HTTP_NOT_FOUND, chickens,
                             sizeof(chickens) - 1, MHD_RESPMEM_PERSISTENT);
}

void Server::start(unsigned port)
{
        daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, port, NULL, NULL,
                                  &requestHandler, this, MHD_OPTION_END);
        if (daemon)
                _running = true;
}

void Server::stop()
{
        if (_running)
        {
                MHD_stop_daemon(daemon);
                _running = false;
        }
}
