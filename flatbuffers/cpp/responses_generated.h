// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_RESPONSES_QUANTRA_H_
#define FLATBUFFERS_GENERATED_RESPONSES_QUANTRA_H_

#include "flatbuffers/flatbuffers.h"

namespace quantra {

struct FlowInterest;
struct FlowInterestBuilder;

struct FlowPastInterest;
struct FlowPastInterestBuilder;

struct FlowNotional;
struct FlowNotionalBuilder;

struct FlowsWrapper;
struct FlowsWrapperBuilder;

struct FixedRateBondResponse;
struct FixedRateBondResponseBuilder;

struct PriceFixedRateBondResponse;
struct PriceFixedRateBondResponseBuilder;

enum Flow : uint8_t {
  Flow_NONE = 0,
  Flow_FlowInterest = 1,
  Flow_FlowPastInterest = 2,
  Flow_FlowNotional = 3,
  Flow_MIN = Flow_NONE,
  Flow_MAX = Flow_FlowNotional
};

inline const Flow (&EnumValuesFlow())[4] {
  static const Flow values[] = {
    Flow_NONE,
    Flow_FlowInterest,
    Flow_FlowPastInterest,
    Flow_FlowNotional
  };
  return values;
}

inline const char * const *EnumNamesFlow() {
  static const char * const names[5] = {
    "NONE",
    "FlowInterest",
    "FlowPastInterest",
    "FlowNotional",
    nullptr
  };
  return names;
}

inline const char *EnumNameFlow(Flow e) {
  if (flatbuffers::IsOutRange(e, Flow_NONE, Flow_FlowNotional)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesFlow()[index];
}

template<typename T> struct FlowTraits {
  static const Flow enum_value = Flow_NONE;
};

template<> struct FlowTraits<quantra::FlowInterest> {
  static const Flow enum_value = Flow_FlowInterest;
};

template<> struct FlowTraits<quantra::FlowPastInterest> {
  static const Flow enum_value = Flow_FlowPastInterest;
};

template<> struct FlowTraits<quantra::FlowNotional> {
  static const Flow enum_value = Flow_FlowNotional;
};

bool VerifyFlow(flatbuffers::Verifier &verifier, const void *obj, Flow type);
bool VerifyFlowVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct FlowInterest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef FlowInterestBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_AMOUNT = 4,
    VT_ACCRUAL_START_DATE = 6,
    VT_ACCRUAL_END_DATE = 8,
    VT_DISCOUNT = 10,
    VT_RATE = 12,
    VT_PRICE = 14
  };
  double amount() const {
    return GetField<double>(VT_AMOUNT, 0.0);
  }
  const flatbuffers::String *accrual_start_date() const {
    return GetPointer<const flatbuffers::String *>(VT_ACCRUAL_START_DATE);
  }
  const flatbuffers::String *accrual_end_date() const {
    return GetPointer<const flatbuffers::String *>(VT_ACCRUAL_END_DATE);
  }
  float discount() const {
    return GetField<float>(VT_DISCOUNT, 0.0f);
  }
  float rate() const {
    return GetField<float>(VT_RATE, 0.0f);
  }
  float price() const {
    return GetField<float>(VT_PRICE, 0.0f);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<double>(verifier, VT_AMOUNT) &&
           VerifyOffset(verifier, VT_ACCRUAL_START_DATE) &&
           verifier.VerifyString(accrual_start_date()) &&
           VerifyOffset(verifier, VT_ACCRUAL_END_DATE) &&
           verifier.VerifyString(accrual_end_date()) &&
           VerifyField<float>(verifier, VT_DISCOUNT) &&
           VerifyField<float>(verifier, VT_RATE) &&
           VerifyField<float>(verifier, VT_PRICE) &&
           verifier.EndTable();
  }
};

