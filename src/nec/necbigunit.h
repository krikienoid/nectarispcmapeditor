#ifndef NEC_BIGUNIT_H
#define NEC_BIGUNIT_H

// Dependencies

#include <iostream>
#include <vector>
#include "bytes/byte.h"
#include "necmapunit.h"
#include "necbiginfo.h"

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
