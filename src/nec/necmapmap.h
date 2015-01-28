#ifndef NEC_MAPMAP_H
#define NEC_MAPMAP_H

// Dependencies

#include <iostream>
#include <vector>
#include "bytes/bytestring.h"

namespace Nec {

// Class

class MapMap : public std::vector<ByteString> {

public:

    static const std::size_t QUADRANT_WIDTH  = 15;
    static const std::size_t QUADRANT_HEIGHT = 10;
    static const std::size_t PADDING         = 2;
    static const std::size_t MAX_SIZE;

    MapMap ();
    MapMap (const std::size_t, const std::size_t);

    std::istream& read           (std::istream&);
    std::ostream& write          (std::ostream&)     const;

    void          resize         (const std::size_t);

    static std::size_t getWidth  (const std::size_t qX);
    static std::size_t getHeight (const std::size_t qY);
    static std::size_t getSize   (const std::size_t qX, const std::size_t qY);

    std::size_t qX;
    std::size_t qY;
};

//

}

#endif // NEC_MAPMAP_H
