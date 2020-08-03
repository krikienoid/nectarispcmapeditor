#include "mapname.h"

namespace Nec {

// Static Constants

const char MapName::CHAR_OFFSET[MapName::LENGTH] = {72, -33, 88, 62, -22, 92};

// I/O

std::istream& MapName::read (std::istream& ins) {
    for (std::size_t i = 0; i < LENGTH; ++i) {
        char c;
        ins.get(c);
        at(i) = c - CHAR_OFFSET[i];
    }
    return ins;
}

std::ostream& MapName::write (std::ostream& outs) const {
    for (std::size_t i = 0; i < LENGTH; ++i) {
        outs.put(at(i) + CHAR_OFFSET[i]);
    }
    return outs;
}

//

}
