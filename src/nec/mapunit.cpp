#include "mapunit.h"

namespace Nec {

MapUnit::MapUnit() {
}

std::istream& MapUnit::read(std::istream& ins) {
    /*constexpr std::size_t maxWidth  = MapSize::getWidth(4);
    const std::size_t width         = MapSize::getWidth(qX + 1);
    const std::size_t height        = MapSize::getHeight(qY + 1);

    for (std::size_t i = 0, ii = size(); i < ii; ++i) {
        const std::size_t x = i % maxWidth;
        const std::size_t y = i / maxWidth;

        if (x < width && y < height) {
            data[i].readLittle(ins);
        }
    }*/

    return ins;
}

std::ostream& MapUnit::write(std::ostream& outs) const {
    return outs;
}

} // namespace Nec
