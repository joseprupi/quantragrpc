#include <iostream>
#include <string>
#include <sstream>

#include "crow_all.h"

#include "flatbuffers/idl.h"
#include "flatbuffers/util.h"
#include "flatbuffers/grpc.h"

#include "../client/cpp/quantra_client.h"

int main(int argc, char **argv)
{
    crow::App<> app;

    std::string connection;
    connection = argv[1];
    bool secure = 

    QuantraClient client(connection, true);

    CROW_ROUTE(app, "/")
        .name("hello")([]
                       { return "Hello World!"; });

    CROW_ROUTE(app, "/PriceFixedRateBondRequest")
        .methods("POST"_method)([&](const crow::request &req)
                                {
                                    auto response = client.PriceFixedRateBondRequestJSON(req.body);
                                    std::ostringstream os;
                                    os << *response;
                                    return crow::response{os.str()};
                                });

    // CROW_ROUTE(app, "/PriceFloatingRateBondRequest")
    //     .methods("POST"_method)([&](const crow::request &req)
    //                             {
    //                                 auto response = client.PriceFloatingRateBondRequestJSON(req.body);
    //                                 std::ostringstream os;
    //                                 os << *response;
    //                                 return crow::response{os.str()};
    //                             });

    app.loglevel(crow::LogLevel::DEBUG);

    app.port(18080)
        .multithreaded()
        .run();
}