#ifndef NEC_BIGINFO_H
#define NEC_BIGINFO_H

#include <iostream>
#include <vector>

#include "mapinfo.h"

namespace Nec {

class BigInfo : public std::vector<MapInfo> {
public:
    static const std::size_t    LENGTH = 0x100;
    static const std::size_t    SIZE   = MapInfo::SIZE * LENGTH;

                                BigInfo();

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    bool                        mapInfoExists(const std::size_t) const;
};

} // namespace Nec

#endif // NEC_BIGINFO_H
