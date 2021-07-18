#include "bytestring.h"

namespace Raw {

// Public

ByteString::ByteString() {
    length = 0;
    data   = nullptr;
}

ByteString::ByteString(const std::size_t n) {
    length = n;
    data   = new Byte[length];
}

ByteString::ByteString(const Byte b) {
    length  = 1;
    data    = new Byte[length];
    data[0] = b;
}

ByteString::ByteString(const ByteString& bString) {
    length = bString.length;
    data   = new Byte[length];

    for (std::size_t i = 0; i < length; ++i) {
        data[i] = bString.data[i];
    }
}

ByteString::~ByteString() {
    delete[] data;
}

ByteString& ByteString::operator=(ByteString bString) {
    swap(bString);

    return *this;
}

Byte ByteString::operator[](const std::size_t i) const {
    return data[i];
}

Byte& ByteString::operator[](const std::size_t i) {
    return data[i];
}

ByteString ByteString::operator+(const ByteString& bString) const {
    ByteString result(length + bString.length);
    std::size_t i = 0;

    for (std::size_t j = 0; j < length; ++j, ++i) {
        result.data[i] = data[j];
    }

    for (std::size_t j = 0; j < bString.length; ++j, ++i) {
        result.data[i] = bString.data[j];
    }

    return result;
}

std::istream& ByteString::read(std::istream& ins) {
    return readLittle(ins);
}

std::ostream& ByteString::write(std::ostream& outs) const {
    return writeLittle(outs);
}

std::istream& ByteString::readLittle(std::istream& ins) {
    for (std::size_t i = 0; i < length; ++i) {
        data[i].read(ins);
    }

    return ins;
}

std::ostream& ByteString::writeLittle(std::ostream& outs) const {
    for (std::size_t i = 0; i < length; ++i) {
        data[i].write(outs);
    }

    return outs;
}

std::istream& ByteString::readBig(std::istream& ins) {
    for (std::size_t i = length; i;) {
        data[--i].read(ins);
    }

    return ins;
}

std::ostream& ByteString::writeBig(std::ostream& outs) const {
    for (std::size_t i = length; i;) {
        data[--i].write(outs);
    }

    return outs;
}

std::size_t ByteString::size() const {
    return length;
}

void ByteString::push(const Byte b) {
    ByteString result(length + 1);
    std::size_t i;

    for (i = 0; i < length; ++i) {
        result.data[i] = data[i];
    }

    result.data[i] = b;

    operator=(result);
}

ByteString ByteString::substr(
    const std::size_t start,
    const std::size_t n
) const {
    std::size_t nn = n;

    if (start >= length) {
        nn = 0;
    } else if (start + n > length) {
        nn -= (start + n) - length;
    }

    ByteString result(nn);

    for (std::size_t i = 0; start + i < length && i < result.length; ++i) {
        result.data[i] = data[start + i];
    }

    return result;
}

ByteString ByteString::substr(const std::size_t start) const {
    return substr(start, length);
}

void ByteString::insertSubstr(
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

void ByteString::resize(const std::size_t n) {
    ByteString result(n);

    for (std::size_t i = 0; i < result.length; ++i) {
        result.data[i] = operator[](i);
    }

    operator=(result);
}

std::string ByteString::toString() const {
    std::string result;

    for (std::size_t i = 0; i < length; ++i) {
        result += data[i].printString() + ' ';
    }

    return result;
}

int ByteString::toInt() const {
    int result = 0;

    for (std::size_t i = 0; i < length; ++i) {
        result |= static_cast<int>(data[i].value()) << static_cast<int>(8 * i);
    }

    return result;
}

ByteString ByteString::fromInt(int n) {
    ByteString result(sizeof(n));

    for (std::size_t i = result.length; i; --i, n >>= 8) {
        result.data[result.length - i] = Byte(n & 0xff);
    }

    return result;
}

// Private

void ByteString::swap(ByteString& bString) {
    std::size_t tmpSize = length;
    Byte*       tmpData = data;
    length = bString.length;
    data   = bString.data;
    bString.length = tmpSize;
    bString.data   = tmpData;
}

// Helpers

ByteString operator+(const Byte b, const ByteString& bString) {
    return ByteString(b) + bString;
}

} // namespace Raw
