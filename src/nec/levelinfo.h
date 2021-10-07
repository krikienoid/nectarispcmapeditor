#ifndef NEC_LEVELINFO_H
#define NEC_LEVELINFO_H

#include <iostream>

#include "raw/byte.h"
#include "raw/bytearray.h"
#include "levelname.h"
#include "mapposition.h"

namespace Nec {

struct LevelInfo {
public:
    static constexpr std::size_t    playerCount = 4;
    static constexpr std::size_t    activeTilesetCount = 5;
    static constexpr std::size_t    size = 0x40;

                                LevelInfo();

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    Raw::Byte                   levelNumber;
    Raw::Byte                   unknown1;
    Raw::Byte                   chunkCountX;
    Raw::Byte                   chunkCountY;

    Raw::ByteArray              playerRole;                         // size:  4
    Raw::ByteArray              playerAttitude;                     // size: 16
    Raw::Byte                   activeTilesets[activeTilesetCount]; // size:  5
    Raw::ByteArray              unknown2;                           // size:  3

    LevelName                   levelName;                          // size:  6
    MapPosition                 playerHQs[playerCount];             // size:  8
    Raw::ByteArray              unknown3;                           // size: 10
    Raw::ByteArray              levelMapAddress;                    // size:  4
    Raw::ByteArray              levelUnitAddress;                   // size:  4
};

} // namespace Nec

#endif // NEC_LEVELINFO_H
