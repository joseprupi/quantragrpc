#include <ql/quantlib.hpp>

#ifndef COMMON_H
#define COMMON_H

QuantLib::Date DateToQL(std::string date)
{
    return QuantLib::DateParser::parseFormatted(date, "%Y/%m/%d");
}

#endif //COMMON_H