struct FlowInterestBuilder {
  typedef FlowInterest Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_amount(double amount) {
    fbb_.AddElement<double>(FlowInterest::VT_AMOUNT, amount, 0.0);
  }
  void add_accrual_start_date(flatbuffers::Offset<flatbuffers::String> accrual_start_date) {
    fbb_.AddOffset(FlowInterest::VT_ACCRUAL_START_DATE, accrual_start_date);
  }
  void add_accrual_end_date(flatbuffers::Offset<flatbuffers::String> accrual_end_date) {
    fbb_.AddOffset(FlowInterest::VT_ACCRUAL_END_DATE, accrual_end_date);
  }
  void add_discount(float discount) {
    fbb_.AddElement<float>(FlowInterest::VT_DISCOUNT, discount, 0.0f);
  }
  void add_rate(float rate) {
    fbb_.AddElement<float>(FlowInterest::VT_RATE, rate, 0.0f);
  }
  void add_price(float price) {
    fbb_.AddElement<float>(FlowInterest::VT_PRICE, price, 0.0f);
  }
  explicit FlowInterestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<FlowInterest> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<FlowInterest>(end);
    return o;
  }
};

inline flatbuffers::Offset<FlowInterest> CreateFlowInterest(
    flatbuffers::FlatBufferBuilder &_fbb,
    double amount = 0.0,
    flatbuffers::Offset<flatbuffers::String> accrual_start_date = 0,
    flatbuffers::Offset<flatbuffers::String> accrual_end_date = 0,
    float discount = 0.0f,
    float rate = 0.0f,
    float price = 0.0f) {
  FlowInterestBuilder builder_(_fbb);
  builder_.add_amount(amount);
  builder_.add_price(price);
  builder_.add_rate(rate);
  builder_.add_discount(discount);
  builder_.add_accrual_end_date(accrual_end_date);
  builder_.add_accrual_start_date(accrual_start_date);
  return builder_.Finish();
}

inline flatbuffers::Offset<FlowInterest> CreateFlowInterestDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    double amount = 0.0,
    const char *accrual_start_date = nullptr,
    const char *accrual_end_date = nullptr,
    float discount = 0.0f,
    float rate = 0.0f,
    float price = 0.0f) {
  auto accrual_start_date__ = accrual_start_date ? _fbb.CreateString(accrual_start_date) : 0;
  auto accrual_end_date__ = accrual_end_date ? _fbb.CreateString(accrual_end_date) : 0;
  return quantra::CreateFlowInterest(
      _fbb,
      amount,
      accrual_start_date__,
      accrual_end_date__,
      discount,
      rate,
      price);
}

struct FlowPastInterest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef FlowPastInterestBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_AMOUNT = 4,
    VT_ACCRUAL_START_DATE = 6,
    VT_ACCRUAL_END_DATE = 8,
    VT_RATE = 10
  };
  double amount() const {
    return GetField<double>(VT_AMOUNT, 0.0);
  }
  const flatbuffers::String *accrual_start_date() const {
    return GetPointer<const flatbuffers::String *>(VT_ACCRUAL_START_DATE);
  }
  const flatbuffers::String *accrual_end_date() const {
    return GetPointer<const flatbuffers::String *>(VT_ACCRUAL_END_DATE);
  }
  float rate() const {
    return GetField<float>(VT_RATE, 0.0f);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<double>(verifier, VT_AMOUNT) &&
           VerifyOffset(verifier, VT_ACCRUAL_START_DATE) &&
           verifier.VerifyString(accrual_start_date()) &&
           VerifyOffset(verifier, VT_ACCRUAL_END_DATE) &&
           verifier.VerifyString(accrual_end_date()) &&
           VerifyField<float>(verifier, VT_RATE) &&
           verifier.EndTable();
  }
};

struct FlowPastInterestBuilder {
  typedef FlowPastInterest Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_amount(double amount) {
    fbb_.AddElement<double>(FlowPastInterest::VT_AMOUNT, amount, 0.0);
  }
  void add_accrual_start_date(flatbuffers::Offset<flatbuffers::String> accrual_start_date) {
    fbb_.AddOffset(FlowPastInterest::VT_ACCRUAL_START_DATE, accrual_start_date);
  }
  void add_accrual_end_date(flatbuffers::Offset<flatbuffers::String> accrual_end_date) {
    fbb_.AddOffset(FlowPastInterest::VT_ACCRUAL_END_DATE, accrual_end_date);
  }
  void add_rate(float rate) {
    fbb_.AddElement<float>(FlowPastInterest::VT_RATE, rate, 0.0f);
  }
  explicit FlowPastInterestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<FlowPastInterest> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<FlowPastInterest>(end);
    return o;
  }
};

