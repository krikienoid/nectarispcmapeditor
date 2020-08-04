#ifndef NEC_MAPUNIT_H
#define NEC_MAPUNIT_H

// Dependencies

#include <iostream>

namespace Nec {

// Class

class MapUnit {

public:

    MapUnit ();

    std::istream& read         (std::istream&);
    std::ostream& write        (std::ostream&)     const;

};

//

} // namespace Nec

#endif // NEC_MAPUNIT_H
