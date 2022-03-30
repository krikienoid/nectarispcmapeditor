#include "bigmap.h"

namespace Nec {

BigMap::BigMap(BigInfo* const bigInfo) : bigInfo(bigInfo) {
    items.resize(BigInfo::levelCount);
}

std::istream& BigMap::read(std::istream& ins) {
    for (std::size_t i = 0; i < BigInfo::levelCount; ++i) {
        if (bigInfo->levelInfoExists(i)) {
            const auto& levelInfo = bigInfo->items[i];

            LevelMap levelMap(
                levelInfo.chunkCountX.value(),
                levelInfo.chunkCountY.value()
            );

            ins.seekg(levelInfo.levelMapAddress.value());
            levelMap.read(ins);

            items[i] = levelMap;
        }
    }

    return ins;
}

std::ostream& BigMap::write(std::ostream& outs) const {
    for (std::size_t i = 0, ii = bigInfo->items.size(); i < ii; ++i) {
        if (bigInfo->levelInfoExists(i)) {
            bigInfo->items[i].levelMapAddress = Raw::UInt32(outs.tellp());
            items[i].write(outs);
        }
    }

    return outs;
}

} // namespace Nec
