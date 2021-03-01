

// std::string bond_to_json(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder)
// {
//     std::string schemafile;
//     auto root = flatbuffers::GetRoot<PriceFixedRateBondRequest>(builder->GetBufferPointer());
//     bool ok = flatbuffers::LoadFile("../flatbuffers/fbs/requests.fbs", false, &schemafile);
//     if (!ok)
//     {
//         printf("couldn't load files!\n");
//         return "";
//     }

//     flatbuffers::Parser parser;
//     const char *include_directories[] = {"../flatbuffers/fbs", nullptr};

//     ok = parser.Parse(schemafile.c_str(), include_directories);
//     assert(ok);

//     std::string jsongen;
//     if (!GenerateText(parser, builder->GetBufferPointer(), &jsongen))
//     {
//         printf("Couldn't serialize parsed data to JSON!\n");
//         return "";
//     }

//     //return jsongen;
//     return "";
// }