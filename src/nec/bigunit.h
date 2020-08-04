#ifndef NEC_BIGUNIT_H
#define NEC_BIGUNIT_H

// Dependencies

#include <iostream>
#include <vector>

#include "raw/bytestring.h"
#include "biginfo.h"
#include "mapunit.h"

namespace Nec {

// Class

class BigUnit : public std::vector<MapUnit> {

public:

    explicit BigUnit ();

    std::istream& read         (std::istream&);
    std::ostream& write        (std::ostream&) const;

};

//

}

#endif // NEC_BIGUNIT_H
