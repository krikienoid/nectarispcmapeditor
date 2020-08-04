#ifndef RAW_BYTE_H
#define RAW_BYTE_H

// Dependencies

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>

namespace Raw {

// Class

class Byte {

public:

    enum Print {BIN, DEC, HEX};
    const static unsigned char MAX  = 255;
    const static std::size_t   SIZE = 256;
    const static std::size_t   BITS = 8;

    Byte ()                       : data(0)  {}
    Byte (const int n)            : data(n)  {}
    Byte (const unsigned char uc) : data(uc) {}
    Byte (const bool [BITS]);

    operator int () const;

    bool          operator==   (const Byte)    const;
    bool          operator!=   (const Byte)    const;
    bool          operator<=   (const Byte)    const;
    bool          operator>=   (const Byte)    const;
    bool          operator<    (const Byte)    const;
    bool          operator>    (const Byte)    const;
    //bool          operator[]   (const std::size_t) const;
    //bool&         operator[]   (const std::size_t);

    std::istream& read         (std::istream&);
    std::ostream& write        (std::ostream&) const;

    std::string   printString  (const Print print = HEX) const;

private:

    std::string   toStringHex  ()              const;
    std::string   toStringDec  ()              const;
    std::string   toStringBin  ()              const;

    unsigned char data;

};

//

} // namespace Raw

#endif // RAW_BYTE_H
