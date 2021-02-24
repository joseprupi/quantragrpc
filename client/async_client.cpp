#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>
#include <thread>

#include "quantraserver.grpc.fb.h"
#include "quantraserver_generated.h"
#include "responses_generated.h"

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;

class QuantraClient
{
public:
    explicit QuantraClient(std::shared_ptr<grpc::Channel> channel)
        : stub_(quantra::QuantraServer::NewStub(channel)) {}

    // Assembles the client's payload and sends it to the server.
    void PriceBond()
    {
        flatbuffers::grpc::MessageBuilder builder;

        // ****************************
        // Create the discounting curve
        // ****************************

        // Settings
        auto calendar = quantra::enums::Calendar_TARGET;
        auto settlement_date = builder.CreateString("2008/09/18");
        auto fixing_days = 3;
        auto settlement_days = 3;

        // Create deposit
        auto deposit_helper_zc3m_builder = quantra::DepositHelperBuilder(builder);
        deposit_helper_zc3m_builder.add_tenor_number(3);
        deposit_helper_zc3m_builder.add_tenor_time_unit(quantra::enums::TimeUnit_Months);
        deposit_helper_zc3m_builder.add_fixing_days(fixing_days);
        deposit_helper_zc3m_builder.add_calendar(calendar);
        deposit_helper_zc3m_builder.add_business_day_convention(quantra::enums::BusinessDayConvention_ModifiedFollowing);
        deposit_helper_zc3m_builder.add_day_counter(quantra::enums::DayCounter_Actual365Fixed);
        auto deposit_helper_zc3m = deposit_helper_zc3m_builder.Finish();

        // Create deposit
        auto deposit_helper_zc6m_builder = quantra::DepositHelperBuilder(builder);
        deposit_helper_zc6m_builder.add_rate(0.0145);
        deposit_helper_zc6m_builder.add_tenor_number(6);
        deposit_helper_zc6m_builder.add_tenor_time_unit(quantra::enums::TimeUnit_Months);
        deposit_helper_zc6m_builder.add_fixing_days(fixing_days);
        deposit_helper_zc6m_builder.add_calendar(calendar);
        deposit_helper_zc6m_builder.add_business_day_convention(quantra::enums::BusinessDayConvention_ModifiedFollowing);
        deposit_helper_zc6m_builder.add_day_counter(quantra::enums::DayCounter_Actual365Fixed);
        auto deposit_helper_zc6m = deposit_helper_zc6m_builder.Finish();

        // Create deposit
        auto deposit_helper_zc1y_builder = quantra::DepositHelperBuilder(builder);
        deposit_helper_zc1y_builder.add_rate(0.0194);
        deposit_helper_zc1y_builder.add_tenor_number(1);
        deposit_helper_zc1y_builder.add_tenor_time_unit(quantra::enums::TimeUnit_Years);
        deposit_helper_zc1y_builder.add_fixing_days(fixing_days);
        deposit_helper_zc1y_builder.add_calendar(calendar);
        deposit_helper_zc1y_builder.add_business_day_convention(quantra::enums::BusinessDayConvention_ModifiedFollowing);
        deposit_helper_zc1y_builder.add_day_counter(quantra::enums::DayCounter_Actual365Fixed);
        auto deposit_helper_zc1y = deposit_helper_zc1y_builder.Finish();

        // Create vector of points
        std::vector<uint8_t> types_vector;
        std::vector<flatbuffers::Offset<void>> points_vector;

        types_vector.push_back(quantra::Point_DepositHelper);
        types_vector.push_back(quantra::Point_DepositHelper);
        types_vector.push_back(quantra::Point_DepositHelper);

        points_vector.push_back(deposit_helper_zc3m.Union());
        points_vector.push_back(deposit_helper_zc6m.Union());
        points_vector.push_back(deposit_helper_zc1y.Union());

        float redemption = 100.0;

        int number_of_bonds = 5;

        std::string issue_dates[] = {
            "2005/03/15",
            "2005/06/15",
            "2006/06/30",
            "2002/11/15",
            "1987/05/15"};

        std::string maturities[] = {
            "2010/08/31",
            "2011/08/31",
            "2013/08/31",
            "2018/08/15",
            "2038/05/15"};

        float coupon_rates[] = {
            0.02375,
            0.04625,
            0.03125,
            0.04000,
            0.04500};

        float market_quotes[] = {
            100.390625,
            106.21875,
            100.59375,
            101.6875,
            102.140625};

        for (int i = 0; i < number_of_bonds; i++)
        {
            // Create schedule for bond helper
            auto effective_date = builder.CreateString(issue_dates[i]);
            auto termination_date = builder.CreateString(maturities[i]);
            auto schedule_builder = quantra::ScheduleBuilder(builder);
            schedule_builder.add_calendar(quantra::enums::Calendar_UnitedStatesGovernmentBond);
            schedule_builder.add_effective_date(effective_date);
            schedule_builder.add_termination_date(termination_date);
            schedule_builder.add_convention(quantra::enums::BusinessDayConvention_Unadjusted);
            schedule_builder.add_frequency(quantra::enums::Frequency_Semiannual);
            schedule_builder.add_termination_date_convention(quantra::enums::BusinessDayConvention_Unadjusted);
            schedule_builder.add_date_generation_rule(quantra::enums::DateGenerationRule_Backward);
            schedule_builder.add_end_of_mont(false);
            auto schedule = schedule_builder.Finish();

            // Create bond helper
            auto bond_helper_builder = quantra::BondHelperBuilder(builder);
            bond_helper_builder.add_rate(market_quotes[i]);
            bond_helper_builder.add_settlement_days(settlement_days);
            bond_helper_builder.add_face_amount(100.0);
            bond_helper_builder.add_schedule(schedule);
            bond_helper_builder.add_coupon_rate(coupon_rates[i]);
            bond_helper_builder.add_day_counter(quantra::enums::DayCounter_ActualActual365);
            bond_helper_builder.add_business_day_convention(quantra::enums::BusinessDayConvention_Unadjusted);
            bond_helper_builder.add_redemption(redemption);
            bond_helper_builder.add_issue_date(effective_date);
            auto bond_helper = bond_helper_builder.Finish();

            types_vector.push_back(quantra::Point_BondHelper);
            points_vector.push_back(bond_helper.Union());
        }

        auto types = builder.CreateVector(types_vector);
        auto points = builder.CreateVector(points_vector);

        // Create the termstructure curve
        auto id = builder.CreateString("depos_curve");
        auto term_structure_builder = quantra::TermStructureBuilder(builder);
        term_structure_builder.add_bootstrap_trait(quantra::enums::BootstrapTrait_Discount);
        term_structure_builder.add_interpolator(quantra::enums::Interpolator_LogLinear);
        term_structure_builder.add_id(id);
        term_structure_builder.add_day_counter(quantra::enums::DayCounter_ActualActual365);
        term_structure_builder.add_as_of_date(settlement_date);
        term_structure_builder.add_points_type(types);
        term_structure_builder.add_points(points);
        auto term_structure = term_structure_builder.Finish();

        // *****************************************************
        // Create the pricing information. Curves and as of date
        // *****************************************************

        std::vector<flatbuffers::Offset<quantra::TermStructure>> term_structures_vector;
        term_structures_vector.push_back(term_structure);
        auto term_structures = builder.CreateVector(term_structures_vector);

        auto as_of_date = builder.CreateString("2008/09/16");
        auto pricing_builder = quantra::PricingBuilder(builder);
        pricing_builder.add_as_of_date(as_of_date);
        pricing_builder.add_curves(term_structures);
        auto pricing = pricing_builder.Finish();

        // **************************
        // Create the Fixed Rate Bond
        // **************************

        // Create the Schedule table

        auto effective_date = builder.CreateString("2007/05/15");
        auto termination_date = builder.CreateString("2017/05/15");
        auto schedule_builder = quantra::ScheduleBuilder(builder);
        schedule_builder.add_calendar(quantra::enums::Calendar_UnitedStatesGovernmentBond);
        schedule_builder.add_effective_date(effective_date);
        schedule_builder.add_termination_date(termination_date);
        schedule_builder.add_convention(quantra::enums::BusinessDayConvention_Unadjusted);
        schedule_builder.add_frequency(quantra::enums::Frequency_Semiannual);
        schedule_builder.add_termination_date_convention(quantra::enums::BusinessDayConvention_Unadjusted);
        schedule_builder.add_date_generation_rule(quantra::enums::DateGenerationRule_Backward);
        schedule_builder.add_end_of_mont(false);
        auto schedule = schedule_builder.Finish();

        // Create the fixed rate bond
        auto issue_date = builder.CreateString("2007/05/15");
        auto fixed_rate_bond_builder = quantra::FixedRateBondBuilder(builder);
        fixed_rate_bond_builder.add_settlement_days(settlement_days);
        fixed_rate_bond_builder.add_face_amount(100);
        fixed_rate_bond_builder.add_schedule(schedule);
        fixed_rate_bond_builder.add_rate(0.045);
        fixed_rate_bond_builder.add_day_counter(quantra::enums::DayCounter_ActualActualBond);
        fixed_rate_bond_builder.add_business_day_convention(quantra::enums::BusinessDayConvention_ModifiedFollowing);
        fixed_rate_bond_builder.add_redemption(100);
        fixed_rate_bond_builder.add_issue_date(issue_date);
        auto bond = fixed_rate_bond_builder.Finish();

        // ***********************************
        // Create the PriceFixedRateBond table
        // ***********************************

        // Create the Yield table
        auto yield_builder = quantra::YieldBuilder(builder);
        yield_builder.add_day_counter(quantra::enums::DayCounter_Actual360);
        yield_builder.add_compounding(quantra::enums::Compounding_Compounded);
        yield_builder.add_frequency(quantra::enums::Frequency_Annual);
        auto yield = yield_builder.Finish();

        // Create the BondPricing table
        auto curve_id = builder.CreateString("depos_curve");
        auto bond_pricing_builder = quantra::PriceFixedRateBondBuilder(builder);
        bond_pricing_builder.add_fixed_rate_bond(bond);
        bond_pricing_builder.add_discounting_curve(curve_id);
        bond_pricing_builder.add_yield(yield);
        auto bond_pricing = bond_pricing_builder.Finish();

        std::vector<flatbuffers::Offset<quantra::PriceFixedRateBond>> bonds_vector_vector;
        bonds_vector_vector.push_back(bond_pricing);
        auto bonds_vector = builder.CreateVector(bonds_vector_vector);

        // ******************************************
        // Create the PriceFixedRateBondRequest table
        // ******************************************

        auto bond_request_builder = quantra::PriceFixedRateBondRequestBuilder(builder);
        bond_request_builder.add_pricing(pricing);
        bond_request_builder.add_bonds(bonds_vector);
        auto bond_request = bond_request_builder.Finish();

        builder.Finish(bond_request);
        auto request_msg = builder.ReleaseMessage<quantra::PriceFixedRateBondRequest>();

        // Call object to store rpc data
        AsyncClientCall *call = new AsyncClientCall;

        // stub_->PrepareAsyncSayHello() creates an RPC object, returning
        // an instance to store in "call" but does not actually start the RPC
        // Because we are using the asynchronous API, we need to hold on to
        // the "call" instance in order to get updates on the ongoing RPC.
        call->response_reader =
            stub_->PrepareAsyncBondPricing(&call->context, request_msg, &cq_);

        // StartCall initiates the RPC call
        call->response_reader->StartCall();

        // Request that, upon completion of the RPC, "reply" be updated with the
        // server's response; "status" with the indication of whether the operation
        // was successful. Tag the request with the memory address of the call object.
        call->response_reader->Finish(&call->reply, &call->status, (void *)call);
    }

