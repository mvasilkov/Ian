#pragma once

#include <microhttpd.h>

inline int send_response(struct MHD_Connection *connection, unsigned code,
                         const char *res, size_t size,
                         MHD_ResponseMemoryMode mode)
{
        struct MHD_Response *response =
                MHD_create_response_from_buffer(size, (void *)res, mode);
        int ret = MHD_queue_response(connection, code, response);
        MHD_destroy_response(response);
        return ret;
}
