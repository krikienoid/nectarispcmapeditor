#include "levelinfo.h"

namespace Nec {

LevelInfo::LevelInfo() :
    unknown2(3),
    unknown3(10)
{}

std::istream& LevelInfo::read(std::istream& ins) {
    levelNumber.read(ins);
    unknown1.read(ins);
    chunkCountX.read(ins);
    chunkCountY.read(ins);

    for (auto& item : playerRole) {
        item.read(ins);
    }

    for (auto& item : playerAttitude) {
        item.read(ins);
    }

    for (auto& item : activeTilesets) {
        item.read(ins);
    }

    unknown2.read(ins);
    levelName.read(ins);

    for (auto& item : playerHQs) {
        item.read(ins);
    }

    unknown3.read(ins);
    levelMapAddress.read(ins);
    levelUnitAddress.read(ins);

    return ins;
}

std::ostream& LevelInfo::write(std::ostream& outs) const {
    levelNumber.write(outs);
    unknown1.write(outs);
    chunkCountX.write(outs);
    chunkCountY.write(outs);

    for (const auto& item : playerRole) {
        item.write(outs);
    }

    for (const auto& item : playerAttitude) {
        item.write(outs);
    }

    for (const auto& item : activeTilesets) {
        item.write(outs);
    }

    unknown2.write(outs);
    levelName.write(outs);

    for (const auto& item : playerHQs) {
        item.write(outs);
    }

    unknown3.write(outs);
    levelMapAddress.write(outs);
    levelUnitAddress.write(outs);

    return outs;
}

} // namespace Nec
