#ifndef NEC_MAPPOSITION_H
#define NEC_MAPPOSITION_H

#include <iostream>

#include "raw/byte.h"

namespace Nec {

struct MapPosition {
    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    Raw::Byte                   x;
    Raw::Byte                   y;
};

} // namespace Nec

#endif // NEC_MAPPOSITION_H
