#ifndef NEC_TER_H
#define NEC_TER_H

#include <iostream>
#include <vector>

#include "raw/byte.h"

namespace Nec {

class Ter : public std::vector<Raw::Byte> {
public:
                                Ter();
    explicit                    Ter(std::istream&);

private:
    static const std::size_t    SIZE = 0x800;
};

} // namespace Nec

#endif // NEC_TER_H
