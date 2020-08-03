#include "bigmap.h"

namespace Nec {

// Constructor

BigMap::BigMap (BigInfo * bigInfo) : bigInfo(bigInfo) {
    for (std::size_t i = 0; i < BigInfo::LENGTH; ++i)
        push_back(MapMap());
}

// I/O

std::istream& BigMap::read (std::istream& ins) {
    for (std::size_t i = 0; i < BigInfo::LENGTH; ++i) {
        if (bigInfo->mapInfoExists(i)) {
            at(i).qX = bigInfo->at(i).quadrantsX;
            at(i).qY = bigInfo->at(i).quadrantsY;
            at(i).resize(MapMap::getSize(4, 4));
            ins.seekg(bigInfo->at(i).addressMap.toInt());
            at(i).read(ins);
        }
    }
    return ins;
}

std::ostream& BigMap::write (std::ostream& outs) const {
    for (std::size_t i = 0, ii = bigInfo->size(); i < ii; ++i) {
        if (bigInfo->mapInfoExists(i)) {
            bigInfo->at(i).addressMap = ByteString::fromInt(outs.tellp());
            at(i).write(outs);
        }
    }
    return outs;
}

//

}
