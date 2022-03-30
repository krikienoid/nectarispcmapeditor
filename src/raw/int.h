#ifndef RAW_INT_H
#define RAW_INT_H

#include <cstddef>
#include <cstdint>
#include <iostream>

#include "byte.h"
#include "bytearray.h"

namespace Raw {

enum class                      Endian { Little, Big };

template <class T, std::size_t N, Endian E = Endian::Little>
class Int {
public:
    static constexpr std::size_t    bitCount = 8;

                                Int() : data(N) {}

                                Int(T n) : data(N) {
                                    for (
                                        std::size_t i = 0;
                                        i < N;
                                        ++i, n >>= bitCount
                                    ) {
                                        const auto j = (E == Endian::Little)
                                            ? i
                                            : (N - 1) - i;

                                        data[j] = Byte(static_cast<unsigned char>(n));
                                    }
                                }

    std::istream&               read(std::istream& ins) {
                                    data.read(ins);

                                    return ins;
                                }

    std::ostream&               write(std::ostream& outs) const {
                                    data.write(outs);

                                    return outs;
                                }

    T                           value() const {
                                    T result = 0;

                                    for (std::size_t i = 0; i < N; ++i) {
                                        const auto j = (E == Endian::Little)
                                            ? i
                                            : (N - 1) - i;

                                        result |=
                                            static_cast<T>(data[j].value()) <<
                                            static_cast<T>(bitCount * i);
                                    }

                                    return result;
                                }

    ByteArray                   toByteArray() {
                                    return data;
                                }

    static Int<T, N, E>         fromByteArray(const ByteArray& ba) {
                                    Int<T, N, E> result;

                                    for (
                                        std::size_t i = 0, ii = ba.size();
                                        i < N && i < ii;
                                        ++i
                                    ) {
                                        const auto j1 = (E == Endian::Little)
                                            ? i
                                            : (N - 1) - i;

                                        const auto j2 = (E == Endian::Little)
                                            ? i
                                            : (ii - 1) - i;

                                        result.data[j1] = ba[j2];
                                    }

                                    return result;
                                }

private:
    ByteArray                   data;
};

typedef Int<std::int8_t,   1>   Int8;
typedef Int<std::int16_t,  2>   Int16;
typedef Int<std::int32_t,  4>   Int32;

typedef Int<std::uint8_t,  1>   UInt8;
typedef Int<std::uint16_t, 2>   UInt16;
typedef Int<std::uint32_t, 4>   UInt32;

} // namespace Raw

#endif // RAW_INT_H
