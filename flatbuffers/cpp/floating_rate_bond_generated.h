// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_FLOATINGRATEBOND_QUANTRA_H_
#define FLATBUFFERS_GENERATED_FLOATINGRATEBOND_QUANTRA_H_

#include "flatbuffers/flatbuffers.h"

#include "enums_generated.h"
#include "schedule_generated.h"
#include "index_generated.h"

namespace quantra {

struct FloatingRateBond;
struct FloatingRateBondBuilder;
struct FloatingRateBondT;

struct FloatingRateBondT : public flatbuffers::NativeTable {
  typedef FloatingRateBond TableType;
  int32_t settlement_days = 0;
  double face_amount = 0.0;
  std::unique_ptr<quantra::ScheduleT> schedule{};
  std::unique_ptr<quantra::IndexT> index{};
  quantra::enums::DayCounter accrual_day_counter = quantra::enums::DayCounter_Actual360;
  quantra::enums::BusinessDayConvention payment_convention = quantra::enums::BusinessDayConvention_Following;
  int32_t fixing_days = 0;
  double spread = 0.0;
  bool in_arrears = false;
  double redemption = 0.0;
  std::string issue_date{};
};

struct FloatingRateBond FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef FloatingRateBondT NativeTableType;
  typedef FloatingRateBondBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_SETTLEMENT_DAYS = 4,
    VT_FACE_AMOUNT = 6,
    VT_SCHEDULE = 8,
    VT_INDEX = 10,
    VT_ACCRUAL_DAY_COUNTER = 12,
    VT_PAYMENT_CONVENTION = 14,
    VT_FIXING_DAYS = 16,
    VT_SPREAD = 18,
    VT_IN_ARREARS = 20,
    VT_REDEMPTION = 22,
    VT_ISSUE_DATE = 24
  };
  int32_t settlement_days() const {
    return GetField<int32_t>(VT_SETTLEMENT_DAYS, 0);
  }
  double face_amount() const {
    return GetField<double>(VT_FACE_AMOUNT, 0.0);
  }
  const quantra::Schedule *schedule() const {
    return GetPointer<const quantra::Schedule *>(VT_SCHEDULE);
  }
  const quantra::Index *index() const {
    return GetPointer<const quantra::Index *>(VT_INDEX);
  }
  quantra::enums::DayCounter accrual_day_counter() const {
    return static_cast<quantra::enums::DayCounter>(GetField<int8_t>(VT_ACCRUAL_DAY_COUNTER, 0));
  }
  quantra::enums::BusinessDayConvention payment_convention() const {
    return static_cast<quantra::enums::BusinessDayConvention>(GetField<int8_t>(VT_PAYMENT_CONVENTION, 0));
  }
  int32_t fixing_days() const {
    return GetField<int32_t>(VT_FIXING_DAYS, 0);
  }
  double spread() const {
    return GetField<double>(VT_SPREAD, 0.0);
  }
  bool in_arrears() const {
    return GetField<uint8_t>(VT_IN_ARREARS, 0) != 0;
  }
  double redemption() const {
    return GetField<double>(VT_REDEMPTION, 0.0);
  }
  const flatbuffers::String *issue_date() const {
    return GetPointer<const flatbuffers::String *>(VT_ISSUE_DATE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_SETTLEMENT_DAYS) &&
           VerifyField<double>(verifier, VT_FACE_AMOUNT) &&
           VerifyOffset(verifier, VT_SCHEDULE) &&
           verifier.VerifyTable(schedule()) &&
           VerifyOffset(verifier, VT_INDEX) &&
           verifier.VerifyTable(index()) &&
           VerifyField<int8_t>(verifier, VT_ACCRUAL_DAY_COUNTER) &&
           VerifyField<int8_t>(verifier, VT_PAYMENT_CONVENTION) &&
           VerifyField<int32_t>(verifier, VT_FIXING_DAYS) &&
           VerifyField<double>(verifier, VT_SPREAD) &&
           VerifyField<uint8_t>(verifier, VT_IN_ARREARS) &&
           VerifyField<double>(verifier, VT_REDEMPTION) &&
           VerifyOffset(verifier, VT_ISSUE_DATE) &&
           verifier.VerifyString(issue_date()) &&
           verifier.EndTable();
  }
  FloatingRateBondT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(FloatingRateBondT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<FloatingRateBond> Pack(flatbuffers::FlatBufferBuilder &_fbb, const FloatingRateBondT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct FloatingRateBondBuilder {
  typedef FloatingRateBond Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_settlement_days(int32_t settlement_days) {
    fbb_.AddElement<int32_t>(FloatingRateBond::VT_SETTLEMENT_DAYS, settlement_days, 0);
  }
  void add_face_amount(double face_amount) {
    fbb_.AddElement<double>(FloatingRateBond::VT_FACE_AMOUNT, face_amount, 0.0);
  }
  void add_schedule(flatbuffers::Offset<quantra::Schedule> schedule) {
    fbb_.AddOffset(FloatingRateBond::VT_SCHEDULE, schedule);
  }
  void add_index(flatbuffers::Offset<quantra::Index> index) {
    fbb_.AddOffset(FloatingRateBond::VT_INDEX, index);
  }
  void add_accrual_day_counter(quantra::enums::DayCounter accrual_day_counter) {
    fbb_.AddElement<int8_t>(FloatingRateBond::VT_ACCRUAL_DAY_COUNTER, static_cast<int8_t>(accrual_day_counter), 0);
  }
  void add_payment_convention(quantra::enums::BusinessDayConvention payment_convention) {
    fbb_.AddElement<int8_t>(FloatingRateBond::VT_PAYMENT_CONVENTION, static_cast<int8_t>(payment_convention), 0);
  }
  void add_fixing_days(int32_t fixing_days) {
    fbb_.AddElement<int32_t>(FloatingRateBond::VT_FIXING_DAYS, fixing_days, 0);
  }
  void add_spread(double spread) {
    fbb_.AddElement<double>(FloatingRateBond::VT_SPREAD, spread, 0.0);
  }
  void add_in_arrears(bool in_arrears) {
    fbb_.AddElement<uint8_t>(FloatingRateBond::VT_IN_ARREARS, static_cast<uint8_t>(in_arrears), 0);
  }
  void add_redemption(double redemption) {
    fbb_.AddElement<double>(FloatingRateBond::VT_REDEMPTION, redemption, 0.0);
  }
  void add_issue_date(flatbuffers::Offset<flatbuffers::String> issue_date) {
    fbb_.AddOffset(FloatingRateBond::VT_ISSUE_DATE, issue_date);
  }
  explicit FloatingRateBondBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<FloatingRateBond> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<FloatingRateBond>(end);
    return o;
  }
};

inline flatbuffers::Offset<FloatingRateBond> CreateFloatingRateBond(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t settlement_days = 0,
    double face_amount = 0.0,
    flatbuffers::Offset<quantra::Schedule> schedule = 0,
    flatbuffers::Offset<quantra::Index> index = 0,
    quantra::enums::DayCounter accrual_day_counter = quantra::enums::DayCounter_Actual360,
    quantra::enums::BusinessDayConvention payment_convention = quantra::enums::BusinessDayConvention_Following,
    int32_t fixing_days = 0,
    double spread = 0.0,
    bool in_arrears = false,
    double redemption = 0.0,
    flatbuffers::Offset<flatbuffers::String> issue_date = 0) {
  FloatingRateBondBuilder builder_(_fbb);
  builder_.add_redemption(redemption);
  builder_.add_spread(spread);
  builder_.add_face_amount(face_amount);
  builder_.add_issue_date(issue_date);
  builder_.add_fixing_days(fixing_days);
  builder_.add_index(index);
  builder_.add_schedule(schedule);
  builder_.add_settlement_days(settlement_days);
  builder_.add_in_arrears(in_arrears);
  builder_.add_payment_convention(payment_convention);
  builder_.add_accrual_day_counter(accrual_day_counter);
  return builder_.Finish();
}

inline flatbuffers::Offset<FloatingRateBond> CreateFloatingRateBondDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t settlement_days = 0,
    double face_amount = 0.0,
    flatbuffers::Offset<quantra::Schedule> schedule = 0,
    flatbuffers::Offset<quantra::Index> index = 0,
    quantra::enums::DayCounter accrual_day_counter = quantra::enums::DayCounter_Actual360,
    quantra::enums::BusinessDayConvention payment_convention = quantra::enums::BusinessDayConvention_Following,
    int32_t fixing_days = 0,
    double spread = 0.0,
    bool in_arrears = false,
    double redemption = 0.0,
    const char *issue_date = nullptr) {
  auto issue_date__ = issue_date ? _fbb.CreateString(issue_date) : 0;
  return quantra::CreateFloatingRateBond(
      _fbb,
      settlement_days,
      face_amount,
      schedule,
      index,
      accrual_day_counter,
      payment_convention,
      fixing_days,
      spread,
      in_arrears,
      redemption,
      issue_date__);
}

