#ifndef NEC_TER_H
#define NEC_TER_H

#include <iostream>
#include <vector>

#include "raw/byte.h"

namespace Nec {

class Ter {
public:
                                Ter();
    explicit                    Ter(std::istream&);

private:
    static constexpr std::size_t    SIZE = 0x800;

    std::vector<Raw::Byte>      data;
};

} // namespace Nec

#endif // NEC_TER_H
