#include "quantra_to_fbs.h";

flatbuffers::Offset<quantra::Yield> yield_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, Yield &yield)
{
    auto yield_builder = quantra::YieldBuilder(*builder);
    yield_builder.add_day_counter(yield.day_counter);
    yield_builder.add_compounding(yield.compounding);
    yield_builder.add_frequency(yield.frequency);
    return yield_builder.Finish();
}

flatbuffers::Offset<quantra::DepositHelper> deposit_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, DepositHelper &deposit)
{
    auto deposit_builder = quantra::DepositHelperBuilder(*builder);
    deposit_builder.add_tenor_number(deposit.tenor_number);
    deposit_builder.add_tenor_time_unit(deposit.tenor_time_unit);
    deposit_builder.add_fixing_days(deposit.fixing_days);
    deposit_builder.add_calendar(deposit.calendar);
    deposit_builder.add_business_day_convention(deposit.business_day_convention);
    deposit_builder.add_day_counter(deposit.day_counter);
    return deposit_builder.Finish();
}

flatbuffers::Offset<quantra::Schedule> schedule_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, Schedule &schedule)
{
    auto effective_date = builder->CreateString(schedule.effective_date);
    auto termination_date = builder->CreateString(schedule.termination_date);
    auto schedule_builder = quantra::ScheduleBuilder(*builder);
    schedule_builder.add_calendar(schedule.calendar);
    schedule_builder.add_effective_date(effective_date);
    schedule_builder.add_termination_date(termination_date);
    schedule_builder.add_convention(schedule.convention);
    schedule_builder.add_frequency(schedule.frequency);
    schedule_builder.add_termination_date_convention(schedule.termination_date_convention);
    schedule_builder.add_date_generation_rule(schedule.date_generation_rule);
    schedule_builder.add_end_of_mont(schedule.end_of_mont);
    return schedule_builder.Finish();
}

flatbuffers::Offset<quantra::Index> schedule_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, Index &index)
{
    std::vector<flatbuffers::Offset<quantra::Fixing>> fixings_vector;

    for (auto it = index.fixings.begin(); it < index.fixings.end(); it++)
    {
        auto date = builder->CreateString(it->date);
        auto fixing_builder = quantra::FixingBuilder(*builder);
        fixing_builder.add_rate(it->rate);
        fixing_builder.add_date(date);
        auto fixing = fixing_builder.Finish();

        fixings_vector.push_back(fixing);
    }

    auto fixings = builder->CreateVector(fixings_vector);

    auto index_builder = quantra::IndexBuilder(*builder);
    index_builder.add_period_number(index.period_number);
    index_builder.add_period_time_unit(index.period_time_unit);
    index_builder.add_settlement_days(index.settlement_days);
    index_builder.add_calendar(index.calendar);
    index_builder.add_business_day_convention(index.business_day_convention);
    index_builder.add_end_of_month(index.end_of_month);
    index_builder.add_day_counter(index.day_counter);
    index_builder.add_fixings(fixings);

    return index_builder.Finish();
}

flatbuffers::Offset<quantra::FRAHelper> FRAhelper_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, FRAHelper &FRA_helper)
{
    auto FRA_helper_builder = quantra::FRAHelperBuilder(*builder);
    FRA_helper_builder.add_rate(FRA_helper.rate);
    FRA_helper_builder.add_months_to_start(FRA_helper.months_to_start);
    FRA_helper_builder.add_months_to_end(FRA_helper.months_to_end);
    FRA_helper_builder.add_calendar(FRA_helper.calendar);
    FRA_helper_builder.add_business_day_convention(FRA_helper.business_day_convention);
    FRA_helper_builder.add_day_counter(FRA_helper.day_counter);

    return FRA_helper_builder.Finish();
}

flatbuffers::Offset<quantra::FutureHelper> future_helper_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, FutureHelper &future_helper)
{
    auto future_start_date = builder->CreateString(future_helper.future_start_date);

    auto future_helper_builder = quantra::FutureHelperBuilder(*builder);
    future_helper_builder.add_rate(future_helper.rate);
    future_helper_builder.add_future_start_date(future_start_date);
    future_helper_builder.add_future_months(future_helper.future_months);
    future_helper_builder.add_calendar(future_helper.calendar);
    future_helper_builder.add_business_day_convention(future_helper.business_day_convention);
    future_helper_builder.add_day_counter(future_helper.day_counter);

    return future_helper_builder.Finish();
}

