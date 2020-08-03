#ifndef NEC_MAPINFO_H
#define NEC_MAPINFO_H

// Dependencies

#include <iostream>
#include "raw/bytestring.h"
#include "mapname.h"
#include "coordinates.h"

namespace Nec {

// Class

struct MapInfo {

    static const std::size_t SIZE = 0x40;

    MapInfo ();

    std::istream&     read         (std::istream&);
    std::ostream&     write        (std::ostream&)     const;

    Byte        mapNumber;
    Byte        unknown1;
    Byte        quadrantsX;
    Byte        quadrantsY;
    ByteString  playerRole;   // size  4
    ByteString  playerStance; // size 16
    ByteString  bgFiles;      // size  5
    ByteString  unknown2;     // size  3

    MapName     mapName;      // size  6
    Coordinates playerHQs[4]; // size  8
    ByteString  unknown3;     // size 10
    ByteString  addressMap;   // size  4
    ByteString  addressUnit;  // size  4

};

//

}

#endif // NEC_MAPINFO_H
