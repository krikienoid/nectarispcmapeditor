#include "ter.h"

namespace Nec {

Ter::Ter() : data(size) {}

Ter::Ter(std::istream& ins) : data(size) {
    for (auto& item : data) {
        item.read(ins);
    }
}

} // namespace Nec
