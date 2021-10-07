#ifndef NEC_LEVELUNIT_H
#define NEC_LEVELUNIT_H

#include <iostream>

namespace Nec {

class LevelUnit {
public:
                                LevelUnit();

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;
};

} // namespace Nec

#endif // NEC_LEVELUNIT_H
