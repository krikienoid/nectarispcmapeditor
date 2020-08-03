#include "mapunit.h"

namespace Nec {

// Constructors

MapUnit::MapUnit() {
}

// I/O

std::istream& MapUnit::read (std::istream& ins) {
    /*int maxWidth  = MapMap::getWidth (4);
    int width     = MapMap::getWidth (qX + 1);
    int height    = MapMap::getHeight(qY + 1);

    for (int i = 0, ii = size(); i < ii; ++i) {
        int x = i % maxWidth;
        int y = i / maxWidth;
        if (x < width && y < height)
            at(i).readLittle(ins);
    }*/

    return ins;
}

std::ostream& MapUnit::write (std::ostream& outs) const {
    return outs;
}

//

}
