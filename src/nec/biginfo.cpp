#include "biginfo.h"

namespace Nec {

BigInfo::BigInfo() {
    for (std::size_t i = 0; i < levelCount; ++i) {
        items.push_back(LevelInfo());
    }
}

bool BigInfo::levelInfoExists(const std::size_t i) const {
    return (i + 1) == items[i].levelNumber.value();
}

std::istream& BigInfo::read(std::istream& ins) {
    for (std::size_t i = 0; i < levelCount; ++i) {
        ins.seekg(i * LevelInfo::size);
        items[i].read(ins);
    }

    return ins;
}

std::ostream& BigInfo::write(std::ostream& outs) const {
    for (std::size_t i = 0; i < levelCount; ++i) {
        outs.seekp(i * LevelInfo::size);
        items[i].write(outs);
    }

    return outs;
}

} // namespace Nec
