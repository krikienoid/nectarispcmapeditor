#ifndef RAW_BYTEARRAY_H
#define RAW_BYTEARRAY_H

#include <cstddef>
#include <iostream>
#include <string>

#include "byte.h"

namespace Raw {

class ByteArray {
public:
                                ByteArray();
    explicit                    ByteArray(std::size_t);
    explicit                    ByteArray(Byte);
                                ByteArray(const ByteArray&);
                                ~ByteArray();

    ByteArray&                  operator=(ByteArray);
    Byte                        operator[](std::size_t) const;
    Byte&                       operator[](std::size_t);
    ByteArray                   operator+(const ByteArray&) const;

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    std::istream&               readLittle(std::istream&);
    std::ostream&               writeLittle(std::ostream&) const;
    std::istream&               readBig(std::istream&);
    std::ostream&               writeBig(std::ostream&) const;

    std::size_t                 size() const;
    void                        push(Byte);
    ByteArray                   substr(std::size_t, std::size_t) const;
    ByteArray                   substr(std::size_t) const;
    void                        insertSubstr(
                                    std::size_t,
                                    std::size_t,
                                    const ByteArray&
                                );
    void                        resize(std::size_t);
    std::string                 toString() const;
    int                         toInt() const;

    static ByteArray            fromInt(int);

private:
    void                        swap(ByteArray&);

    std::size_t                 length;
    Byte*                       data;
};

ByteArray                       operator+(Byte, const ByteArray&);

} // namespace Raw

#endif // RAW_BYTEARRAY_H
