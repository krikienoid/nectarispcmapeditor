#include "levelname.h"

namespace Nec {

constexpr char LevelName::offsets[];

LevelName::LevelName() : data(length, filler) {}

LevelName::LevelName(const std::string& str) : data(str) {
    data.resize(length, filler);
}

LevelName::LevelName(const char* s) : data(s) {
    data.resize(length, filler);
}

std::istream& LevelName::read(std::istream& ins) {
    for (std::size_t i = 0; i < length; ++i) {
        char c;

        ins.get(c);

        data[i] = c - offsets[i];
    }

    return ins;
}

std::ostream& LevelName::write(std::ostream& outs) const {
    for (std::size_t i = 0; i < length; ++i) {
        outs.put(data[i] + offsets[i]);
    }

    return outs;
}

std::string LevelName::toString() const {
    return data;
}

} // namespace Nec
