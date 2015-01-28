#include "necbigunit.h"

namespace Nec {

// Constructor

BigUnit::BigUnit () {
}

// I/O

std::istream& BigUnit::read  (std::istream& ins) {
    /*for (std::size_t i = 0; i < BigInfo::LENGTH; ++i) {
        if (bigInfo->mapInfoExists(i)) {
            ins.seekg(bigInfo->at(i).addressUnit.toInt());
            at(i).read(ins);
        }
    }
    */
    return ins;
}

std::ostream& BigUnit::write (std::ostream& outs) const {
    /*for (std::size_t i = 0, ii = bigInfo->size(); i < ii; ++i) {
        if (bigInfo->mapInfoExists(i)) {
            bigInfo->at(i).addressUnit = ByteString::fromInt(outs.tellp());
            at(i).write(outs);
        }
    }*/
    return outs;
}

//

}
