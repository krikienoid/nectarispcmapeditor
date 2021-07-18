#ifndef NEC_BIGINFO_H
#define NEC_BIGINFO_H

#include <iostream>
#include <vector>

#include "mapinfo.h"

namespace Nec {

class BigInfo {
public:
    static constexpr std::size_t    LENGTH = 0x100;
    static constexpr std::size_t    SIZE = MapInfo::SIZE * LENGTH;

                                BigInfo();

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    bool                        mapInfoExists(std::size_t) const;

    std::vector<MapInfo>        items;
};

} // namespace Nec

#endif // NEC_BIGINFO_H
