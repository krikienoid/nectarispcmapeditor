#ifndef NEC_COORDINATES_H
#define NEC_COORDINATES_H

#include <iostream>

#include "raw/byte.h"

namespace Nec {

struct Coordinates {
    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    Raw::Byte                   x;
    Raw::Byte                   y;
};

} // namespace Nec

#endif // NEC_COORDINATES_H