flatbuffers::Offset<quantra::SwapHelper> swap_helper_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, SwapHelper &swap_helper)
{
    auto swap_helper_builder = quantra::SwapHelperBuilder(*builder);

    swap_helper_builder.add_rate(swap_helper.rate);
    swap_helper_builder.add_tenor_number(swap_helper.tenor_number);
    swap_helper_builder.add_calendar(swap_helper.calendar);
    swap_helper_builder.add_sw_fixed_leg_frequency(swap_helper.sw_fixed_leg_frequency);
    swap_helper_builder.add_sw_fixed_leg_convention(swap_helper.sw_fixed_leg_convention);
    swap_helper_builder.add_sw_fixed_leg_day_counter(swap_helper.sw_fixed_leg_day_counter);
    swap_helper_builder.add_sw_floating_leg_index(swap_helper.sw_floating_leg_index);
    swap_helper_builder.add_spread(swap_helper.spread);
    swap_helper_builder.add_fwd_start_days(swap_helper.fwd_start_days);

    return swap_helper_builder.Finish();
}

flatbuffers::Offset<quantra::BondHelper> bond_helper_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, BondHelper &bond_helper)
{
    auto schedule = schedule_to_fbs(builder, bond_helper.schedule);
    auto issue_date = builder->CreateString(bond_helper.issue_date);

    auto bond_helper_builder = quantra::BondHelperBuilder(*builder);

    bond_helper_builder.add_rate(bond_helper.rate);
    bond_helper_builder.add_settlement_days(bond_helper.settlement_days);
    bond_helper_builder.add_face_amount(bond_helper.face_amount);
    bond_helper_builder.add_schedule(schedule);
    bond_helper_builder.add_coupon_rate(bond_helper.coupon_rate);
    bond_helper_builder.add_day_counter(bond_helper.day_counter);
    bond_helper_builder.add_business_day_convention(bond_helper.business_day_convention);
    bond_helper_builder.add_redemption(bond_helper.redemption);
    bond_helper_builder.add_issue_date(issue_date);

    return bond_helper_builder.Finish();
}

