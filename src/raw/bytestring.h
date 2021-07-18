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
    explicit                    ByteString(std::size_t);
    explicit                    ByteString(Byte);
                                ByteString(const ByteString&);
                                ~ByteString();

    ByteString&                 operator=(ByteString);
    Byte                        operator[](std::size_t) const;
    Byte&                       operator[](std::size_t);
    ByteString                  operator+(const ByteString&) const;

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    std::istream&               readLittle(std::istream&);
    std::ostream&               writeLittle(std::ostream&) const;
    std::istream&               readBig(std::istream&);
    std::ostream&               writeBig(std::ostream&) const;

    std::size_t                 size() const;
    void                        push(Byte);
    ByteString                  substr(std::size_t, std::size_t) const;
    ByteString                  substr(std::size_t) const;
    void                        insertSubstr(
                                    std::size_t,
                                    std::size_t,
                                    const ByteString&
                                );
    void                        resize(std::size_t);
    std::string                 toString() const;
    int                         toInt() const;

    static ByteString           fromInt(int);

private:
    void                        swap(ByteString&);

    std::size_t                 length;
    Byte*                       data;
};

ByteString                      operator+(Byte, const ByteString&);

} // namespace Raw

#endif // RAW_BYTESTRING_H