inline flatbuffers::Offset<FlowPastInterest> CreateFlowPastInterest(
    flatbuffers::FlatBufferBuilder &_fbb,
    double amount = 0.0,
    flatbuffers::Offset<flatbuffers::String> accrual_start_date = 0,
    flatbuffers::Offset<flatbuffers::String> accrual_end_date = 0,
    float rate = 0.0f) {
  FlowPastInterestBuilder builder_(_fbb);
  builder_.add_amount(amount);
  builder_.add_rate(rate);
  builder_.add_accrual_end_date(accrual_end_date);
  builder_.add_accrual_start_date(accrual_start_date);
  return builder_.Finish();
}

inline flatbuffers::Offset<FlowPastInterest> CreateFlowPastInterestDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    double amount = 0.0,
    const char *accrual_start_date = nullptr,
    const char *accrual_end_date = nullptr,
    float rate = 0.0f) {
  auto accrual_start_date__ = accrual_start_date ? _fbb.CreateString(accrual_start_date) : 0;
  auto accrual_end_date__ = accrual_end_date ? _fbb.CreateString(accrual_end_date) : 0;
  return quantra::CreateFlowPastInterest(
      _fbb,
      amount,
      accrual_start_date__,
      accrual_end_date__,
      rate);
}

struct FlowNotional FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef FlowNotionalBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_DATE = 4,
    VT_AMOUNT = 6,
    VT_DISCOUNT = 8,
    VT_PRICE = 10
  };
  const flatbuffers::String *date() const {
    return GetPointer<const flatbuffers::String *>(VT_DATE);
  }
  double amount() const {
    return GetField<double>(VT_AMOUNT, 0.0);
  }
  float discount() const {
    return GetField<float>(VT_DISCOUNT, 0.0f);
  }
  float price() const {
    return GetField<float>(VT_PRICE, 0.0f);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_DATE) &&
           verifier.VerifyString(date()) &&
           VerifyField<double>(verifier, VT_AMOUNT) &&
           VerifyField<float>(verifier, VT_DISCOUNT) &&
           VerifyField<float>(verifier, VT_PRICE) &&
           verifier.EndTable();
  }
};

struct FlowNotionalBuilder {
  typedef FlowNotional Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_date(flatbuffers::Offset<flatbuffers::String> date) {
    fbb_.AddOffset(FlowNotional::VT_DATE, date);
  }
  void add_amount(double amount) {
    fbb_.AddElement<double>(FlowNotional::VT_AMOUNT, amount, 0.0);
  }
  void add_discount(float discount) {
    fbb_.AddElement<float>(FlowNotional::VT_DISCOUNT, discount, 0.0f);
  }
  void add_price(float price) {
    fbb_.AddElement<float>(FlowNotional::VT_PRICE, price, 0.0f);
  }
  explicit FlowNotionalBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<FlowNotional> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<FlowNotional>(end);
    return o;
  }
};

inline flatbuffers::Offset<FlowNotional> CreateFlowNotional(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> date = 0,
    double amount = 0.0,
    float discount = 0.0f,
    float price = 0.0f) {
  FlowNotionalBuilder builder_(_fbb);
  builder_.add_amount(amount);
  builder_.add_price(price);
  builder_.add_discount(discount);
  builder_.add_date(date);
  return builder_.Finish();
}

inline flatbuffers::Offset<FlowNotional> CreateFlowNotionalDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *date = nullptr,
    double amount = 0.0,
    float discount = 0.0f,
    float price = 0.0f) {
  auto date__ = date ? _fbb.CreateString(date) : 0;
  return quantra::CreateFlowNotional(
      _fbb,
      date__,
      amount,
      discount,
      price);
}

