#ifndef RAW_BYTEARRAY_H
#define RAW_BYTEARRAY_H

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>

namespace Raw {

typedef unsigned char           Byte;

class ByteArray {
public:
    enum class                  PrintFormat { Bin, Dec, Hex };

                                ByteArray();
    explicit                    ByteArray(std::size_t);
                                ByteArray(const ByteArray&);
                                ByteArray(ByteArray&&) noexcept;
                                ~ByteArray();

    ByteArray&                  operator=(ByteArray);
    Byte                        operator[](std::size_t) const;
    Byte&                       operator[](std::size_t);
    ByteArray                   operator+(const ByteArray&) const;

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

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
    std::string                 toString(
                                    PrintFormat format = PrintFormat::Hex
                                ) const;

private:
    void                        swap(ByteArray&);

    static std::string          byteToStringBin(Byte);
    static std::string          byteToStringDec(Byte);
    static std::string          byteToStringHex(Byte);

    std::size_t                 length;
    Byte*                       data;
};

ByteArray                       operator+(Byte, const ByteArray&);

} // namespace Raw

#endif // RAW_BYTEARRAY_H
