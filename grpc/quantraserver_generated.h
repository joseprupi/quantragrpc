// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_QUANTRASERVER_QUANTRA_H_
#define FLATBUFFERS_GENERATED_QUANTRASERVER_QUANTRA_H_

#include "flatbuffers/flatbuffers.h"

#include "bonds_generated.h"
#include "common_generated.h"
#include "curve_points_generated.h"
#include "enums_generated.h"
#include "requests_generated.h"
#include "term_structure_generated.h"

namespace quantra {

struct BondPricingReply;
struct BondPricingReplyBuilder;

struct BondPricingReply FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef BondPricingReplyBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_MESSAGE = 4
  };
  const flatbuffers::String *message() const {
    return GetPointer<const flatbuffers::String *>(VT_MESSAGE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_MESSAGE) &&
           verifier.VerifyString(message()) &&
           verifier.EndTable();
  }
};

struct BondPricingReplyBuilder {
  typedef BondPricingReply Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_message(flatbuffers::Offset<flatbuffers::String> message) {
    fbb_.AddOffset(BondPricingReply::VT_MESSAGE, message);
  }
  explicit BondPricingReplyBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<BondPricingReply> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<BondPricingReply>(end);
    return o;
  }
};

inline flatbuffers::Offset<BondPricingReply> CreateBondPricingReply(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> message = 0) {
  BondPricingReplyBuilder builder_(_fbb);
  builder_.add_message(message);
  return builder_.Finish();
}

inline flatbuffers::Offset<BondPricingReply> CreateBondPricingReplyDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *message = nullptr) {
  auto message__ = message ? _fbb.CreateString(message) : 0;
  return quantra::CreateBondPricingReply(
      _fbb,
      message__);
}

}  // namespace quantra

#endif  // FLATBUFFERS_GENERATED_QUANTRASERVER_QUANTRA_H_