flatbuffers::Offset<FloatingRateBond> CreateFloatingRateBond(flatbuffers::FlatBufferBuilder &_fbb, const FloatingRateBondT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline FloatingRateBondT *FloatingRateBond::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<FloatingRateBondT>(new FloatingRateBondT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void FloatingRateBond::UnPackTo(FloatingRateBondT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = settlement_days(); _o->settlement_days = _e; }
  { auto _e = face_amount(); _o->face_amount = _e; }
  { auto _e = schedule(); if (_e) { if(_o->schedule) { _e->UnPackTo(_o->schedule.get(), _resolver); } else { _o->schedule = std::unique_ptr<quantra::ScheduleT>(_e->UnPack(_resolver)); } } }
  { auto _e = index(); if (_e) { if(_o->index) { _e->UnPackTo(_o->index.get(), _resolver); } else { _o->index = std::unique_ptr<quantra::IndexT>(_e->UnPack(_resolver)); } } }
  { auto _e = accrual_day_counter(); _o->accrual_day_counter = _e; }
  { auto _e = payment_convention(); _o->payment_convention = _e; }
  { auto _e = fixing_days(); _o->fixing_days = _e; }
  { auto _e = spread(); _o->spread = _e; }
  { auto _e = in_arrears(); _o->in_arrears = _e; }
  { auto _e = redemption(); _o->redemption = _e; }
  { auto _e = issue_date(); if (_e) _o->issue_date = _e->str(); }
}

inline flatbuffers::Offset<FloatingRateBond> FloatingRateBond::Pack(flatbuffers::FlatBufferBuilder &_fbb, const FloatingRateBondT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateFloatingRateBond(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<FloatingRateBond> CreateFloatingRateBond(flatbuffers::FlatBufferBuilder &_fbb, const FloatingRateBondT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const FloatingRateBondT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _settlement_days = _o->settlement_days;
  auto _face_amount = _o->face_amount;
  auto _schedule = _o->schedule ? CreateSchedule(_fbb, _o->schedule.get(), _rehasher) : 0;
  auto _index = _o->index ? CreateIndex(_fbb, _o->index.get(), _rehasher) : 0;
  auto _accrual_day_counter = _o->accrual_day_counter;
  auto _payment_convention = _o->payment_convention;
  auto _fixing_days = _o->fixing_days;
  auto _spread = _o->spread;
  auto _in_arrears = _o->in_arrears;
  auto _redemption = _o->redemption;
  auto _issue_date = _o->issue_date.empty() ? 0 : _fbb.CreateString(_o->issue_date);
  return quantra::CreateFloatingRateBond(
      _fbb,
      _settlement_days,
      _face_amount,
      _schedule,
      _index,
      _accrual_day_counter,
      _payment_convention,
      _fixing_days,
      _spread,
      _in_arrears,
      _redemption,
      _issue_date);
}

inline const quantra::FloatingRateBond *GetFloatingRateBond(const void *buf) {
  return flatbuffers::GetRoot<quantra::FloatingRateBond>(buf);
}

inline const quantra::FloatingRateBond *GetSizePrefixedFloatingRateBond(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<quantra::FloatingRateBond>(buf);
}

inline bool VerifyFloatingRateBondBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<quantra::FloatingRateBond>(nullptr);
}

inline bool VerifySizePrefixedFloatingRateBondBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<quantra::FloatingRateBond>(nullptr);
}

inline void FinishFloatingRateBondBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<quantra::FloatingRateBond> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedFloatingRateBondBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<quantra::FloatingRateBond> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<quantra::FloatingRateBondT> UnPackFloatingRateBond(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<quantra::FloatingRateBondT>(GetFloatingRateBond(buf)->UnPack(res));
}

inline std::unique_ptr<quantra::FloatingRateBondT> UnPackSizePrefixedFloatingRateBond(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<quantra::FloatingRateBondT>(GetSizePrefixedFloatingRateBond(buf)->UnPack(res));
}

}  // namespace quantra

#endif  // FLATBUFFERS_GENERATED_FLOATINGRATEBOND_QUANTRA_H_