flatbuffers::Offset<quantra::TermStructure> term_structure_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, TermStructure &term_structure)
{

    std::vector<flatbuffers::Offset<quantra::PointsWrapper>> points_vector;

    for (auto it = term_structure.points.begin(); it < term_structure.points.end(); it++)
    {
        switch (it->point_type)
        {
        case Deposit:
            auto deposit_builder = quantra::DepositHelperBuilder(*builder);
            deposit_builder.add_rate(it->deposit_helper.rate);
            deposit_builder.add_tenor_number(it->deposit_helper.tenor_number);
            deposit_builder.add_tenor_time_unit(it->deposit_helper.tenor_time_unit);
            deposit_builder.add_fixing_days(it->deposit_helper.fixing_days);
            deposit_builder.add_calendar(it->deposit_helper.calendar);
            deposit_builder.add_business_day_convention(it->deposit_helper.business_day_convention);
            deposit_builder.add_day_counter(it->deposit_helper.day_counter);
            auto deposit = deposit_builder.Finish();

            auto deposit_wrapper_builder = quantra::PointsWrapperBuilder(*builder);
            deposit_wrapper_builder.add_point_wrapper_type(quantra::Point_DepositHelper);
            deposit_wrapper_builder.add_point_wrapper(deposit.Union());
            auto deposit_wrapper = deposit_wrapper_builder.Finish();

            points_vector.push_back(deposit_wrapper);
            break;
        case FRA:
            auto FRA_builder = quantra::FRAHelperBuilder(*builder);
            FRA_builder.add_rate(it->FRA_helper.rate);
            FRA_builder.add_months_to_start(it->FRA_helper.months_to_start);
            FRA_builder.add_months_to_end(it->FRA_helper.months_to_end);
            FRA_builder.add_fixing_days(it->FRA_helper.fixing_days);
            FRA_builder.add_calendar(it->FRA_helper.calendar);
            FRA_builder.add_business_day_convention(it->FRA_helper.business_day_convention);
            FRA_builder.add_day_counter(it->FRA_helper.day_counter);
            auto FRA = FRA_builder.Finish();

            auto FRA_wrapper_builder = quantra::PointsWrapperBuilder(*builder);
            deposit_wrapper_builder.add_point_wrapper_type(quantra::Point_FRAHelper);
            deposit_wrapper_builder.add_point_wrapper(FRA.Union());
            auto FRA_wrapper = FRA_wrapper_builder.Finish();

            points_vector.push_back(FRA_wrapper);

            break;
        case Future:
            auto future_start_date = builder->CreateString(it->future_helper.future_start_date);
            auto future_builder = quantra::FutureHelperBuilder(*builder);
            future_builder.add_rate(it->future_helper.rate);
            future_builder.add_future_start_date(future_start_date);
            future_builder.add_future_months(it->future_helper.future_months);
            future_builder.add_calendar(it->future_helper.calendar);
            future_builder.add_business_day_convention(it->future_helper.business_day_convention);
            future_builder.add_day_counter(it->future_helper.day_counter);
            auto future = future_builder.Finish();

            auto future_wrapper_builder = quantra::PointsWrapperBuilder(*builder);
            deposit_wrapper_builder.add_point_wrapper_type(quantra::Point_FutureHelper);
            deposit_wrapper_builder.add_point_wrapper(future.Union());
            auto future_wrapper = future_wrapper_builder.Finish();

            points_vector.push_back(future_wrapper);

            break;
        case Swap:
            auto swap_builder = quantra::SwapHelperBuilder(*builder);
            swap_builder.add_rate(it->swap_helper.rate);
            swap_builder.add_tenor_time_unit(it->swap_helper.tenor_time_unit);
            swap_builder.add_tenor_number(it->swap_helper.tenor_number);
            swap_builder.add_calendar(it->swap_helper.calendar);
            swap_builder.add_sw_fixed_leg_frequency(it->swap_helper.sw_fixed_leg_frequency);
            swap_builder.add_sw_fixed_leg_convention(it->swap_helper.sw_fixed_leg_convention);
            swap_builder.add_sw_fixed_leg_day_counter(it->swap_helper.sw_fixed_leg_day_counter);
            swap_builder.add_sw_floating_leg_index(it->swap_helper.sw_floating_leg_index);
            swap_builder.add_spread(it->swap_helper.spread);
            swap_builder.add_fwd_start_days(it->swap_helper.fwd_start_days);
            auto swap = swap_builder.Finish();

            auto swap_wrapper_builder = quantra::PointsWrapperBuilder(*builder);
            swap_wrapper_builder.add_point_wrapper_type(quantra::Point_SwapHelper);
            swap_wrapper_builder.add_point_wrapper(swap.Union());
            auto swap_wrapper = swap_wrapper_builder.Finish();

            points_vector.push_back(swap_wrapper);

            break;
        case Bond:
            auto issue_date = builder->CreateString(it->bond_helper.issue_date);
            auto schedule = schedule_to_fbs(builder, it->bond_helper.schedule);
            auto bond_helper_builder = quantra::BondHelperBuilder(*builder);
            bond_helper_builder.add_rate(it->bond_helper.rate);
            bond_helper_builder.add_settlement_days(it->bond_helper.settlement_days);
            bond_helper_builder.add_face_amount(it->bond_helper.face_amount);
            bond_helper_builder.add_schedule(schedule);
            bond_helper_builder.add_coupon_rate(it->bond_helper.coupon_rate);
            bond_helper_builder.add_day_counter(it->bond_helper.day_counter);
            bond_helper_builder.add_business_day_convention(it->bond_helper.business_day_convention);
            bond_helper_builder.add_redemption(it->bond_helper.redemption);
            bond_helper_builder.add_issue_date(issue_date);
            auto bond_helper = bond_helper_builder.Finish();

            auto bond_wrapper_builder = quantra::PointsWrapperBuilder(*builder);
            bond_wrapper_builder.add_point_wrapper_type(quantra::Point_BondHelper);
            bond_wrapper_builder.add_point_wrapper(bond_helper.Union());
            auto point_wrapper = bond_wrapper_builder.Finish();

            points_vector.push_back(point_wrapper);
            break;

        default:
            break;
        }
    }

    auto points = builder->CreateVector(points_vector);

    // Create the termstructure curve
    auto id = builder->CreateString("depos_curve");
    auto term_structure_builder = quantra::TermStructureBuilder(*builder);
    term_structure_builder.add_bootstrap_trait(quantra::enums::BootstrapTrait_Discount);
    term_structure_builder.add_interpolator(quantra::enums::Interpolator_LogLinear);
    term_structure_builder.add_id(id);
    term_structure_builder.add_day_counter(quantra::enums::DayCounter_ActualActual365);
    term_structure_builder.add_as_of_date(settlement_date);
    term_structure_builder.add_points(points);
    auto term_structure = term_structure_builder.Finish();
}

// flatbuffers::Offset<quantra::Pricing> pricing_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, Pricing &pricing)
// {
//     std::vector<flatbuffers::Offset<quantra::TermStructure>> term_structures_vector;

//     for (auto it = pricing.curves.begin(); it < pricing.curves.end(); it++)
//     {
//         term_structures_vector.push_back(*it);
//     }

//     auto term_structures = builder->CreateVector(term_structures_vector);

//     auto as_of_date = builder->CreateString("2008/09/16");
//     auto pricing_builder = quantra::PricingBuilder(*builder);
//     pricing_builder.add_as_of_date(as_of_date);
//     pricing_builder.add_curves(term_structures);
//     return pricing_builder.Finish();
// }