#include "byte.h"

namespace Nec {

// Constructors

Byte::Byte (const bool bits[BITS]) {
    for (std::size_t i = 0; i < BITS; ++i) {
        data += bits[i];
        data <<= 1;
    }
}

// Operators

Byte::operator int() const {return int(data);}

bool Byte::operator== (const Byte b) const {return data == b.data;}
bool Byte::operator!= (const Byte b) const {return data != b.data;}
bool Byte::operator<= (const Byte b) const {return data <= b.data;}
bool Byte::operator>= (const Byte b) const {return data >= b.data;}
bool Byte::operator<  (const Byte b) const {return data <  b.data;}
bool Byte::operator>  (const Byte b) const {return data >  b.data;}

// I/O

std::istream& Byte::read (std::istream& ins) {
    char c;
    ins.get(c);
    data = c;
    return ins;
}

std::ostream& Byte::write (std::ostream& outs) const {
    outs.put(data);
    return outs;
}

// Public Methods

std::string Byte::toStringHex () const {
    char * buffer = new char [2];
    std::sprintf(buffer, "%x", data);
    std::string result(buffer);
    if (result.size() < 2)
        result = '0' + result;
    return result;
}

std::string Byte::toStringDec () const {
    char * buffer = new char [3];
    std::sprintf(buffer, "%d", data);
    std::string result(buffer);
    while (result.size() < 3)
        result = '0' + result;
    return result;
}

std::string Byte::toStringBin () const {
    char * buffer = new char [BITS];
    std::sprintf(buffer, "%b", data);
    std::string result(buffer);
    while (result.size() < BITS)
        result = '0' + result;
    return result;
}

//

}