struct FlowsWrapper FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef FlowsWrapperBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_FLOW_WRAPPER_TYPE = 4,
    VT_FLOW_WRAPPER = 6
  };
  quantra::Flow flow_wrapper_type() const {
    return static_cast<quantra::Flow>(GetField<uint8_t>(VT_FLOW_WRAPPER_TYPE, 0));
  }
  const void *flow_wrapper() const {
    return GetPointer<const void *>(VT_FLOW_WRAPPER);
  }
  template<typename T> const T *flow_wrapper_as() const;
  const quantra::FlowInterest *flow_wrapper_as_FlowInterest() const {
    return flow_wrapper_type() == quantra::Flow_FlowInterest ? static_cast<const quantra::FlowInterest *>(flow_wrapper()) : nullptr;
  }
  const quantra::FlowPastInterest *flow_wrapper_as_FlowPastInterest() const {
    return flow_wrapper_type() == quantra::Flow_FlowPastInterest ? static_cast<const quantra::FlowPastInterest *>(flow_wrapper()) : nullptr;
  }
  const quantra::FlowNotional *flow_wrapper_as_FlowNotional() const {
    return flow_wrapper_type() == quantra::Flow_FlowNotional ? static_cast<const quantra::FlowNotional *>(flow_wrapper()) : nullptr;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_FLOW_WRAPPER_TYPE) &&
           VerifyOffset(verifier, VT_FLOW_WRAPPER) &&
           VerifyFlow(verifier, flow_wrapper(), flow_wrapper_type()) &&
           verifier.EndTable();
  }
};

template<> inline const quantra::FlowInterest *FlowsWrapper::flow_wrapper_as<quantra::FlowInterest>() const {
  return flow_wrapper_as_FlowInterest();
}

template<> inline const quantra::FlowPastInterest *FlowsWrapper::flow_wrapper_as<quantra::FlowPastInterest>() const {
  return flow_wrapper_as_FlowPastInterest();
}

template<> inline const quantra::FlowNotional *FlowsWrapper::flow_wrapper_as<quantra::FlowNotional>() const {
  return flow_wrapper_as_FlowNotional();
}

struct FlowsWrapperBuilder {
  typedef FlowsWrapper Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_flow_wrapper_type(quantra::Flow flow_wrapper_type) {
    fbb_.AddElement<uint8_t>(FlowsWrapper::VT_FLOW_WRAPPER_TYPE, static_cast<uint8_t>(flow_wrapper_type), 0);
  }
  void add_flow_wrapper(flatbuffers::Offset<void> flow_wrapper) {
    fbb_.AddOffset(FlowsWrapper::VT_FLOW_WRAPPER, flow_wrapper);
  }
  explicit FlowsWrapperBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<FlowsWrapper> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<FlowsWrapper>(end);
    return o;
  }
};

inline flatbuffers::Offset<FlowsWrapper> CreateFlowsWrapper(
    flatbuffers::FlatBufferBuilder &_fbb,
    quantra::Flow flow_wrapper_type = quantra::Flow_NONE,
    flatbuffers::Offset<void> flow_wrapper = 0) {
  FlowsWrapperBuilder builder_(_fbb);
  builder_.add_flow_wrapper(flow_wrapper);
  builder_.add_flow_wrapper_type(flow_wrapper_type);
  return builder_.Finish();
}

