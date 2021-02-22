#include "quantraserver.grpc.fb.h"
#include "quantraserver_generated.h"
#include "responses_generated.h"

#include <grpcpp/grpcpp.h>

#include <iostream>
#include <memory>
#include <string>

class QuantraClient
{
public:
    QuantraClient(std::shared_ptr<grpc::Channel> channel)
        : stub_(quantra::QuantraServer::NewStub(channel)) {}

    float PriceBond()
    {
        //flatbuffers::FlatBufferBuilder builder(1024);
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
        auto deposit_helper_zc3m_builder = quantra::DepositBuilder(builder);
        deposit_helper_zc3m_builder.add_tenor_number(3);
        deposit_helper_zc3m_builder.add_tenor_time_unit(quantra::enums::TimeUnit_Months);
        deposit_helper_zc3m_builder.add_fixing_days(fixing_days);
        deposit_helper_zc3m_builder.add_calendar(calendar);
        deposit_helper_zc3m_builder.add_business_day_convention(quantra::enums::BusinessDayConvention_ModifiedFollowing);
        deposit_helper_zc3m_builder.add_day_counter(quantra::enums::DayCounter_Actual365Fixed);
        auto deposit_helper_zc3m = deposit_helper_zc3m_builder.Finish();

        // Create deposit
        auto deposit_helper_zc6m_builder = quantra::DepositBuilder(builder);
        deposit_helper_zc6m_builder.add_rate(0.0145);
        deposit_helper_zc6m_builder.add_tenor_number(6);
        deposit_helper_zc6m_builder.add_tenor_time_unit(quantra::enums::TimeUnit_Months);
        deposit_helper_zc6m_builder.add_fixing_days(fixing_days);
        deposit_helper_zc6m_builder.add_calendar(calendar);
        deposit_helper_zc6m_builder.add_business_day_convention(quantra::enums::BusinessDayConvention_ModifiedFollowing);
        deposit_helper_zc6m_builder.add_day_counter(quantra::enums::DayCounter_Actual365Fixed);
        auto deposit_helper_zc6m = deposit_helper_zc6m_builder.Finish();

        // Create deposit
        auto deposit_helper_zc1y_builder = quantra::DepositBuilder(builder);
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
        types_vector.push_back(quantra::Point_Deposit);
        types_vector.push_back(quantra::Point_Deposit);
        types_vector.push_back(quantra::Point_Deposit);
        auto types = builder.CreateVector(types_vector);

        std::vector<flatbuffers::Offset<void>> points_vector;
        points_vector.push_back(deposit_helper_zc3m.Union());
        points_vector.push_back(deposit_helper_zc6m.Union());
        points_vector.push_back(deposit_helper_zc1y.Union());
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

        // **************************
        // Create the Fixed Rate Bond
        // **************************

        // Create the Schedule table
        auto schedule_builder = quantra::ScheduleBuilder(builder);
        schedule_builder.add_calendar(quantra::enums::Calendar_UnitedStatesGovernmentBond);
        auto effective_date = builder.CreateString("2007/05/15");
        schedule_builder.add_effective_date(effective_date);
        auto termination_date = builder.CreateString("2017/05/15");
        schedule_builder.add_termination_date(effective_date);
        schedule_builder.add_convention(quantra::enums::BusinessDayConvention_Unadjusted);
        schedule_builder.add_frequency(quantra::enums::Frequency_Semiannual);
        schedule_builder.add_termination_date_convention(quantra::enums::BusinessDayConvention_Unadjusted);
        schedule_builder.add_date_generation_rule(quantra::enums::DateGenerationRule_Backward);
        schedule_builder.add_end_of_mont(false);
        auto schedule = schedule_builder.Finish();

        // Create the fixed rate bond
        auto fixed_rate_bond_builder = quantra::FixedRateBondBuilder(builder);
        fixed_rate_bond_builder.add_settlement_days(settlement_days);
        fixed_rate_bond_builder.add_face_amount(100);
        fixed_rate_bond_builder.add_schedule(schedule);
        fixed_rate_bond_builder.add_rate(0.045);
        fixed_rate_bond_builder.add_day_counter(quantra::enums::DayCounter_ActualActualBond);
        fixed_rate_bond_builder.add_business_day_convention(quantra::enums::BusinessDayConvention_ModifiedFollowing);
        fixed_rate_bond_builder.add_redemption(100);
        auto issue_date = builder.CreateString("2007/05/15");
        fixed_rate_bond_builder.add_issue_date(issue_date);
        auto bond = fixed_rate_bond_builder.Finish();

        // ***************************************
        // Create the pricing request for the bond
        // ***************************************

        // Create the Yield table
        auto yield_builder = quantra::YieldBuilder(builder);
        yield_builder.add_day_counter(quantra::enums::DayCounter_Actual360);
        yield_builder.add_compounding(quantra::enums::Compounding_Compounded);
        yield_builder.add_frequency(quantra::enums::Frequency_Annual);
        auto yield = yield_builder.Finish();

        // Create the Pricing table
        auto pricing_builder = quantra::PricingBuilder(builder);
        auto as_of_date = builder.CreateString("2008/09/16");
        pricing_builder.add_as_of_date(as_of_date);
        auto pricing = pricing_builder.Finish();

        auto bond_request_builder = quantra::PriceFixedRateBondBuilder(builder);
        bond_request_builder.add_yield(yield);
        bond_request_builder.add_pricing(pricing);
        bond_request_builder.add_fixed_rate_bond(bond);
        bond_request_builder.add_term_structure(term_structure);
        auto bond_request = bond_request_builder.Finish();

        auto request_msg = builder.ReleaseMessage<quantra::PriceFixedRateBond>();

        flatbuffers::grpc::Message<quantra::NPVResponse> response_msg;

        grpc::ClientContext context;

        auto status = stub_->BondPricing(&context, &request_msg, &response_msg);
        if (status.ok())
        {
            const quantra::NPVResponse *response = response_msg.GetRoot();
            return response->npv();
        }
        else
        {
            std::cerr << status.error_code() << ": " << status.error_message()
                      << std::endl;
            return -1;
        }
    }

private:
    std::unique_ptr<quantra::QuantraServer::Stub> stub_;
};

int main(int argc, char **argv)
{
    std::string server_address("localhost:50051");

    auto channel =
        grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials());
    QuantraClient greeter(channel);

    float npv = greeter.PriceBond();
    std::cerr << "NPV received: " << npv << std::endl;

    return 0;
}
