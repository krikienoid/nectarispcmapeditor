#ifndef NEC_TER_H
#define NEC_TER_H

// Dependencies

#include <iostream>
#include <vector>

#include "raw/byte.h"

namespace Nec {

// Class

class Ter : public std::vector<Byte> {

public:

             Ter ();
    explicit Ter (std::istream&);

private:

    static const std::size_t SIZE = 0x800;

};

//

}

#endif // NEC_TER_H
