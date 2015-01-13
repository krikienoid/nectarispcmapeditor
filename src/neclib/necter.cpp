#include "necter.h"

namespace Nec {

// Nec Ter

Ter::Ter () : std::vector<Byte>(SIZE) {}

Ter::Ter (std::istream& ins) : std::vector<Byte>(SIZE) {
    for (std::size_t i = 0; i < SIZE; ++i)
        at(i).read(ins);
}

//

}
