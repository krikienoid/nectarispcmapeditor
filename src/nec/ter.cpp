#include "ter.h"

namespace Nec {

Ter::Ter() : data(SIZE) {}

Ter::Ter(std::istream& ins) : data(SIZE) {
    for (std::size_t i = 0; i < SIZE; ++i) {
        data[i].read(ins);
    }
}

} // namespace Nec
