#include "term_structure_parser.h"

using namespace quantra;

std::shared_ptr<RateHelper> TermStructureParser::parse(uint8_t *buffer_pointer)
{
    auto termStructure = GetTermStructure(buffer_pointer);

    auto points = termStructure->Points();

    std::shared_ptr<TermStructurePointParser> tsparser = std::make_shared<TermStructurePointParser>();

    for (auto it = points.begin(points); it != points.end(points); ++it)
    {
        std::shared_ptr<RateHelper> rate_helper = tsparser->parse(it);
    }
}