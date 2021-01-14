#include "mapunit.h"

namespace Nec {

MapUnit::MapUnit() {
}

std::istream& MapUnit::read(std::istream& ins) {
    /*const int maxWidth  = MapMap::getWidth(4);
    const int width     = MapMap::getWidth(qX + 1);
    const int height    = MapMap::getHeight(qY + 1);

    for (int i = 0, ii = size(); i < ii; ++i) {
        const int x = i % maxWidth;
        const int y = i / maxWidth;

        if (x < width && y < height) {
            at(i).readLittle(ins);
        }
    }*/

    return ins;
}

std::ostream& MapUnit::write(std::ostream& outs) const {
    return outs;
}

} // namespace Nec
