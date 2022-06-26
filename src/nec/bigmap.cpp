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
                levelInfo.chunkCountX.getValue(),
                levelInfo.chunkCountY.getValue()
            );

            ins.seekg(levelInfo.levelMapAddress.getValue());
            levelMap.read(ins);

            items[i] = levelMap;
        }
    }

    return ins;
}

std::ostream& BigMap::write(std::ostream& outs) const {
    for (std::size_t i = 0, ii = bigInfo->items.size(); i < ii; ++i) {
        if (bigInfo->levelInfoExists(i)) {
            bigInfo->items[i].levelMapAddress.setValue(outs.tellp());
            items[i].write(outs);
        }
    }

    return outs;
}

} // namespace Nec
