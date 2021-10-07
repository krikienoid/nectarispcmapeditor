#include "bigunit.h"

namespace Nec {

BigUnit::BigUnit() {
}

std::istream& BigUnit::read(std::istream& ins) {
    /*for (std::size_t i = 0; i < BigInfo::LENGTH; ++i) {
        if (bigInfo->levelInfoExists(i)) {
            ins.seekg(bigInfo->items[i].levelUnitAddress.toInt());
            items[i].read(ins);
        }
    }
    */

    return ins;
}

std::ostream& BigUnit::write(std::ostream& outs) const {
    /*for (std::size_t i = 0, ii = bigInfo->items.size(); i < ii; ++i) {
        if (bigInfo->levelInfoExists(i)) {
            bigInfo->items[i].levelUnitAddress = Raw::ByteArray::fromInt(outs.tellp());
            items[i].write(outs);
        }
    }*/

    return outs;
}

} // namespace Nec
