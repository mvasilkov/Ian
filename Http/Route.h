#pragma once

#include <sstream>
#include <string>

#include <microhttpd.h>

#include "Http/Util.h"

class BasicRoute {
public:
        virtual bool validPath(const char *path, const char *method) = 0;

        virtual int handleRequest(struct MHD_Connection *connection,
                                  const char *url, const char *method) = 0;
};

class Route: public BasicRoute {
public:
        virtual void createResponse(struct MHD_Connection *connection,
                                    const char *url, const char *method,
                                    std::stringstream& response) = 0;

        int handleRequest(struct MHD_Connection *connection,
                          const char *url, const char *method) override
        {
                std::stringstream response_string;
                createResponse(connection, url, method, response_string);
                const std::string& res = response_string.str();
                return send_response(connection, MHD_HTTP_OK, res.c_str(),
                                     res.size(), MHD_RESPMEM_MUST_COPY);
        }
};
