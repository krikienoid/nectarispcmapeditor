#include "bytestring.h"

namespace Nec {

// Constructors

// Default Constructor
ByteString::ByteString () {
    length = 0;
    data   = 0;
}

// Explicit Size Constructor
ByteString::ByteString (const std::size_t n) {
    length = n;
    data   = new Byte [length];
}

// Byte Constructor
ByteString::ByteString (const Byte b) {
    length  = 1;
    data    = new Byte [length];
    data[0] = b;
}

// Copy Constructor
ByteString::ByteString (const ByteString& bString) {
    length = bString.length;
    data   = new Byte [length];
    for (std::size_t i = 0; i < length; ++i)
        data[i] = bString.data[i];
}

// Destructor
ByteString::~ByteString () {delete [] data;}

// Operators

ByteString& ByteString::operator= (ByteString bString) {
    swap(bString);
    return *this;
}

Byte  ByteString::operator[] (const std::size_t i) const {
    if (i < length)
        return data[i];
    else
        return Byte(0);
}

Byte& ByteString::operator[] (const std::size_t i) {
    if (i < length)
        return data[i];
    else
        return data[length - 1];
}

ByteString ByteString::operator+ (const ByteString& bString) const {
    ByteString result(length + bString.length);
    std::size_t i = 0;
    for (std::size_t j = 0; j < length; ++j, ++i)
        result.data[i] = data[j];
    for (std::size_t j = 0; j < bString.length; ++j, ++i)
        result.data[i] = bString.data[j];
    return result;
}

// I/O

std::istream& ByteString::read (std::istream& ins) {
    return readLittle(ins);
}

std::ostream& ByteString::write (std::ostream& outs) const {
    return writeLittle(outs);
}

// Binary I/O

std::istream& ByteString::readLittle   (std::istream& ins) {
    for (std::size_t i = 0; i < length; ++i)
        data[i].read(ins);
    return ins;
}

std::ostream& ByteString::writeLittle  (std::ostream& outs) const {
    for(std::size_t i = 0; i < length; ++i)
        data[i].write(outs);
    return outs;
}

std::istream& ByteString::readBig      (std::istream& ins) {
    for(std::size_t i = length; i;)
        data[--i].read(ins);
    return ins;
}

std::ostream& ByteString::writeBig     (std::ostream& outs) const {
    for(std::size_t i = length; i;)
        data[--i].write(outs);
    return outs;
}

// Public Methods

int ByteString::size() const {return length;}

void ByteString::push (const Byte b) {
    ByteString result(length + 1);
    std::size_t i;
    for (i = 0; i < length; ++i)
        result.data[i] = data[i];
    data[i] = b;
    operator=(result);
}

ByteString ByteString::substr (
    const std::size_t start,
    const std::size_t n
) const {
    std::size_t nn = n;
    if (start >= length)
        nn = 0;
    else if (start + n > length)
        nn -= (start + n) - length;
    ByteString result(nn);
    for (std::size_t i = 0; start + i < length && i < result.length; ++i)
        result.data[i] = data[start + i];
    return result;
}

ByteString ByteString::substr (const std::size_t start) const {
    return substr(start, length);
}

void ByteString::insertSubstr (
    const std::size_t start,
    const std::size_t end,
    const ByteString& bString
) {
    operator=(
        substr(0, start) +
        bString +
        substr(end)
    );
}

void ByteString::resize (const std::size_t n) {
    ByteString result(n);
    for (std::size_t i = 0; i < result.length; ++i)
        result.data[i] = operator[](i);
    operator=(result);
}

std::string ByteString::toString () const {
    std::string result;
    for(std::size_t i = 0; i < length; ++i)
        result += data[i].printString() + ' ';
    return result;
}

int ByteString::toInt () const {
    int result = 0;
    for (std::size_t i = 0; i < length; ++i)
        result |= data[i] << (8 * i);
    return result;
}

// Static Methods

// From Int
ByteString ByteString::fromInt (int n) {
    ByteString result(sizeof(int));
    for (std::size_t i = result.length; i; --i, n >>= 8)
        result.data[result.length - i] = static_cast<char>(n & 0xFF);
    return result;
}

// Private Methods

void ByteString::swap (ByteString& bString) {
    std::size_t tmpSize = length;
    Byte *      tmpData = data;
    length = bString.length;
    data   = bString.data;
    bString.length = tmpSize;
    bString.data   = tmpData;
}

// Non Class Functions

ByteString operator+ (const Byte b, const ByteString& bString) {
    return ByteString(b) + bString;
}

//

}
