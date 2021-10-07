#include "ter.h"

namespace Nec {

Ter::Ter() : data(size) {}

Ter::Ter(std::istream& ins) : data(size) {
    for (auto& b : data) {
        b.read(ins);
    }
}

} // namespace Nec
