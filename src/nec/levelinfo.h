#ifndef NEC_LEVELINFO_H
#define NEC_LEVELINFO_H

#include <array>
#include <iostream>

#include "raw/bytearray.h"
#include "raw/int.h"
#include "levelname.h"
#include "mapposition.h"

namespace Nec {

struct LevelInfo {
public:
    static constexpr std::size_t    playerCount = 4;
    static constexpr std::size_t    playerCountSq = playerCount * playerCount;
    static constexpr std::size_t    activeTilesetCount = 5;
    static constexpr std::size_t    size = 0x40;

                                LevelInfo();

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    Raw::UInt8                  levelNumber;
    Raw::UInt8                  unknown1;
    Raw::UInt8                  chunkCountX;
    Raw::UInt8                  chunkCountY;

    std::array<Raw::UInt8, playerCount>         playerRole;         // size:  4
    std::array<Raw::UInt8, playerCountSq>       playerAttitude;     // size: 16
    std::array<Raw::UInt8, activeTilesetCount>  activeTilesets;     // size:  5
    Raw::ByteArray                              unknown2;           // size:  3

    LevelName                                   levelName;          // size:  6
    std::array<MapPosition, playerCount>        playerHQs;          // size:  8
    Raw::ByteArray                              unknown3;           // size: 10
    Raw::UInt32                                 levelMapAddress;    // size:  4
    Raw::UInt32                                 levelUnitAddress;   // size:  4
};

} // namespace Nec

#endif // NEC_LEVELINFO_H
