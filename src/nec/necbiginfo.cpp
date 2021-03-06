#include "necbiginfo.h"

namespace Nec {

// Constructors

BigInfo::BigInfo () {
    for(std::size_t i = 0; i < LENGTH; ++i) {
        push_back(MapInfo());
    }
}

// Methods

bool BigInfo::mapInfoExists (const std::size_t i) const {
    return (i + 1) == std::size_t(at(i).mapNumber);
}

// I/O

std::istream& BigInfo::read (std::istream& ins) {
    for (std::size_t i = 0; i < LENGTH; ++i) {
        ins.seekg(i * MapInfo::SIZE);
        at(i).read(ins);
    }
    return ins;
}

std::ostream& BigInfo::write (std::ostream& outs) const {
    for (std::size_t i = 0; i < LENGTH; ++i) {
        outs.seekp(i * MapInfo::SIZE);
        at(i).write(outs);
    }
    return outs;
}

//

}
