#ifndef NEC_BIGUNIT_H
#define NEC_BIGUNIT_H

// Dependencies

#include <iostream>
#include <vector>
#include "neclib/byte.h"
#include "necbiginfo.h"

namespace Nec {

// Class

class BigUnit : public std::vector<Byte> {

public:

    explicit BigUnit ();

    std::istream& read         (std::istream&);
    std::ostream& write        (std::ostream&) const;

};

//

}

#endif // NEC_BIGUNIT_H
