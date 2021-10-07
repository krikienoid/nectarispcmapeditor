#include "mapposition.h"

namespace Nec {

std::istream& MapPosition::read(std::istream& ins) {
    x.read(ins);
    y.read(ins);

    return ins;
}

std::ostream& MapPosition::write(std::ostream& outs) const {
    x.write(outs);
    y.write(outs);

    return outs;
}

} // namespace Nec
