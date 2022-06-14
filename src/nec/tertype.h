#ifndef NEC_TERTYPE_H
#define NEC_TERTYPE_H

#include <string>
#include <vector>

#include "raw/int.h"
#include "termovetype.h"

namespace Nec {

namespace TerType {

struct TerTypeMeta {
    const Raw::UInt8            value;
    const std::string           name;
    const double                defense;
    const TerMoveTypeKey        terMoveType;
};

extern const std::vector<TerTypeMeta> data;

} // namespace TerType

} // namespace Nec

#endif // NEC_TERTYPE_H
