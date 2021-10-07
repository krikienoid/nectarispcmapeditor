#include "levelunit.h"

namespace Nec {

LevelUnit::LevelUnit() {
}

std::istream& LevelUnit::read(std::istream& ins) {
    /*constexpr std::size_t maxWidth  = MapSize::getWidth(4);
    const std::size_t width         = MapSize::getWidth(cX + 1);
    const std::size_t height        = MapSize::getHeight(cY + 1);

    for (std::size_t i = 0, ii = size(); i < ii; ++i) {
        const auto x = i % maxWidth;
        const auto y = i / maxWidth;

        if (x < width && y < height) {
            data[i].readLittle(ins);
        }
    }*/

    return ins;
}

std::ostream& LevelUnit::write(std::ostream& outs) const {
    return outs;
}

} // namespace Nec
