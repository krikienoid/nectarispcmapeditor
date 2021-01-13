#include "byte.h"

namespace Raw {

Byte::Byte(const bool bits[BITS]) {
    for (std::size_t i = 0; i < BITS; ++i) {
        data += bits[i];
        data <<= 1;
    }
}

Byte::operator int() const { return int(data); }

bool Byte::operator==(const Byte b) const { return data == b.data; }
bool Byte::operator!=(const Byte b) const { return data != b.data; }
bool Byte::operator<=(const Byte b) const { return data <= b.data; }
bool Byte::operator>=(const Byte b) const { return data >= b.data; }
bool Byte::operator<(const Byte b) const { return data < b.data; }
bool Byte::operator>(const Byte b) const { return data > b.data; }

std::istream& Byte::read(std::istream& ins) {
    char c;

    ins.get(c);

    data = c;

    return ins;
}

std::ostream& Byte::write(std::ostream& outs) const {
    outs.put(data);

    return outs;
}

std::string Byte::toStringHex() const {
    char buffer[3];

    std::sprintf(buffer, "%x", data);

    std::string result(buffer);

    if (result.size() < 2) {
        result = '0' + result;
    }

    return result;
}

std::string Byte::toStringDec() const {
    char buffer[4];

    std::sprintf(buffer, "%d", data);

    std::string result(buffer);

    while (result.size() < 3) {
        result = '0' + result;
    }

    return result;
}

std::string Byte::toStringBin() const {
    std::string result(BITS, '0');
    unsigned char marker = 1;

    for (std::size_t i = BITS; i; marker <<= 1) {
        result[--i] = (data & marker) ? '1' : '0';
    }

    return result;
}

std::string Byte::printString(const Print print) const {
    std::string result;

    switch (print) {
        case DEC: result = toStringDec(); break;
        case BIN: result = toStringBin(); break;
        case HEX:
        default:  result = toStringHex(); break;
    }

    return result;
}

} // namespace Raw
