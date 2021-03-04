#include "flatbuffers/grpc.h"

#include "quantra_structs.h";
#include "term_structure_generated.h"
#include "index_generated.h"
#include "common_generated.h"

flatbuffers::Offset<quantra::Yield> yield_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, Yield &yield);

flatbuffers::Offset<quantra::DepositHelper> deposit_to_fbs(std::shared_ptr<flatbuffers::grpc::MessageBuilder> builder, DepositHelper &deposit);