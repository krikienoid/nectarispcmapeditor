#ifndef NEC_MAPMAP_H
#define NEC_MAPMAP_H

#include <iostream>
#include <vector>

#include "raw/bytestring.h"
#include "mapsize.h"

namespace Nec {

class MapMap {
public:
                                MapMap();
    explicit                    MapMap(std::size_t, std::size_t);

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    void                        resize(std::size_t);

    std::size_t                 qX;
    std::size_t                 qY;

    std::vector<Raw::ByteString>    data;
};

} // namespace Nec

#endif // NEC_MAPMAP_H
