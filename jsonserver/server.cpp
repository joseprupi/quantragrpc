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

    QuantraClient client(connection, false);

    CROW_ROUTE(app, "/PriceFixedRateBondRequest")
        .methods("POST"_method)([&](const crow::request &req)
                                {
                                    auto response = client.PriceFixedRateBondRequestJSON(req.body);
                                    //std::cout << *response;
                                    std::ostringstream os;
                                    os << *response;

                                    // int size2;
                                    // for (auto it = client.responses.begin(); it != client.responses.end(); it++)
                                    // {
                                    //     size2 = (*it)->size();
                                    //     for (auto it2 = (*it)->begin(); it2 != (*it)->end(); it2++)
                                    //     {
                                    //         std::cout << (*it2)->npv << std::endl;
                                    //         os << (*it2)->npv;
                                    //     }
                                    // }

                                    return crow::response{os.str()};
                                });

    app.loglevel(crow::LogLevel::DEBUG);

    app.port(18080)
        .multithreaded()
        .run();
}