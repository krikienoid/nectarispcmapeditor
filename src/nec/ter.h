#ifndef NEC_TER_H
#define NEC_TER_H

#include <iostream>
#include <vector>

#include "raw/int.h"

namespace Nec {

class Ter {
public:
                                Ter();
    explicit                    Ter(std::istream&);

private:
    static constexpr std::size_t    size = 0x800;

    std::vector<Raw::UInt8>     data;
};

} // namespace Nec

#endif // NEC_TER_H
