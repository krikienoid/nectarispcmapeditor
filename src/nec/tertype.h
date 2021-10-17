#ifndef NEC_TERTYPE_H
#define NEC_TERTYPE_H

#include <string>
#include <vector>

#include "raw/byte.h"

namespace Nec {

namespace TerType {

enum class TerFilterGroup {
    Plain,
    Road,
    Hill,
    Rock,
    Mountain,
    Valley,
    Sand,
    Brush,
    Forest,
    Beach,
    ShallowWater,
    DeepWater,
    Harbor,
    Coast,
    First = Plain,
    Last  = Coast
};

struct TerTypeMeta {
    const Raw::Byte             value;
    const std::string           name;
    const double                defense;
    const TerFilterGroup        terFilterGroup;
};

extern const std::vector<TerTypeMeta> data;
extern const std::vector<std::string> terFilterGroupNames;

} // namespace TerType

} // namespace Nec

#endif // NEC_TERTYPE_H
