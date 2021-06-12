#include "json_to_fbs.h"

std::shared_ptr<flatbuffers::grpc::MessageBuilder> JSONParser::PriceFixedRateBondRequestToFBS(std::string json_str)
{
    if (!this->price_fixed_rate_bond_parser->Parse(json_str.c_str(), fbs_include_directories))
    {
        throw std::runtime_error("Error while loading json");
    }

    return std::make_shared<flatbuffers::grpc::MessageBuilder>(std::move(this->price_fixed_rate_bond_parser->builder_));
}

std::shared_ptr<std::string> JSONParser::PriceFixedRateBondResponseToJSON(const uint8_t *buffer)
{
    std::string jsongen;
    if (!GenerateText((*this->fixed_rate_bond_response_parser), buffer, &jsongen))
    {
        throw std::runtime_error("Couldn't serialize bond response to JSON!");
    }

    //auto tmp = std::make_shared<std::string>(jsongen);
    //std::cout << *tmp;

    return std::make_shared<std::string>(jsongen);
}

JSONParser::JSONParser()
{
    this->LoadFBS();
}

void JSONParser::LoadFBS()
{
    std::string schemafile;

    // Load FIXED_RATE_BOND_REQUEST schema
    if (!flatbuffers::LoadFile(FIXED_RATE_BOND_REQUEST_PATH, false, &schemafile))
    {
        throw std::runtime_error("Error while loading flatbuffers file");
    }

    this->price_fixed_rate_bond_parser->opts.strict_json = true;

    if (!this->price_fixed_rate_bond_parser->Parse(schemafile.c_str(), fbs_include_directories))
    {
        throw std::runtime_error("Error while loading flatbuffers schema");
    }

    // Load FIXED_RATE_BOND_REQUEST schema
    if (!flatbuffers::LoadFile(FIXED_RATE_BOND_RESPONSE_PATH, false, &schemafile))
    {
        throw std::runtime_error("Error while loading flatbuffers file");
    }

    this->fixed_rate_bond_response_parser->opts.strict_json = true;

    if (!this->fixed_rate_bond_response_parser->Parse(schemafile.c_str(), fbs_include_directories))
    {
        throw std::runtime_error("Error while loading flatbuffers schema");
    }
}