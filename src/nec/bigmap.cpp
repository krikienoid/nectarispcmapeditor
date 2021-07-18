#include "bigmap.h"

namespace Nec {

BigMap::BigMap(BigInfo* const bigInfo) : bigInfo(bigInfo) {
    for (std::size_t i = 0; i < BigInfo::LENGTH; ++i) {
        items.push_back(MapMap());
    }
}

std::istream& BigMap::read(std::istream& ins) {
    for (std::size_t i = 0; i < BigInfo::LENGTH; ++i) {
        if (bigInfo->mapInfoExists(i)) {
            items[i].qX = bigInfo->items[i].quadrantsX.value();
            items[i].qY = bigInfo->items[i].quadrantsY.value();
            items[i].resize(MapSize::MAX_SIZE);
            ins.seekg(bigInfo->items[i].addressMap.toInt());
            items[i].read(ins);
        }
    }

    return ins;
}

std::ostream& BigMap::write(std::ostream& outs) const {
    for (std::size_t i = 0, ii = bigInfo->items.size(); i < ii; ++i) {
        if (bigInfo->mapInfoExists(i)) {
            bigInfo->items[i].addressMap = Raw::ByteString::fromInt(outs.tellp());
            items[i].write(outs);
        }
    }

    return outs;
}

} // namespace Nec
