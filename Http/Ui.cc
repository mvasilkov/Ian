#include "Http/Server.h"
#include "Http/Ui.h"

void Index::createResponse(MHD_Connection *, const char *, const char *,
                           std::stringstream& response)
{
        response << "Ian http ui";
}

static Server ui_server;
static Index index_route;

int start_http_ui(unsigned port)
{
        if (ui_server.running())
                return 1;

        ui_server.addRoute(&index_route);
        ui_server.start(port);

        return !ui_server.running();
}

void stop_http_ui()
{
        if (ui_server.running())
                ui_server.stop();
}
