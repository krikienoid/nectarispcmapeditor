#ifndef NEC_MAPINFO_H
#define NEC_MAPINFO_H

// Dependencies

#include <iostream>

#include "raw/byte.h"
#include "raw/bytestring.h"
#include "coordinates.h"
#include "mapname.h"

namespace Nec {

// Class

struct MapInfo {

    static const std::size_t SIZE = 0x40;

    MapInfo ();

    std::istream&     read         (std::istream&);
    std::ostream&     write        (std::ostream&)     const;

    Raw::Byte       mapNumber;
    Raw::Byte       unknown1;
    Raw::Byte       quadrantsX;
    Raw::Byte       quadrantsY;
    Raw::ByteString playerRole;   // size  4
    Raw::ByteString playerStance; // size 16
    Raw::ByteString bgFiles;      // size  5
    Raw::ByteString unknown2;     // size  3

    MapName         mapName;      // size  6
    Coordinates     playerHQs[4]; // size  8
    Raw::ByteString unknown3;     // size 10
    Raw::ByteString addressMap;   // size  4
    Raw::ByteString addressUnit;  // size  4

};

//

} // namespace Nec

#endif // NEC_MAPINFO_H
