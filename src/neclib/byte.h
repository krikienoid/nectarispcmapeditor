#ifndef IMP_BYTE_H
#define IMP_BYTE_H

// Dependencies

#include <iostream>
#include <cstddef>
#include <string>

namespace Nec {

// Class

class Byte {

public:

    const static unsigned char MAX  = 255;
    const static std::size_t   SIZE = 256;
    const static std::size_t   BITS = 8;

    Byte ()                       : data(0)       {}
    Byte (const int n)            : data(n % MAX) {}
    Byte (const unsigned char uc) : data(uc)      {}
    Byte (const bool [BITS]);

    operator int () const;

    bool          operator==   (const Byte)    const;
    bool          operator!=   (const Byte)    const;
    bool          operator<=   (const Byte)    const;
    bool          operator>=   (const Byte)    const;
    bool          operator<    (const Byte)    const;
    bool          operator>    (const Byte)    const;

    std::istream& read         (std::istream&);
    std::ostream& write        (std::ostream&) const;

    std::string   toStringHex  ()              const;
    std::string   toStringDec  ()              const;
    std::string   toStringBin  ()              const;

private:

    unsigned char data;

};

//

}

#endif // IMP_BYTE_H
