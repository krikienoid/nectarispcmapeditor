#include "tertype.h"

namespace Nec {

std::vector<TerTypeMeta> TER_TYPE_DATA;
std::vector<std::string> TER_FILTER_GROUP_NAMES;

void initTerTypeMeta() {
    TER_FILTER_GROUP_NAMES.resize(static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::Last) + 1);
        TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::Plain)]        = "Plain";
        TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::Road)]         = "Road";
        TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::Hill)]         = "Hill";
        TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::Rock)]         = "Rock";
        TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::Mountain)]     = "Mountain";
        TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::Valley)]       = "Valley";
        TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::Sand)]         = "Sand";
        TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::Brush)]        = "Brush";
        TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::Forest)]       = "Forest";
        TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::Beach)]        = "Beach";
        TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::ShallowWater)] = "Shallow Water";
        TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::DeepWater)]    = "Deep Water";
        TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::Harbor)]       = "Harbor";
        TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(TerTypeMeta::TerFilterGroup::Coast)]        = "Coast";
    TER_TYPE_DATA.push_back(TerTypeMeta("Plains",        1.05, TerTypeMeta::TerFilterGroup::Plain));
    TER_TYPE_DATA.push_back(TerTypeMeta("Roads",         1.00, TerTypeMeta::TerFilterGroup::Road));
    TER_TYPE_DATA.push_back(TerTypeMeta("Hills",         1.20, TerTypeMeta::TerFilterGroup::Hill));
    TER_TYPE_DATA.push_back(TerTypeMeta("Rocks",         1.30, TerTypeMeta::TerFilterGroup::Rock));
    TER_TYPE_DATA.push_back(TerTypeMeta("Valley",        1.00, TerTypeMeta::TerFilterGroup::Valley));
    TER_TYPE_DATA.push_back(TerTypeMeta("Mountains",     1.40, TerTypeMeta::TerFilterGroup::Mountain));
    TER_TYPE_DATA.push_back(TerTypeMeta("Roads",         1.00, TerTypeMeta::TerFilterGroup::Road));
    TER_TYPE_DATA.push_back(TerTypeMeta("Plains",        1.05, TerTypeMeta::TerFilterGroup::Plain));
    TER_TYPE_DATA.push_back(TerTypeMeta("Forest",        1.25, TerTypeMeta::TerFilterGroup::Forest));
    TER_TYPE_DATA.push_back(TerTypeMeta("Brush",         1.08, TerTypeMeta::TerFilterGroup::Brush));
    TER_TYPE_DATA.push_back(TerTypeMeta("Rocks",         1.28, TerTypeMeta::TerFilterGroup::Rock));
    TER_TYPE_DATA.push_back(TerTypeMeta("Sea Cliff",     1.32, TerTypeMeta::TerFilterGroup::Coast));
    TER_TYPE_DATA.push_back(TerTypeMeta("Shallow Water", 1.12, TerTypeMeta::TerFilterGroup::ShallowWater));
    TER_TYPE_DATA.push_back(TerTypeMeta("Deep Water",    1.06, TerTypeMeta::TerFilterGroup::DeepWater));
    TER_TYPE_DATA.push_back(TerTypeMeta("Harbor",        1.10, TerTypeMeta::TerFilterGroup::Harbor));
    TER_TYPE_DATA.push_back(TerTypeMeta("Roads",         1.00, TerTypeMeta::TerFilterGroup::Road));
    TER_TYPE_DATA.push_back(TerTypeMeta("Bridge",        1.02, TerTypeMeta::TerFilterGroup::Road));
    TER_TYPE_DATA.push_back(TerTypeMeta("Valley",        1.00, TerTypeMeta::TerFilterGroup::Valley));
    TER_TYPE_DATA.push_back(TerTypeMeta("Beach",         1.15, TerTypeMeta::TerFilterGroup::Beach));
    TER_TYPE_DATA.push_back(TerTypeMeta("Desert Cliff",  1.35, TerTypeMeta::TerFilterGroup::Mountain));
    TER_TYPE_DATA.push_back(TerTypeMeta("Sand",          1.04, TerTypeMeta::TerFilterGroup::Sand));
    TER_TYPE_DATA.push_back(TerTypeMeta("Roads",         1.00, TerTypeMeta::TerFilterGroup::Road));
    TER_TYPE_DATA.push_back(TerTypeMeta("Beach Cliff",   1.20, TerTypeMeta::TerFilterGroup::Coast));
    TER_TYPE_DATA.push_back(TerTypeMeta("Mountains",     1.40, TerTypeMeta::TerFilterGroup::Mountain));
    TER_TYPE_DATA.push_back(TerTypeMeta("Hills",         1.20, TerTypeMeta::TerFilterGroup::Hill));
    TER_TYPE_DATA.push_back(TerTypeMeta("Rocks",         1.30, TerTypeMeta::TerFilterGroup::Rock));
    TER_TYPE_DATA.push_back(TerTypeMeta("Valley",        1.00, TerTypeMeta::TerFilterGroup::Valley));
    TER_TYPE_DATA.push_back(TerTypeMeta("Roads",         1.00, TerTypeMeta::TerFilterGroup::Road));   // Valley
    TER_TYPE_DATA.push_back(TerTypeMeta("Plains",        1.05, TerTypeMeta::TerFilterGroup::Plain));  // Desert
    TER_TYPE_DATA.push_back(TerTypeMeta("Forest",        1.25, TerTypeMeta::TerFilterGroup::Forest)); // Desert
    TER_TYPE_DATA.push_back(TerTypeMeta("Roads",         1.00, TerTypeMeta::TerFilterGroup::Road));
    TER_TYPE_DATA.push_back(TerTypeMeta("Roads",         1.00, TerTypeMeta::TerFilterGroup::Road));
    TER_TYPE_DATA.push_back(TerTypeMeta("HQ",            1.35, TerTypeMeta::TerFilterGroup::Road));
    TER_TYPE_DATA.push_back(TerTypeMeta("HQ",            1.35, TerTypeMeta::TerFilterGroup::Road));
    TER_TYPE_DATA.push_back(TerTypeMeta("HQ",            1.35, TerTypeMeta::TerFilterGroup::Road));
    TER_TYPE_DATA.push_back(TerTypeMeta("HQ",            1.35, TerTypeMeta::TerFilterGroup::Road));
    TER_TYPE_DATA.push_back(TerTypeMeta("Depot",         1.00, TerTypeMeta::TerFilterGroup::Road));
}

//

} // namespace Nec
