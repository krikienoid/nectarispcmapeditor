#ifndef NEC_MAPINFO_H
#define NEC_MAPINFO_H

#include <iostream>

#include "raw/byte.h"
#include "raw/bytestring.h"
#include "coordinates.h"
#include "mapname.h"

namespace Nec {

struct MapInfo {
public:
    static constexpr std::size_t    PLAYER_COUNT = 4;
    static constexpr std::size_t    BG_FILE_MAX = 5;
    static constexpr std::size_t    SIZE = 0x40;

                                MapInfo();

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    Raw::Byte                   mapNumber;
    Raw::Byte                   unknown1;
    Raw::Byte                   quadrantsX;
    Raw::Byte                   quadrantsY;

    Raw::ByteString             playerRole;                     // size:  4
    Raw::ByteString             playerStance;                   // size: 16
    Raw::Byte                   bgFiles[BG_FILE_MAX];           // size:  5
    Raw::ByteString             unknown2;                       // size:  3

    MapName                     mapName;                        // size:  6
    Coordinates                 playerHQs[PLAYER_COUNT];        // size:  8
    Raw::ByteString             unknown3;                       // size: 10
    Raw::ByteString             addressMap;                     // size:  4
    Raw::ByteString             addressUnit;                    // size:  4
};

} // namespace Nec

#endif // NEC_MAPINFO_H
