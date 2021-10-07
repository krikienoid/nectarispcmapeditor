#include "levelinfo.h"

namespace Nec {

LevelInfo::LevelInfo() :
    playerRole(playerCount),
    playerAttitude(playerCount * playerCount),
    unknown2(3),
    unknown3(10),
    levelMapAddress(4),
    levelUnitAddress(4)
{}

std::istream& LevelInfo::read(std::istream& ins) {
    levelNumber.read(ins);
    unknown1.read(ins);
    chunkCountX.read(ins);
    chunkCountY.read(ins);
    playerRole.read(ins);
    playerAttitude.read(ins);

    for (auto& b : activeTilesets) {
        b.read(ins);
    }

    unknown2.read(ins);
    levelName.read(ins);

    for (auto& b : playerHQs) {
        b.read(ins);
    }

    unknown3.read(ins);
    levelMapAddress.readLittle(ins);
    levelUnitAddress.readLittle(ins);

    return ins;
}

std::ostream& LevelInfo::write(std::ostream& outs) const {
    levelNumber.write(outs);
    unknown1.write(outs);
    chunkCountX.write(outs);
    chunkCountY.write(outs);
    playerRole.write(outs);
    playerAttitude.write(outs);

    for (const auto& b : activeTilesets) {
        b.write(outs);
    }

    unknown2.write(outs);
    levelName.write(outs);

    for (const auto& b : playerHQs) {
        b.write(outs);
    }

    unknown3.write(outs);
    levelMapAddress.writeLittle(outs);
    levelUnitAddress.writeLittle(outs);

    return outs;
}

} // namespace Nec
