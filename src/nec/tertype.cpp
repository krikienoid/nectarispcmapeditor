#include "tertype.h"

namespace Nec {

namespace TerType {

const std::vector<TerTypeMeta> data = {
    {Raw::Byte(0x00), "Plains",        1.05, TerFilterGroup::Plain},
    {Raw::Byte(0x01), "Roads",         1.00, TerFilterGroup::Road},
    {Raw::Byte(0x02), "Hills",         1.20, TerFilterGroup::Hill},
    {Raw::Byte(0x03), "Rocks",         1.30, TerFilterGroup::Rock},
    {Raw::Byte(0x04), "Valley",        1.00, TerFilterGroup::Valley},
    {Raw::Byte(0x05), "Mountains",     1.40, TerFilterGroup::Mountain},
    {Raw::Byte(0x06), "Roads",         1.00, TerFilterGroup::Road},
    {Raw::Byte(0x07), "Plains",        1.05, TerFilterGroup::Plain},
    {Raw::Byte(0x08), "Forest",        1.25, TerFilterGroup::Forest},
    {Raw::Byte(0x09), "Brush",         1.08, TerFilterGroup::Brush},
    {Raw::Byte(0x0a), "Rocks",         1.28, TerFilterGroup::Rock},
    {Raw::Byte(0x0b), "Sea Cliff",     1.32, TerFilterGroup::Coast},
    {Raw::Byte(0x0c), "Shallow Water", 1.12, TerFilterGroup::ShallowWater},
    {Raw::Byte(0x0d), "Deep Water",    1.06, TerFilterGroup::DeepWater},
    {Raw::Byte(0x0e), "Harbor",        1.10, TerFilterGroup::Harbor},
    {Raw::Byte(0x0f), "Roads",         1.00, TerFilterGroup::Road},
    {Raw::Byte(0x10), "Bridge",        1.02, TerFilterGroup::Road},
    {Raw::Byte(0x11), "Valley",        1.00, TerFilterGroup::Valley},
    {Raw::Byte(0x12), "Beach",         1.15, TerFilterGroup::Beach},
    {Raw::Byte(0x13), "Desert Cliff",  1.35, TerFilterGroup::Mountain},
    {Raw::Byte(0x14), "Sand",          1.04, TerFilterGroup::Sand},
    {Raw::Byte(0x15), "Roads",         1.00, TerFilterGroup::Road},
    {Raw::Byte(0x16), "Beach Cliff",   1.20, TerFilterGroup::Coast},
    {Raw::Byte(0x17), "Mountains",     1.40, TerFilterGroup::Mountain},
    {Raw::Byte(0x18), "Hills",         1.20, TerFilterGroup::Hill},
    {Raw::Byte(0x19), "Rocks",         1.30, TerFilterGroup::Rock},
    {Raw::Byte(0x1a), "Valley",        1.00, TerFilterGroup::Valley},
    {Raw::Byte(0x1b), "Roads",         1.00, TerFilterGroup::Road},   // Valley
    {Raw::Byte(0x1c), "Plains",        1.05, TerFilterGroup::Plain},  // Desert
    {Raw::Byte(0x1d), "Forest",        1.25, TerFilterGroup::Forest}, // Desert
    {Raw::Byte(0x1e), "Roads",         1.00, TerFilterGroup::Road},
    {Raw::Byte(0x1f), "Roads",         1.00, TerFilterGroup::Road},
    {Raw::Byte(0x20), "HQ",            1.35, TerFilterGroup::Road},
    {Raw::Byte(0x21), "HQ",            1.35, TerFilterGroup::Road},
    {Raw::Byte(0x22), "HQ",            1.35, TerFilterGroup::Road},
    {Raw::Byte(0x23), "HQ",            1.35, TerFilterGroup::Road},
    {Raw::Byte(0x24), "Depot",         1.00, TerFilterGroup::Road}
};

const std::vector<std::string> terFilterGroupNames = {
    "Plain",
    "Road",
    "Hill",
    "Rock",
    "Mountain",
    "Valley",
    "Sand",
    "Brush",
    "Forest",
    "Beach",
    "Shallow Water",
    "Deep Water",
    "Harbor",
    "Coast"
};

} // namespace TerType

} // namespace Nec
