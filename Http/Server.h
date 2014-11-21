#pragma once

#include <vector>

#include <microhttpd.h>

#include "Http/Route.h"

class Server {
private:
        struct MHD_Daemon *daemon = nullptr;
        std::vector<Route *> routes;
        bool _running = false;

        static int requestHandler(void *, struct MHD_Connection *,
                                  const char *, const char *, const char *,
                                  const char *, size_t *, void **);

public:
        void addRoute(Route *route)
        {
                routes.push_back(route);
        }

        bool running() const
        {
                return _running;
        }

        void start(unsigned);
        void stop();
};
