#include "levelmap.h"

namespace Nec {

LevelMap::LevelMap() : cX(0), cY(0) {}

LevelMap::LevelMap(const std::size_t cX, const std::size_t cY) :
    cX(cX),
    cY(cY)
{
    items.resize(MapSize::maxSize, Raw::ByteArray(2));
}

std::istream& LevelMap::read(std::istream& ins) {
    constexpr std::size_t maxWidth  = MapSize::getWidth(4);
    const std::size_t width         = MapSize::getWidth(cX + 1);
    const std::size_t height        = MapSize::getHeight(cY + 1);

    for (std::size_t i = 0, ii = items.size(); i < ii; ++i) {
        const auto x = i % maxWidth;
        const auto y = i / maxWidth;

        if (x < width && y < height) {
            items[i].readLittle(ins);
        }
    }

    return ins;
}

std::ostream& LevelMap::write(std::ostream& outs) const {
    constexpr std::size_t maxWidth  = MapSize::getWidth(4);
    const std::size_t width         = MapSize::getWidth(cX + 1);
    const std::size_t height        = MapSize::getHeight(cY + 1);

    for (std::size_t i = 0, ii = MapSize::maxSize; i < ii; ++i) {
        const auto x = i % maxWidth;
        const auto y = i / maxWidth;

        if (x < width && y < height) {
            items[i].writeLittle(outs);
        }
    }

    return outs;
}

} // namespace Nec
