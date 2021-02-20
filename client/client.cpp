#include "quantraserver.grpc.fb.h"
#include "quantraserver_generated.h"

#include <grpcpp/grpcpp.h>

#include <iostream>
#include <memory>
#include <string>

class QuantraClient
{
public:
    QuantraClient(std::shared_ptr<grpc::Channel> channel)
        : stub_(quantra::QuantraServer::NewStub(channel)) {}

    std::string SayHello(const std::string &name)
    {
        flatbuffers::FlatBufferBuilder builder(1024);

        // Create the discounting curve
        auto calendar = quantra::enums::Calendar_TARGET;
        auto settlement_date = builder.CreateString("2008/09/18");
        auto fixing_days = 2;
        auto settlement_days = 2;

        // Create deposit
        auto deposit_helper_zc3m = quantra::DepositBuilder(builder);
        deposit_helper_zc3m.add_rate(0.0096);
        deposit_helper_zc3m.add_tenor_number(3);
        deposit_helper_zc3m.add_tenor_time_unit(quantra::enums::TimeUnit_Months);
        deposit_helper_zc3m.add_fixing_days(fixing_days);
        deposit_helper_zc3m.add_calendar(calendar);
        deposit_helper_zc3m.add_business_day_convention(quantra::enums::BusinessDayConvention_ModifiedFollowing);
        deposit_helper_zc3m.add_day_counter(quantra::enums::DayCounter_Actual365Fixed);

        // Create the Pricing table
        auto as_of_date = builder.CreateString("2020/01/01");
        auto pricing = quantra::CreatePricing(builder, as_of_date);

        // Create the Schedule table
        auto calendar = quantra::enums::Calendar_TARGET;
        auto effective_date = builder.CreateString("2020/01/01");
        auto termination_date = builder.CreateString("2030/01/01");
        auto frequency = quantra::enums::Frequency_Annual;
        auto convention = quantra::enums::BusinessDayConvention_Following;
        auto termination_date_convention = quantra::enums::BusinessDayConvention_Following;
        auto date_generation_rule = quantra::enums::DateGenerationRule_Backward;
        auto end_of_month = false;
        auto schedule = quantra::CreateSchedule(builder, calendar, effective_date, termination_date, frequency, convention, termination_date_convention, date_generation_rule, end_of_month);

        // Create the Yield table
        auto day_counter = quantra::enums::DayCounter_Actual360;
        auto compounding = quantra::enums::Compounding_Compounded;
        auto frequency = quantra::enums::Frequency_Annual;
        auto yield = quantra::CreateYield(builder, day_counter, compounding, frequency);

        // Create the fixed rate bond
        auto settlement_days = 2;
        auto face_amount = 20000;
        auto rate = 3.5;
        auto day_counter = quantra::enums::DayCounter_Actual360;
        auto business_day_convention = quantra::enums::BusinessDayConvention_Following;
        auto redemption = 20000;
        auto issue_date = builder.CreateString("2020/01/01");
        auto fixed_rate_bond = quantra::CreateFixedRateBond(builder, settlement_days, face_amount, rate, day_counter, business_day_convention, redemption, issue_date, schedule, yield);

        flatbuffers::grpc::MessageBuilder mb;
        auto name_offset = mb.CreateString(name);
        auto request_offset = quantra::CreatePriceFixedRateBond(mb, name_offset);
        mb.Finish(request_offset);
        auto request_msg = mb.ReleaseMessage<HelloRequest>();

        flatbuffers::grpc::Message<HelloReply> response_msg;

        grpc::ClientContext context;

        auto status = stub_->SayHello(&context, request_msg, &response_msg);
        if (status.ok())
        {
            const HelloReply *response = response_msg.GetRoot();
            return response->message()->str();
        }
        else
        {
            std::cerr << status.error_code() << ": " << status.error_message()
                      << std::endl;
            return "RPC failed";
        }
    }

    void SayManyHellos(const std::string &name, int num_greetings,
                       std::function<void(const std::string &)> callback)
    {
        flatbuffers::grpc::MessageBuilder mb;
        auto name_offset = mb.CreateString(name);
        auto request_offset =
            CreateManyHellosRequest(mb, name_offset, num_greetings);
        mb.Finish(request_offset);
        auto request_msg = mb.ReleaseMessage<ManyHellosRequest>();

        flatbuffers::grpc::Message<HelloReply> response_msg;

        grpc::ClientContext context;

        auto stream = stub_->SayManyHellos(&context, request_msg);
        while (stream->Read(&response_msg))
        {
            const HelloReply *response = response_msg.GetRoot();
            callback(response->message()->str());
        }
        auto status = stream->Finish();
        if (!status.ok())
        {
            std::cerr << status.error_code() << ": " << status.error_message()
                      << std::endl;
            callback("RPC failed");
        }
    }

private:
    std::unique_ptr<Greeter::Stub> stub_;
};

int main(int argc, char **argv)
{
    std::string server_address("localhost:50051");

    auto channel =
        grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials());
    GreeterClient greeter(channel);

    std::string name("world");

    std::string message = greeter.SayHello(name);
    std::cerr << "Greeter received: " << message << std::endl;

    int num_greetings = 10;
    greeter.SayManyHellos(name, num_greetings, [](const std::string &message) {
        std::cerr << "Greeter received: " << message << std::endl;
    });

    return 0;
}
