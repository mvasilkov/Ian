#pragma once

#include "Http/Route.h"

class Index: public Route {
public:
        bool validPath(const char *path, const char *method) override
        {
                return strcmp("/", path) == 0 && strcmp("GET", method) == 0;
        }

        void createResponse(MHD_Connection *, const char *, const char *,
                            std::stringstream&) override;
};

int start_http_ui(unsigned);
void stop_http_ui();
