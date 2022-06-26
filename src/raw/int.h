#ifndef RAW_INT_H
#define RAW_INT_H

#include <cstddef>
#include <cstdint>

#include "bytearray.h"
#include "datanode.h"

namespace Raw {

enum class                      Endian { Little, Big };

template <class T, std::size_t N, Endian E = Endian::Little>
class Int : public DataElement {
public:
    static constexpr std::size_t    bitCount = 8;

                                Int() : DataElement(N) {}

                                Int(T n) : DataElement(N) {
                                    setValue(n);
                                }

    T                           getValue() const {
                                    T result = 0;

                                    for (std::size_t i = 0; i < N; ++i) {
                                        const auto j = (E == Endian::Little)
                                            ? i
                                            : (N - 1) - i;

                                        result |=
                                            static_cast<T>(data[j]) <<
                                            static_cast<T>(bitCount * i);
                                    }

                                    return result;
                                }

    void                        setValue(T n) {
                                    for (
                                        std::size_t i = 0;
                                        i < N;
                                        ++i, n >>= bitCount
                                    ) {
                                        const auto j = (E == Endian::Little)
                                            ? i
                                            : (N - 1) - i;

                                        data[j] = static_cast<Byte>(n);
                                    }
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
};

typedef Int<std::int8_t,   1>   Int8;
typedef Int<std::int16_t,  2>   Int16;
typedef Int<std::int32_t,  4>   Int32;

typedef Int<std::uint8_t,  1>   UInt8;
typedef Int<std::uint16_t, 2>   UInt16;
typedef Int<std::uint32_t, 4>   UInt32;

} // namespace Raw

#endif // RAW_INT_H
