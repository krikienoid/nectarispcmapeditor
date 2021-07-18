#include "ter.h"

namespace Nec {

Ter::Ter() : data(SIZE) {}

Ter::Ter(std::istream& ins) : data(SIZE) {
    for (auto& b : data) {
        b.read(ins);
    }
}

} // namespace Nec
