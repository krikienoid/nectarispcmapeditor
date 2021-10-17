#include "tertype.h"

namespace Nec {

namespace TerType {

const std::vector<TerTypeMeta> data = {
    {Raw::Byte(0x00), "Plains",        1.05, TerMoveTypeKey::Plain},
    {Raw::Byte(0x01), "Roads",         1.00, TerMoveTypeKey::Road},
    {Raw::Byte(0x02), "Hills",         1.20, TerMoveTypeKey::Hill},
    {Raw::Byte(0x03), "Rocks",         1.30, TerMoveTypeKey::Rock},
    {Raw::Byte(0x04), "Valley",        1.00, TerMoveTypeKey::Valley},
    {Raw::Byte(0x05), "Mountains",     1.40, TerMoveTypeKey::Mountain},
    {Raw::Byte(0x06), "Roads",         1.00, TerMoveTypeKey::Road},
    {Raw::Byte(0x07), "Plains",        1.05, TerMoveTypeKey::Plain},
    {Raw::Byte(0x08), "Forest",        1.25, TerMoveTypeKey::Forest},
    {Raw::Byte(0x09), "Brush",         1.08, TerMoveTypeKey::Brush},
    {Raw::Byte(0x0a), "Rocks",         1.28, TerMoveTypeKey::Rock},
    {Raw::Byte(0x0b), "Sea Cliff",     1.32, TerMoveTypeKey::Mountain},
    {Raw::Byte(0x0c), "Shallow Water", 1.12, TerMoveTypeKey::ShallowWater},
    {Raw::Byte(0x0d), "Deep Water",    1.06, TerMoveTypeKey::DeepWater},
    {Raw::Byte(0x0e), "Harbor",        1.10, TerMoveTypeKey::DeepWater},
    {Raw::Byte(0x0f), "Roads",         1.00, TerMoveTypeKey::Road},
    {Raw::Byte(0x10), "Bridge",        1.02, TerMoveTypeKey::Road},
    {Raw::Byte(0x11), "Valley",        1.00, TerMoveTypeKey::Valley},
    {Raw::Byte(0x12), "Beach",         1.15, TerMoveTypeKey::Beach},
    {Raw::Byte(0x13), "Desert Cliff",  1.35, TerMoveTypeKey::Mountain},
    {Raw::Byte(0x14), "Sand",          1.04, TerMoveTypeKey::Plain},
    {Raw::Byte(0x15), "Roads",         1.00, TerMoveTypeKey::Road},
    {Raw::Byte(0x16), "Beach Cliff",   1.20, TerMoveTypeKey::Mountain},
    {Raw::Byte(0x17), "Mountains",     1.40, TerMoveTypeKey::Mountain},
    {Raw::Byte(0x18), "Hills",         1.20, TerMoveTypeKey::Hill},
    {Raw::Byte(0x19), "Rocks",         1.30, TerMoveTypeKey::Rock},
    {Raw::Byte(0x1a), "Valley",        1.00, TerMoveTypeKey::Valley},
    {Raw::Byte(0x1b), "Roads",         1.00, TerMoveTypeKey::Road},   // Valley
    {Raw::Byte(0x1c), "Plains",        1.05, TerMoveTypeKey::Plain},  // Desert
    {Raw::Byte(0x1d), "Forest",        1.25, TerMoveTypeKey::Forest}, // Desert
    {Raw::Byte(0x1e), "Roads",         1.00, TerMoveTypeKey::Road},
    {Raw::Byte(0x1f), "Roads",         1.00, TerMoveTypeKey::Road}
};

} // namespace TerType

} // namespace Nec
