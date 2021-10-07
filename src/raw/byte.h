#ifndef RAW_BYTE_H
#define RAW_BYTE_H

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>

namespace Raw {

class Byte {
public:
    enum class                  Format { Bin, Dec, Hex };

    static constexpr unsigned char  max  = 255;
    static constexpr std::size_t    size = 256;
    static constexpr std::size_t    bitCount = 8;

                                Byte() : data(0) {}
    explicit                    Byte(const unsigned char uc) : data(uc) {}
    explicit                    Byte(const int n) :
                                    data(static_cast<unsigned char>(n)) {}
    explicit                    Byte(const bool[bitCount]);

    bool                        operator==(Byte) const;
    bool                        operator!=(Byte) const;
    bool                        operator<=(Byte) const;
    bool                        operator>=(Byte) const;
    bool                        operator<(Byte) const;
    bool                        operator>(Byte) const;
    // bool                        operator[](std::size_t) const;
    // bool&                       operator[](std::size_t);

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    unsigned char               value() const;

    std::string                 printString(Format format = Format::Hex) const;

private:
    std::string                 toStringHex() const;
    std::string                 toStringDec() const;
    std::string                 toStringBin() const;

    unsigned char               data;
};

} // namespace Raw

#endif // RAW_BYTE_H
