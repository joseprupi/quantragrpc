#include "flatbuffers/grpc.h"

#include "quantra_structs.h"
#include "term_structure_generated.h"
#include "index_generated.h"
#include "common_generated.h"
#include "fixed_rate_bond_generated.h"
#include "floating_rate_bond_generated.h"
#include "price_fixed_rate_bond_request_generated.h"
#include "price_floating_rate_bond_request_generated.h"

using namespace structs;

flatbuffers::Offset<quantra::Yield> yield_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, Yield &yield);
flatbuffers::Offset<quantra::Pricing> pricing_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, Pricing &pricing);
flatbuffers::Offset<quantra::DepositHelper> deposit_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, DepositHelper &deposit);
flatbuffers::Offset<quantra::Schedule> schedule_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, Schedule &schedule);
flatbuffers::Offset<quantra::Index> index_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, Index &index);
flatbuffers::Offset<quantra::PointsWrapper> deposit_helper_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, DepositHelper &deposit_helper);
flatbuffers::Offset<quantra::PointsWrapper> FRAhelper_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, FRAHelper &FRA_helper);
flatbuffers::Offset<quantra::PointsWrapper> future_helper_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, FutureHelper &future_helper);
flatbuffers::Offset<quantra::PointsWrapper> swap_helper_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, SwapHelper &swap_helper);
flatbuffers::Offset<quantra::PointsWrapper> bond_helper_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, BondHelper &bond_helper);
flatbuffers::Offset<quantra::TermStructure> term_structure_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, TermStructure &term_structure);
flatbuffers::Offset<quantra::FixedRateBond> fixed_rate_bond_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, FixedRateBond &fixed_rate_bond);
flatbuffers::Offset<quantra::FloatingRateBond> floating_rate_bond_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, FloatingRateBond &floating_rate_bond);
flatbuffers::Offset<quantra::PriceFixedRateBond> price_fixe_rate_bond_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, PriceFixedRateBond &price_bond);
flatbuffers::Offset<quantra::PriceFixedRateBondRequest> price_fixe_rate_bond_request_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, PriceFixedRateBondRequest &price_bond);