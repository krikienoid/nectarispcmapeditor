#include "mapinfo.h"

namespace Nec {

MapInfo::MapInfo() :
    playerRole(PLAYER_COUNT),
    playerStance(PLAYER_COUNT * PLAYER_COUNT),
    unknown2(3),
    unknown3(10),
    addressMap(4),
    addressUnit(4)
{}

std::istream& MapInfo::read(std::istream& ins) {
    mapNumber.read(ins);
    unknown1.read(ins);
    quadrantsX.read(ins);
    quadrantsY.read(ins);
    playerRole.read(ins);
    playerStance.read(ins);

    for (auto& b : bgFiles) {
        b.read(ins);
    }

    unknown2.read(ins);
    mapName.read(ins);

    for (auto& b : playerHQs) {
        b.read(ins);
    }

    unknown3.read(ins);
    addressMap.readLittle(ins);
    addressUnit.readLittle(ins);

    return ins;
}

std::ostream& MapInfo::write(std::ostream& outs) const {
    mapNumber.write(outs);
    unknown1.write(outs);
    quadrantsX.write(outs);
    quadrantsY.write(outs);
    playerRole.write(outs);
    playerStance.write(outs);

    for (const auto& b : bgFiles) {
        b.write(outs);
    }

    unknown2.write(outs);
    mapName.write(outs);

    for (const auto& b : playerHQs) {
        b.write(outs);
    }

    unknown3.write(outs);
    addressMap.writeLittle(outs);
    addressUnit.writeLittle(outs);

    return outs;
}

} // namespace Nec
