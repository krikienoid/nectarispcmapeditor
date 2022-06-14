#ifndef NEC_BIGUNIT_H
#define NEC_BIGUNIT_H

#include <iostream>
#include <vector>

#include "raw/int.h"
#include "biginfo.h"
#include "levelunit.h"

namespace Nec {

class BigUnit {
public:
    explicit                    BigUnit();

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;
};

} // namespace Nec

#endif // NEC_BIGUNIT_H
