#include "term_structure_parser.h"

using namespace quantra;

std::shared_ptr<RateHelper> TermStructureParser::parse(const quantra::TermStructure *ts)
{
    // auto points = ts->Points();

    // std::shared_ptr<TermStructurePointParser> tsparser = std::make_shared<TermStructurePointParser>();

    // for (auto it = points.begin(points); it != points.end(points); ++it)
    // {
    //     std::shared_ptr<RateHelper> rate_helper = tsparser->parse(it);
    // }

    return nullptr;
}