struct FixedRateBondResponse FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef FixedRateBondResponseBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NPV = 4,
    VT_CLEAN_PRICE = 6,
    VT_DIRTY_PRICE = 8,
    VT_ACCRUED_AMOUNT = 10,
    VT_YIELD_VALUE = 12,
    VT_ACCRUED_DAYS = 14,
    VT_MACAULAY_DURATION = 16,
    VT_MODIFIED_DURATION = 18,
    VT_CONVEXITY = 20,
    VT_BPS = 22,
    VT_FLOWS = 24
  };
  double npv() const {
    return GetField<double>(VT_NPV, 0.0);
  }
  double clean_price() const {
    return GetField<double>(VT_CLEAN_PRICE, 0.0);
  }
  double dirty_price() const {
    return GetField<double>(VT_DIRTY_PRICE, 0.0);
  }
  double accrued_amount() const {
    return GetField<double>(VT_ACCRUED_AMOUNT, 0.0);
  }
  double yield_value() const {
    return GetField<double>(VT_YIELD_VALUE, 0.0);
  }
  double accrued_days() const {
    return GetField<double>(VT_ACCRUED_DAYS, 0.0);
  }
  double macaulay_duration() const {
    return GetField<double>(VT_MACAULAY_DURATION, 0.0);
  }
  double modified_duration() const {
    return GetField<double>(VT_MODIFIED_DURATION, 0.0);
  }
  double convexity() const {
    return GetField<double>(VT_CONVEXITY, 0.0);
  }
  double bps() const {
    return GetField<double>(VT_BPS, 0.0);
  }
  const flatbuffers::Vector<flatbuffers::Offset<quantra::FlowsWrapper>> *flows() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<quantra::FlowsWrapper>> *>(VT_FLOWS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<double>(verifier, VT_NPV) &&
           VerifyField<double>(verifier, VT_CLEAN_PRICE) &&
           VerifyField<double>(verifier, VT_DIRTY_PRICE) &&
           VerifyField<double>(verifier, VT_ACCRUED_AMOUNT) &&
           VerifyField<double>(verifier, VT_YIELD_VALUE) &&
           VerifyField<double>(verifier, VT_ACCRUED_DAYS) &&
           VerifyField<double>(verifier, VT_MACAULAY_DURATION) &&
           VerifyField<double>(verifier, VT_MODIFIED_DURATION) &&
           VerifyField<double>(verifier, VT_CONVEXITY) &&
           VerifyField<double>(verifier, VT_BPS) &&
           VerifyOffset(verifier, VT_FLOWS) &&
           verifier.VerifyVector(flows()) &&
           verifier.VerifyVectorOfTables(flows()) &&
           verifier.EndTable();
  }
};

struct FixedRateBondResponseBuilder {
  typedef FixedRateBondResponse Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_npv(double npv) {
    fbb_.AddElement<double>(FixedRateBondResponse::VT_NPV, npv, 0.0);
  }
  void add_clean_price(double clean_price) {
    fbb_.AddElement<double>(FixedRateBondResponse::VT_CLEAN_PRICE, clean_price, 0.0);
  }
  void add_dirty_price(double dirty_price) {
    fbb_.AddElement<double>(FixedRateBondResponse::VT_DIRTY_PRICE, dirty_price, 0.0);
  }
  void add_accrued_amount(double accrued_amount) {
    fbb_.AddElement<double>(FixedRateBondResponse::VT_ACCRUED_AMOUNT, accrued_amount, 0.0);
  }
  void add_yield_value(double yield_value) {
    fbb_.AddElement<double>(FixedRateBondResponse::VT_YIELD_VALUE, yield_value, 0.0);
  }
  void add_accrued_days(double accrued_days) {
    fbb_.AddElement<double>(FixedRateBondResponse::VT_ACCRUED_DAYS, accrued_days, 0.0);
  }
  void add_macaulay_duration(double macaulay_duration) {
    fbb_.AddElement<double>(FixedRateBondResponse::VT_MACAULAY_DURATION, macaulay_duration, 0.0);
  }
  void add_modified_duration(double modified_duration) {
    fbb_.AddElement<double>(FixedRateBondResponse::VT_MODIFIED_DURATION, modified_duration, 0.0);
  }
  void add_convexity(double convexity) {
    fbb_.AddElement<double>(FixedRateBondResponse::VT_CONVEXITY, convexity, 0.0);
  }
  void add_bps(double bps) {
    fbb_.AddElement<double>(FixedRateBondResponse::VT_BPS, bps, 0.0);
  }
  void add_flows(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<quantra::FlowsWrapper>>> flows) {
    fbb_.AddOffset(FixedRateBondResponse::VT_FLOWS, flows);
  }
  explicit FixedRateBondResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<FixedRateBondResponse> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<FixedRateBondResponse>(end);
    return o;
  }
};

