template <class Request, class Response>
class QuantraRequest
{
public:
    //virtual std::vector<std::shared_ptr<std::string>> verify(const Request *request) const = 0;
    virtual flatbuffers::Offset<Response> request(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder,
                                                  const Request *request) const = 0;
};