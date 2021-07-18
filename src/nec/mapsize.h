#ifndef NEC_MAPSIZE_H
#define NEC_MAPSIZE_H

namespace Nec {

namespace MapSize {

constexpr std::size_t           MAX_CHUNK_COUNT_X = 4;
constexpr std::size_t           MAX_CHUNK_COUNT_Y = 4;
constexpr std::size_t           CHUNK_WIDTH       = 15;
constexpr std::size_t           CHUNK_HEIGHT      = 10;
constexpr std::size_t           PADDING           = 2;

constexpr std::size_t getWidth(std::size_t cX) {
    return cX * CHUNK_WIDTH + PADDING;
}

constexpr std::size_t getHeight(std::size_t cY) {
    return cY * CHUNK_HEIGHT + PADDING;
}

constexpr std::size_t getSize(std::size_t cX, std::size_t cY) {
    return getWidth(cX) * getHeight(cY);
}

constexpr std::size_t           MAX_SIZE = getSize(
                                    MAX_CHUNK_COUNT_X,
                                    MAX_CHUNK_COUNT_Y
                                );

} // namespace MapSize

} // namespace Nec

#endif // NEC_MAPSIZE_H