inline flatbuffers::Offset<FixedRateBondResponse> CreateFixedRateBondResponse(
    flatbuffers::FlatBufferBuilder &_fbb,
    double npv = 0.0,
    double clean_price = 0.0,
    double dirty_price = 0.0,
    double accrued_amount = 0.0,
    double yield_value = 0.0,
    double accrued_days = 0.0,
    double macaulay_duration = 0.0,
    double modified_duration = 0.0,
    double convexity = 0.0,
    double bps = 0.0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<quantra::FlowsWrapper>>> flows = 0) {
  FixedRateBondResponseBuilder builder_(_fbb);
  builder_.add_bps(bps);
  builder_.add_convexity(convexity);
  builder_.add_modified_duration(modified_duration);
  builder_.add_macaulay_duration(macaulay_duration);
  builder_.add_accrued_days(accrued_days);
  builder_.add_yield_value(yield_value);
  builder_.add_accrued_amount(accrued_amount);
  builder_.add_dirty_price(dirty_price);
  builder_.add_clean_price(clean_price);
  builder_.add_npv(npv);
  builder_.add_flows(flows);
  return builder_.Finish();
}

inline flatbuffers::Offset<FixedRateBondResponse> CreateFixedRateBondResponseDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    double npv = 0.0,
    double clean_price = 0.0,
    double dirty_price = 0.0,
    double accrued_amount = 0.0,
    double yield_value = 0.0,
    double accrued_days = 0.0,
    double macaulay_duration = 0.0,
    double modified_duration = 0.0,
    double convexity = 0.0,
    double bps = 0.0,
    const std::vector<flatbuffers::Offset<quantra::FlowsWrapper>> *flows = nullptr) {
  auto flows__ = flows ? _fbb.CreateVector<flatbuffers::Offset<quantra::FlowsWrapper>>(*flows) : 0;
  return quantra::CreateFixedRateBondResponse(
      _fbb,
      npv,
      clean_price,
      dirty_price,
      accrued_amount,
      yield_value,
      accrued_days,
      macaulay_duration,
      modified_duration,
      convexity,
      bps,
      flows__);
}

struct PriceFixedRateBondResponse FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef PriceFixedRateBondResponseBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_BONDS = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<quantra::FixedRateBondResponse>> *bonds() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<quantra::FixedRateBondResponse>> *>(VT_BONDS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_BONDS) &&
           verifier.VerifyVector(bonds()) &&
           verifier.VerifyVectorOfTables(bonds()) &&
           verifier.EndTable();
  }
};

struct PriceFixedRateBondResponseBuilder {
  typedef PriceFixedRateBondResponse Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_bonds(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<quantra::FixedRateBondResponse>>> bonds) {
    fbb_.AddOffset(PriceFixedRateBondResponse::VT_BONDS, bonds);
  }
  explicit PriceFixedRateBondResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<PriceFixedRateBondResponse> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<PriceFixedRateBondResponse>(end);
    return o;
  }
};

inline flatbuffers::Offset<PriceFixedRateBondResponse> CreatePriceFixedRateBondResponse(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<quantra::FixedRateBondResponse>>> bonds = 0) {
  PriceFixedRateBondResponseBuilder builder_(_fbb);
  builder_.add_bonds(bonds);
  return builder_.Finish();
}

inline flatbuffers::Offset<PriceFixedRateBondResponse> CreatePriceFixedRateBondResponseDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<quantra::FixedRateBondResponse>> *bonds = nullptr) {
  auto bonds__ = bonds ? _fbb.CreateVector<flatbuffers::Offset<quantra::FixedRateBondResponse>>(*bonds) : 0;
  return quantra::CreatePriceFixedRateBondResponse(
      _fbb,
      bonds__);
}

inline bool VerifyFlow(flatbuffers::Verifier &verifier, const void *obj, Flow type) {
  switch (type) {
    case Flow_NONE: {
      return true;
    }
    case Flow_FlowInterest: {
      auto ptr = reinterpret_cast<const quantra::FlowInterest *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Flow_FlowPastInterest: {
      auto ptr = reinterpret_cast<const quantra::FlowPastInterest *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Flow_FlowNotional: {
      auto ptr = reinterpret_cast<const quantra::FlowNotional *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return true;
  }
}

inline bool VerifyFlowVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyFlow(
        verifier,  values->Get(i), types->GetEnum<Flow>(i))) {
      return false;
    }
  }
  return true;
}

}  // namespace quantra

#endif  // FLATBUFFERS_GENERATED_RESPONSES_QUANTRA_H_
