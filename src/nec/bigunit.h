#ifndef NEC_BIGUNIT_H
#define NEC_BIGUNIT_H

#include <iostream>
#include <vector>

#include "raw/bytestring.h"
#include "biginfo.h"
#include "mapunit.h"

namespace Nec {

class BigUnit : public std::vector<MapUnit> {
public:
    explicit                    BigUnit();

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;
};

} // namespace Nec

#endif // NEC_BIGUNIT_H
