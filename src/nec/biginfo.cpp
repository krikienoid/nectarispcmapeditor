#include "biginfo.h"

namespace Nec {

BigInfo::BigInfo() {
    for (std::size_t i = 0; i < LENGTH; ++i) {
        items.push_back(MapInfo());
    }
}

bool BigInfo::mapInfoExists(const std::size_t i) const {
    return (i + 1) == items[i].mapNumber.value();
}

std::istream& BigInfo::read(std::istream& ins) {
    for (std::size_t i = 0; i < LENGTH; ++i) {
        ins.seekg(i * MapInfo::SIZE);
        items[i].read(ins);
    }

    return ins;
}

std::ostream& BigInfo::write(std::ostream& outs) const {
    for (std::size_t i = 0; i < LENGTH; ++i) {
        outs.seekp(i * MapInfo::SIZE);
        items[i].write(outs);
    }

    return outs;
}

} // namespace Nec
