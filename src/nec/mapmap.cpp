#include "mapmap.h"

namespace Nec {

const std::size_t MapMap::MAX_SIZE = MapMap::getSize(4, 4);

MapMap::MapMap() {
    qX = 0;
    qY = 0;
}

MapMap::MapMap(const std::size_t qX, const std::size_t qY) : qX(qX), qY(qY) {
    resize(getSize(4, 4));
}

std::istream& MapMap::read(std::istream& ins) {
    const int maxWidth  = MapMap::getWidth(4);
    const int width     = MapMap::getWidth(qX + 1);
    const int height    = MapMap::getHeight(qY + 1);

    for (int i = 0, ii = size(); i < ii; ++i) {
        const int x = i % maxWidth;
        const int y = i / maxWidth;

        if (x < width && y < height) {
            at(i).readLittle(ins);
        }
    }

    return ins;
}

std::ostream& MapMap::write(std::ostream& outs) const {
    const int maxWidth  = MapMap::getWidth(4);
    const int width     = MapMap::getWidth(qX + 1);
    const int height    = MapMap::getHeight(qY + 1);

    for (int i = 0, ii = MapMap::getSize(4, 4); i < ii; ++i) {
        const int x = i % maxWidth;
        const int y = i / maxWidth;

        if (x < width && y < height) {
            at(i).writeLittle(outs);
        }
    }

    return outs;
}

void MapMap::resize(const std::size_t n) {
    std::vector<Raw::ByteString>::resize(n, Raw::ByteString(2));
}

std::size_t MapMap::getWidth(const std::size_t qX) {
    return qX * QUADRANT_WIDTH + PADDING;
}

std::size_t MapMap::getHeight(const std::size_t qY) {
    return qY * QUADRANT_HEIGHT + PADDING;
}

std::size_t MapMap::getSize(const std::size_t qX, const std::size_t qY) {
    return getWidth(qX) * getHeight(qY);
}

} // namespace Nec
