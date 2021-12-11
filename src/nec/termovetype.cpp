#include "termovetype.h"

namespace Nec {

namespace TerMoveType {

const std::vector<TerMoveTypeMeta> data = {
    {TerMoveTypeKey::Road,          "Road"},
    {TerMoveTypeKey::Plain,         "Plain"},
    {TerMoveTypeKey::Brush,         "Brush"},
    {TerMoveTypeKey::Hill,          "Hill"},
    {TerMoveTypeKey::Mountain,      "Mountain"},
    {TerMoveTypeKey::Valley,        "Valley"},
    {TerMoveTypeKey::Rock,          "Rock"},
    {TerMoveTypeKey::Forest,        "Forest"},
    {TerMoveTypeKey::ShallowWater,  "Shallow Water"},
    {TerMoveTypeKey::DeepWater,     "Deep Water"},
    {TerMoveTypeKey::Beach,         "Beach"}
};

} // namespace TerMoveType

} // namespace Nec
