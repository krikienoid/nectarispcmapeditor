#ifndef NEC_MAPPOSITION_H
#define NEC_MAPPOSITION_H

#include <iostream>

#include "raw/int.h"

namespace Nec {

struct MapPosition {
    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    Raw::UInt8                  x;
    Raw::UInt8                  y;
};

} // namespace Nec

#endif // NEC_MAPPOSITION_H
