#ifndef NEC_TERTYPE_H
#define NEC_TERTYPE_H

#include <string>
#include <vector>

namespace Nec {

struct TerTypeMeta {
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

                                TerTypeMeta(
                                    const std::string& name,
                                    const double defense,
                                    const TerFilterGroup terFilterGroup
                                ) :
                                    name(name),
                                    defense(defense),
                                    terFilterGroup(terFilterGroup)
                                {}

    std::string                 name;
    double                      defense;
    TerFilterGroup              terFilterGroup;
};

extern std::vector<TerTypeMeta> TER_TYPE_DATA;
extern std::vector<std::string> TER_FILTER_GROUP_NAMES;

void initTerTypeMeta();

} // namespace Nec

#endif // NEC_TERTYPE_H
