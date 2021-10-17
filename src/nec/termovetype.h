#ifndef NEC_TERMOVETYPE_H
#define NEC_TERMOVETYPE_H

#include <string>
#include <vector>

namespace Nec {

enum class TerMoveTypeKey {
    Road,
    Plain,
    Brush,
    Hill,
    Mountain,
    Valley,
    Rock,
    Forest,
    ShallowWater,
    DeepWater,
    Beach
};

namespace TerMoveType {

struct TerMoveTypeMeta {
    const TerMoveTypeKey        key;
    const std::string           name;
};

extern const std::vector<TerMoveTypeMeta> data;

} // namespace TerMoveType

} // namespace Nec

#endif // NEC_TERMOVETYPE_H
