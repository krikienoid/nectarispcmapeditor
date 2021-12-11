#ifndef NEC_LEVELMAP_H
#define NEC_LEVELMAP_H

#include <iostream>
#include <vector>

#include "raw/bytearray.h"
#include "mapsize.h"

namespace Nec {

class LevelMap {
public:
                                LevelMap();
    explicit                    LevelMap(std::size_t, std::size_t);

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    std::size_t                 cX;
    std::size_t                 cY;

    std::vector<Raw::ByteArray> items;
};

} // namespace Nec

#endif // NEC_LEVELMAP_H
