#include "bytearray.h"

namespace Raw {

// Public

ByteArray::ByteArray() :
    length(0),
    data(nullptr)
{}

ByteArray::ByteArray(const std::size_t n) :
    length(n),
    data(new Byte[length])
{}

ByteArray::ByteArray(const ByteArray& byteArray) :
    length(byteArray.length),
    data(new Byte[length])
{
    for (std::size_t i = 0; i < length; ++i) {
        data[i] = byteArray.data[i];
    }
}

ByteArray::ByteArray(ByteArray&& tmp) noexcept :
    length(tmp.length),
    data(tmp.data)
{
    tmp.length = 0;
    tmp.data   = nullptr;
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
    char c;

    for (std::size_t i = 0; i < length; ++i) {
        ins.get(c);

        data[i] = static_cast<Byte>(c);
    }

    return ins;
}

std::ostream& ByteArray::write(std::ostream& outs) const {
    for (std::size_t i = 0; i < length; ++i) {
        outs.put(static_cast<char>(data[i]));
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

std::string ByteArray::toString(const PrintFormat format) const {
    std::string result;

    switch (format) {
        case PrintFormat::Bin:
            for (std::size_t i = 0; i < length; ++i) {
                result += byteToStringBin(data[i]);
            }

            break;

        case PrintFormat::Dec:
            for (std::size_t i = 0; i < length; ++i) {
                result += byteToStringDec(data[i]);
            }

            break;

        case PrintFormat::Hex:
        default:
            for (std::size_t i = 0; i < length; ++i) {
                result += byteToStringHex(data[i]);
            }

            break;
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

std::string ByteArray::byteToStringBin(const Byte b) {
    std::string result(8, '0');
    Byte marker = 1;

    for (std::size_t i = 8; i; marker <<= 1) {
        result[--i] = (b & marker) ? '1' : '0';
    }

    return result;
}

std::string ByteArray::byteToStringDec(const Byte b) {
    char buffer[4];

    std::sprintf(buffer, "%d", b);

    std::string result(buffer);

    while (result.size() < 3) {
        result = '0' + result;
    }

    return result;
}

std::string ByteArray::byteToStringHex(const Byte b) {
    char buffer[3];

    std::sprintf(buffer, "%x", b);

    std::string result(buffer);

    if (result.size() < 2) {
        result = '0' + result;
    }

    return result;
}

// Helpers

ByteArray operator+(const Byte b, const ByteArray& byteArray) {
    ByteArray ba(1);

    ba[0] = b;

    return ba + byteArray;
}

} // namespace Raw
