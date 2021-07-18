#include "mapname.h"

namespace Nec {

constexpr char MapName::CHAR_OFFSET[];

MapName::MapName() : data(LENGTH, FILLER_CHAR) {}

MapName::MapName(const std::string& str) : data(str) {
    data.resize(LENGTH, FILLER_CHAR);
}

MapName::MapName(const char* s) : data(s) {
    data.resize(LENGTH, FILLER_CHAR);
}

std::istream& MapName::read(std::istream& ins) {
    for (std::size_t i = 0; i < LENGTH; ++i) {
        char c;

        ins.get(c);

        data[i] = c - CHAR_OFFSET[i];
    }

    return ins;
}

std::ostream& MapName::write(std::ostream& outs) const {
    for (std::size_t i = 0; i < LENGTH; ++i) {
        outs.put(data[i] + CHAR_OFFSET[i]);
    }

    return outs;
}

std::string MapName::toString() const {
    return data;
}

} // namespace Nec