    // Loop while listening for completed responses.
    // Prints out the response from the server.
    void AsyncCompleteRpc()
    {
        void *got_tag;
        bool ok = false;

        // Block until the next result is available in the completion queue "cq".
        while (cq_.Next(&got_tag, &ok))
        {
            // The tag in this example is the memory location of the call object
            AsyncClientCall *call = static_cast<AsyncClientCall *>(got_tag);

            // Verify that the request was completed successfully. Note that "ok"
            // corresponds solely to the request for updates introduced by Finish().
            GPR_ASSERT(ok);

            if (call->status.ok())
            {
                const quantra::NPVResponse *response = call->reply.GetRoot();
                auto npv = response->npv();
                std::cout << "quantra::QuantraServer received: " << npv << std::endl;
            }
            else
                std::cout << "RPC failed" << call->status.error_code() << std::endl;
            delete call;
        }
    }

private:
    // struct for keeping state and data information
    struct AsyncClientCall
    {
        // Container for the data we expect from the server.
        flatbuffers::grpc::Message<quantra::NPVResponse> reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        grpc::ClientContext context;

        // Storage for the status of the RPC upon completion.
        grpc::Status status;

        std::unique_ptr<grpc::ClientAsyncResponseReader<flatbuffers::grpc::Message<quantra::NPVResponse>>> response_reader;
    };

    // Out of the passed in Channel comes the stub, stored here, our view of the
    // server's exposed services.
    std::unique_ptr<quantra::QuantraServer::Stub> stub_;

    // The producer-consumer queue we use to communicate asynchronously with the
    // gRPC runtime.
    grpc::CompletionQueue cq_;
};

int main(int argc, char **argv)
{

    // Instantiate the client. It requires a channel, out of which the actual RPCs
    // are created. This channel models a connection to an endpoint (in this case,
    // localhost at port 50051). We indicate that the channel isn't authenticated
    // (use of InsecureChannelCredentials()).
    QuantraClient greeter(grpc::CreateChannel(
        "localhost:50051", grpc::InsecureChannelCredentials()));

    // Spawn reader thread that loops indefinitely
    std::thread thread_ = std::thread(&QuantraClient::AsyncCompleteRpc, &greeter);

    for (int i = 0; i < 2000; i++)
    {
        greeter.PriceBond();
    }

    std::cout << "Press control-c to quit" << std::endl
              << std::endl;
    thread_.join();

    return 0;
}