#ifndef NEC_MAPUNIT_H
#define NEC_MAPUNIT_H

#include <iostream>

namespace Nec {

class MapUnit {
public:
                                MapUnit();

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;
};

} // namespace Nec

#endif // NEC_MAPUNIT_H
