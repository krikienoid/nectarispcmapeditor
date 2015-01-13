#include "necbigunit.h"

namespace Nec {

// Constructor

BigUnit::BigUnit () {
}

// I/O

std::istream& BigUnit::read  (std::istream& ins) {
    return ins;
}

std::ostream& BigUnit::write (std::ostream& outs) const {
    return outs;
}

//

}
