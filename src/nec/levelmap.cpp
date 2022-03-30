#include "levelmap.h"

namespace Nec {

LevelMap::LevelMap() : cX(0), cY(0) {}

LevelMap::LevelMap(const std::size_t cX, const std::size_t cY) :
    cX(cX),
    cY(cY)
{
    items.resize(MapSize::maxSize);
}

std::istream& LevelMap::read(std::istream& ins) {
    const auto width  = MapSize::getWidth(cX + 1);
    const auto height = MapSize::getHeight(cY + 1);

    for (std::size_t i = 0, ii = items.size(); i < ii; ++i) {
        if (MapSize::isInBounds(i, width, height)) {
            items[i].read(ins);
        }
    }

    return ins;
}

std::ostream& LevelMap::write(std::ostream& outs) const {
    const auto width  = MapSize::getWidth(cX + 1);
    const auto height = MapSize::getHeight(cY + 1);

    for (std::size_t i = 0, ii = MapSize::maxSize; i < ii; ++i) {
        if (MapSize::isInBounds(i, width, height)) {
            items[i].write(outs);
        }
    }

    return outs;
}

} // namespace Nec
