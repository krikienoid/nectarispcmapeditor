#include "ter.h"

namespace Nec {

Ter::Ter() : std::vector<Raw::Byte>(SIZE) {}

Ter::Ter(std::istream& ins) : std::vector<Raw::Byte>(SIZE) {
    for (std::size_t i = 0; i < SIZE; ++i) {
        at(i).read(ins);
    }
}

} // namespace Nec
