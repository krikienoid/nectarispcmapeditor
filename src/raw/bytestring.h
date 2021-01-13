#ifndef RAW_BYTESTRING_H
#define RAW_BYTESTRING_H

#include <cstddef>
#include <iostream>
#include <string>

#include "byte.h"

namespace Raw {

class ByteString {
public:
                                ByteString();
    explicit                    ByteString(const std::size_t);
    explicit                    ByteString(const Byte);
                                ByteString(const ByteString&);
                                ~ByteString();

    ByteString&                 operator=(ByteString);
    Byte                        operator[](const std::size_t) const;
    Byte&                       operator[](const std::size_t);
    ByteString                  operator+(const ByteString&) const;

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    std::istream&               readLittle(std::istream&);
    std::ostream&               writeLittle(std::ostream&) const;
    std::istream&               readBig(std::istream&);
    std::ostream&               writeBig(std::ostream&) const;

    int                         size() const;
    void                        push(const Byte);
    ByteString                  substr(const std::size_t, const std::size_t) const;
    ByteString                  substr(const std::size_t) const;
    void                        insertSubstr(const std::size_t, const std::size_t, const ByteString&);
    void                        resize(const std::size_t);
    std::string                 toString() const;
    int                         toInt() const;

    static ByteString           fromInt(int);

private:
    void                        swap(ByteString&);

    std::size_t                 length;
    Byte*                       data;
};

ByteString                      operator+(const Byte, const ByteString&);

} // namespace Raw

#endif // RAW_BYTESTRING_H
