#include "levelunit.h"

namespace Nec {

LevelUnit::LevelUnit() {
}

std::istream& LevelUnit::read(std::istream& ins) {
    /*const auto width  = MapSize::getWidth(cX + 1);
    const auto height = MapSize::getHeight(cY + 1);

    for (std::size_t i = 0, ii = size(); i < ii; ++i) {
        if (MapSize::isInBounds(i, width, height)) {
            data[i].read(ins);
        }
    }*/

    return ins;
}

std::ostream& LevelUnit::write(std::ostream& outs) const {
    return outs;
}

} // namespace Nec
