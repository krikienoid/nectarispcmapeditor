#include "bytearray.h"

namespace Raw {

// Public

ByteArray::ByteArray() {
    length = 0;
    data   = nullptr;
}

ByteArray::ByteArray(const std::size_t n) {
    length = n;
    data   = new Byte[length];
}

ByteArray::ByteArray(const Byte b) {
    length  = 1;
    data    = new Byte[length];
    data[0] = b;
}

ByteArray::ByteArray(const ByteArray& byteArray) {
    length = byteArray.length;
    data   = new Byte[length];

    for (std::size_t i = 0; i < length; ++i) {
        data[i] = byteArray.data[i];
    }
}

ByteArray::~ByteArray() {
    delete[] data;
}

ByteArray& ByteArray::operator=(ByteArray byteArray) {
    swap(byteArray);

    return *this;
}

Byte ByteArray::operator[](const std::size_t i) const {
    return data[i];
}

Byte& ByteArray::operator[](const std::size_t i) {
    return data[i];
}

ByteArray ByteArray::operator+(const ByteArray& byteArray) const {
    ByteArray result(length + byteArray.length);
    std::size_t i = 0;

    for (std::size_t j = 0; j < length; ++j, ++i) {
        result.data[i] = data[j];
    }

    for (std::size_t j = 0; j < byteArray.length; ++j, ++i) {
        result.data[i] = byteArray.data[j];
    }

    return result;
}

std::istream& ByteArray::read(std::istream& ins) {
    return readLittle(ins);
}

std::ostream& ByteArray::write(std::ostream& outs) const {
    return writeLittle(outs);
}

std::istream& ByteArray::readLittle(std::istream& ins) {
    for (std::size_t i = 0; i < length; ++i) {
        data[i].read(ins);
    }

    return ins;
}

std::ostream& ByteArray::writeLittle(std::ostream& outs) const {
    for (std::size_t i = 0; i < length; ++i) {
        data[i].write(outs);
    }

    return outs;
}

std::istream& ByteArray::readBig(std::istream& ins) {
    for (std::size_t i = length; i;) {
        data[--i].read(ins);
    }

    return ins;
}

std::ostream& ByteArray::writeBig(std::ostream& outs) const {
    for (std::size_t i = length; i;) {
        data[--i].write(outs);
    }

    return outs;
}

std::size_t ByteArray::size() const {
    return length;
}

void ByteArray::push(const Byte b) {
    ByteArray result(length + 1);
    std::size_t i;

    for (i = 0; i < length; ++i) {
        result.data[i] = data[i];
    }

    result.data[i] = b;

    operator=(result);
}

ByteArray ByteArray::substr(
    const std::size_t start,
    const std::size_t n
) const {
    std::size_t nn = n;

    if (start >= length) {
        nn = 0;
    } else if (start + n > length) {
        nn -= (start + n) - length;
    }

    ByteArray result(nn);

    for (std::size_t i = 0; start + i < length && i < result.length; ++i) {
        result.data[i] = data[start + i];
    }

    return result;
}

ByteArray ByteArray::substr(const std::size_t start) const {
    return substr(start, length);
}

void ByteArray::insertSubstr(
    const std::size_t start,
    const std::size_t end,
    const ByteArray& byteArray
) {
    operator=(
        substr(0, start) +
        byteArray +
        substr(end)
    );
}

void ByteArray::resize(const std::size_t n) {
    ByteArray result(n);

    for (std::size_t i = 0; i < result.length; ++i) {
        result.data[i] = operator[](i);
    }

    operator=(result);
}

std::string ByteArray::toString() const {
    std::string result;

    for (std::size_t i = 0; i < length; ++i) {
        result += data[i].printString() + ' ';
    }

    return result;
}

int ByteArray::toInt() const {
    int result = 0;

    for (std::size_t i = 0; i < length; ++i) {
        result |= static_cast<int>(data[i].value()) << static_cast<int>(8 * i);
    }

    return result;
}

ByteArray ByteArray::fromInt(int n) {
    ByteArray result(sizeof(n));

    for (std::size_t i = result.length; i; --i, n >>= 8) {
        result.data[result.length - i] = Byte(n & 0xff);
    }

    return result;
}

// Private

void ByteArray::swap(ByteArray& byteArray) {
    std::size_t tmpSize = length;
    Byte*       tmpData = data;
    length = byteArray.length;
    data   = byteArray.data;
    byteArray.length = tmpSize;
    byteArray.data   = tmpData;
}

// Helpers

ByteArray operator+(const Byte b, const ByteArray& byteArray) {
    return ByteArray(b) + byteArray;
}

} // namespace Raw
