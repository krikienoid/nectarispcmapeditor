#ifndef NEC_COORDINATES_H
#define NEC_COORDINATES_H

// Dependencies

#include <iostream>
#include "bytes/byte.h"

namespace Nec {

// Class

struct Coordinates {

    std::istream& read         (std::istream&);
    std::ostream& write        (std::ostream&)     const;

    Byte x;
    Byte y;

};

//

}

#endif // NEC_COORDINATES_H
