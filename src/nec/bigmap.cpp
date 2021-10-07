#include "bigmap.h"

namespace Nec {

BigMap::BigMap(BigInfo* const bigInfo) : bigInfo(bigInfo) {
    for (std::size_t i = 0; i < BigInfo::levelCount; ++i) {
        items.push_back(LevelMap());
    }
}

std::istream& BigMap::read(std::istream& ins) {
    for (std::size_t i = 0; i < BigInfo::levelCount; ++i) {
        if (bigInfo->levelInfoExists(i)) {
            items[i].cX = bigInfo->items[i].chunkCountX.value();
            items[i].cY = bigInfo->items[i].chunkCountY.value();
            items[i].resize(MapSize::maxSize);
            ins.seekg(bigInfo->items[i].levelMapAddress.toInt());
            items[i].read(ins);
        }
    }

    return ins;
}

std::ostream& BigMap::write(std::ostream& outs) const {
    for (std::size_t i = 0, ii = bigInfo->items.size(); i < ii; ++i) {
        if (bigInfo->levelInfoExists(i)) {
            bigInfo->items[i].levelMapAddress = Raw::ByteArray::fromInt(outs.tellp());
            items[i].write(outs);
        }
    }

    return outs;
}

} // namespace Nec
