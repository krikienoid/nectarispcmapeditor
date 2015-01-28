#include "necmapinfo.h"

namespace Nec {

// Constructors

MapInfo::MapInfo () :
    playerRole   (4),
    playerStance (16),
    bgFiles      (5),
    unknown2     (3),
    unknown3     (10),
    addressMap   (4),
    addressUnit  (4)
{}

// I/O

std::istream& MapInfo::read (std::istream& ins) {
    mapNumber   .read(ins);
    unknown1    .read(ins);
    quadrantsX  .read(ins);
    quadrantsY  .read(ins);
    playerRole  .read(ins);
    playerStance.read(ins);
    bgFiles     .read(ins);
    unknown2    .read(ins);
    mapName     .read(ins);
    for (std::size_t i = 0; i < 4; ++i)
        playerHQs[i].read(ins);
    unknown3    .read(ins);
    addressMap  .readLittle(ins);
    addressUnit .readLittle(ins);
    return ins;
}

std::ostream& MapInfo::write (std::ostream& outs) const {
    mapNumber   .write(outs);
    unknown1    .write(outs);
    quadrantsX  .write(outs);
    quadrantsY  .write(outs);
    playerRole  .write(outs);
    playerStance.write(outs);
    bgFiles     .write(outs);
    unknown2    .write(outs);
    mapName     .write(outs);
    for (std::size_t i = 0; i < 4; ++i)
        playerHQs[i].write(outs);
    unknown3    .write(outs);
    addressMap  .writeLittle(outs);
    addressUnit .writeLittle(outs);
    return outs;
}

//

}
