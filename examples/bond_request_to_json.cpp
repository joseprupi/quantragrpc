#include "messages.h"

int main(int argc, char **argv)
{
    std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder = std::make_shared<flatbuffers::grpc::MessageBuilder>();
    bond_request_fbs(builder);

    auto json_string = bond_to_json(builder);

    return 0;
}