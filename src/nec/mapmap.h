#ifndef NEC_MAPMAP_H
#define NEC_MAPMAP_H

#include <iostream>
#include <vector>

#include "raw/bytestring.h"

namespace Nec {

class MapMap : public std::vector<Raw::ByteString> {
public:
    static const std::size_t    QUADRANT_WIDTH  = 15;
    static const std::size_t    QUADRANT_HEIGHT = 10;
    static const std::size_t    PADDING         = 2;
    static const std::size_t    MAX_SIZE;

                                MapMap();
    explicit                    MapMap(std::size_t, std::size_t);

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    void                        resize(std::size_t);

    static std::size_t          getWidth(std::size_t);
    static std::size_t          getHeight(std::size_t);
    static std::size_t          getSize(std::size_t, std::size_t);

    std::size_t                 qX;
    std::size_t                 qY;
};

} // namespace Nec

#endif // NEC_MAPMAP_H
