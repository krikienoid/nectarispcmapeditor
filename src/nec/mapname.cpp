#include "mapname.h"

namespace Nec {

const char MapName::CHAR_OFFSET[MapName::LENGTH] = {72, -33, 88, 62, -22, 92};

MapName::MapName() : std::string(LENGTH, FILLER_CHAR) {}

MapName::MapName(const std::string& str) : std::string(str) {
    resize(LENGTH, FILLER_CHAR);
}

MapName::MapName(const char* s) : std::string(s) {
    resize(LENGTH, FILLER_CHAR);
}

std::istream& MapName::read(std::istream& ins) {
    for (std::size_t i = 0; i < LENGTH; ++i) {
        char c;

        ins.get(c);

        at(i) = c - CHAR_OFFSET[i];
    }

    return ins;
}

std::ostream& MapName::write(std::ostream& outs) const {
    for (std::size_t i = 0; i < LENGTH; ++i) {
        outs.put(at(i) + CHAR_OFFSET[i]);
    }

    return outs;
}

} // namespace Nec
