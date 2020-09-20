#ifndef NEC_TERTYPE_H
#define NEC_TERTYPE_H

#include <string>
#include <vector>

namespace Nec {

struct TerTypeData {
    enum TerGroup {
        TER_PLAINS,
        TER_ROADS,
        TER_HILLS,
        TER_ROCKS,
        TER_MOUNTAINS,
        TER_VALLEY,
        TER_SAND,
        TER_BRUSH,
        TER_FOREST,
        TER_BEACH,
        TER_SHALLOW,
        TER_DEEP,
        TER_HARBOR,
        TER_COAST,
        TER_FIRST = TER_PLAINS,
        TER_LAST  = TER_COAST
    };

                                TerTypeData(
                                    const std::string name,
                                    const double defMod,
                                    const TerGroup terGroup
                                ) :
                                    name(name),
                                    defMod(defMod),
                                    terGroup(terGroup)
                                {}

    std::string                 name;
    double                      defMod;
    TerGroup                    terGroup;
};

extern std::vector<TerTypeData> TER_TYPE_DATA;
extern std::vector<std::string> TER_GROUP_NAMES;

void initTerTypeData();

} // namespace Nec

#endif // NEC_TERTYPE_H
