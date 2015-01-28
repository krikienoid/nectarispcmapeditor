#include "neccoordinates.h"

namespace Nec {

// I/O

std::istream& Coordinates::read (std::istream& ins) {
    x.read(ins);
    y.read(ins);
    return ins;
}

std::ostream& Coordinates::write (std::ostream& outs) const {
    x.write(outs);
    y.write(outs);
    return outs;
}

//

}
