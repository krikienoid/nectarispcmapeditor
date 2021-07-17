#include "mapmap.h"

namespace Nec {

MapMap::MapMap() {
    qX = 0;
    qY = 0;
}

MapMap::MapMap(const std::size_t qX, const std::size_t qY) : qX(qX), qY(qY) {
    resize(MapSize::MAX_SIZE);
}

std::istream& MapMap::read(std::istream& ins) {
    constexpr std::size_t maxWidth  = MapSize::getWidth(4);
    const std::size_t width         = MapSize::getWidth(qX + 1);
    const std::size_t height        = MapSize::getHeight(qY + 1);

    for (std::size_t i = 0, ii = size(); i < ii; ++i) {
        const std::size_t x = i % maxWidth;
        const std::size_t y = i / maxWidth;

        if (x < width && y < height) {
            at(i).readLittle(ins);
        }
    }

    return ins;
}

std::ostream& MapMap::write(std::ostream& outs) const {
    constexpr std::size_t maxWidth  = MapSize::getWidth(4);
    const std::size_t width         = MapSize::getWidth(qX + 1);
    const std::size_t height        = MapSize::getHeight(qY + 1);

    for (std::size_t i = 0, ii = MapSize::MAX_SIZE; i < ii; ++i) {
        const std::size_t x = i % maxWidth;
        const std::size_t y = i / maxWidth;

        if (x < width && y < height) {
            at(i).writeLittle(outs);
        }
    }

    return outs;
}

void MapMap::resize(const std::size_t n) {
    std::vector<Raw::ByteString>::resize(n, Raw::ByteString(2));
}

} // namespace Nec
