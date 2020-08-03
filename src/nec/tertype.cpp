#include "tertype.h"

namespace Nec {

// Terrain Data

std::vector<TerTypeData> TER_TYPE_DATA;

std::vector<std::string> TER_GROUP_NAMES;

void initTerTypeData () {
    TER_GROUP_NAMES.resize(int(TerTypeData::TER_LAST + 1));
        TER_GROUP_NAMES[TerTypeData::TER_PLAINS]    = "Plains";
        TER_GROUP_NAMES[TerTypeData::TER_ROADS]     = "Roads";
        TER_GROUP_NAMES[TerTypeData::TER_HILLS]     = "Hills";
        TER_GROUP_NAMES[TerTypeData::TER_ROCKS]     = "Rocks";
        TER_GROUP_NAMES[TerTypeData::TER_MOUNTAINS] = "Mountains";
        TER_GROUP_NAMES[TerTypeData::TER_VALLEY]    = "Valley";
        TER_GROUP_NAMES[TerTypeData::TER_SAND]      = "Sand";
        TER_GROUP_NAMES[TerTypeData::TER_BRUSH]     = "Brush";
        TER_GROUP_NAMES[TerTypeData::TER_FOREST]    = "Forest";
        TER_GROUP_NAMES[TerTypeData::TER_BEACH]     = "Beach";
        TER_GROUP_NAMES[TerTypeData::TER_SHALLOW]   = "Shallow Water";
        TER_GROUP_NAMES[TerTypeData::TER_DEEP]      = "Deep Water";
        TER_GROUP_NAMES[TerTypeData::TER_HARBOR]    = "Harbor";
        TER_GROUP_NAMES[TerTypeData::TER_COAST]     = "Coasts";
    TER_TYPE_DATA.push_back(TerTypeData("Plains",        1.05, TerTypeData::TER_PLAINS));
    TER_TYPE_DATA.push_back(TerTypeData("Roads",         1.00, TerTypeData::TER_ROADS));
    TER_TYPE_DATA.push_back(TerTypeData("Hills",         1.20, TerTypeData::TER_HILLS));
    TER_TYPE_DATA.push_back(TerTypeData("Rocks",         1.30, TerTypeData::TER_ROCKS));
    TER_TYPE_DATA.push_back(TerTypeData("Valley",        1.00, TerTypeData::TER_VALLEY));
    TER_TYPE_DATA.push_back(TerTypeData("Mountains",     1.40, TerTypeData::TER_MOUNTAINS));
    TER_TYPE_DATA.push_back(TerTypeData("Roads",         1.00, TerTypeData::TER_ROADS));
    TER_TYPE_DATA.push_back(TerTypeData("Plains",        1.05, TerTypeData::TER_PLAINS));
    TER_TYPE_DATA.push_back(TerTypeData("Forest",        1.25, TerTypeData::TER_FOREST));
    TER_TYPE_DATA.push_back(TerTypeData("Brush",         1.08, TerTypeData::TER_BRUSH));
    TER_TYPE_DATA.push_back(TerTypeData("Rocks",         1.28, TerTypeData::TER_ROCKS));
    TER_TYPE_DATA.push_back(TerTypeData("Sea Cliff",     1.32, TerTypeData::TER_COAST));
    TER_TYPE_DATA.push_back(TerTypeData("Shallow Water", 1.12, TerTypeData::TER_SHALLOW));
    TER_TYPE_DATA.push_back(TerTypeData("Deep Water",    1.06, TerTypeData::TER_DEEP));
    TER_TYPE_DATA.push_back(TerTypeData("Harbor",        1.10, TerTypeData::TER_HARBOR));
    TER_TYPE_DATA.push_back(TerTypeData("Roads",         1.00, TerTypeData::TER_ROADS));
    TER_TYPE_DATA.push_back(TerTypeData("Bridge",        1.02, TerTypeData::TER_ROADS));
    TER_TYPE_DATA.push_back(TerTypeData("Valley",        1.00, TerTypeData::TER_VALLEY));
    TER_TYPE_DATA.push_back(TerTypeData("Beach",         1.15, TerTypeData::TER_BEACH));
    TER_TYPE_DATA.push_back(TerTypeData("Desert Cliff",  1.35, TerTypeData::TER_MOUNTAINS));
    TER_TYPE_DATA.push_back(TerTypeData("Sand",          1.04, TerTypeData::TER_SAND));
    TER_TYPE_DATA.push_back(TerTypeData("Roads",         1.00, TerTypeData::TER_ROADS));
    TER_TYPE_DATA.push_back(TerTypeData("Beach Cliff",   1.20, TerTypeData::TER_COAST));
    TER_TYPE_DATA.push_back(TerTypeData("Mountains",     1.40, TerTypeData::TER_MOUNTAINS));
    TER_TYPE_DATA.push_back(TerTypeData("Hills",         1.20, TerTypeData::TER_HILLS));
    TER_TYPE_DATA.push_back(TerTypeData("Rocks",         1.30, TerTypeData::TER_ROCKS));
    TER_TYPE_DATA.push_back(TerTypeData("Valley",        1.00, TerTypeData::TER_VALLEY));
    TER_TYPE_DATA.push_back(TerTypeData("Roads",         1.00, TerTypeData::TER_ROADS)); // Valley
    TER_TYPE_DATA.push_back(TerTypeData("Plains",        1.05, TerTypeData::TER_PLAINS)); // Desert
    TER_TYPE_DATA.push_back(TerTypeData("Forest",        1.25, TerTypeData::TER_FOREST)); // Desert
    TER_TYPE_DATA.push_back(TerTypeData("Roads",         1.00, TerTypeData::TER_ROADS));
    TER_TYPE_DATA.push_back(TerTypeData("Roads",         1.00, TerTypeData::TER_ROADS));
    TER_TYPE_DATA.push_back(TerTypeData("HQ",            1.35, TerTypeData::TER_ROADS));
    TER_TYPE_DATA.push_back(TerTypeData("HQ",            1.35, TerTypeData::TER_ROADS));
    TER_TYPE_DATA.push_back(TerTypeData("HQ",            1.35, TerTypeData::TER_ROADS));
    TER_TYPE_DATA.push_back(TerTypeData("HQ",            1.35, TerTypeData::TER_ROADS));
    TER_TYPE_DATA.push_back(TerTypeData("Depot",         1.00, TerTypeData::TER_ROADS));
}

//

}
