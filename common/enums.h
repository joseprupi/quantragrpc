#include <ql/quantlib.hpp>

#include "enums_generated.h"

#ifndef ENUMS_H
#define ENUMS_H

QuantLib::TimeUnit TimeUnitToQL(quantra::enums::TimeUnit timeUnit);
QuantLib::Calendar CalendarToQL(quantra::enums::Calendar calendar);
QuantLib::BusinessDayConvention ConventionToQL(quantra::enums::BusinessDayConvention dayConvention);
QuantLib::DayCounter DayCounterToQL(quantra::enums::DayCounter dayCounter);
QuantLib::Frequency FrequencyToQL(quantra::enums::Frequency frequency);
std::shared_ptr<QuantLib::IborIndex> IborToQL(quantra::enums::Ibor ibor);
QuantLib::DateGeneration::Rule DateGenerationToQL(quantra::enums::DateGenerationRule dateGeneration);
QuantLib::Compounding CompoundingToQL(quantra::enums::Compounding compounding);

#endif //ENUMS_H