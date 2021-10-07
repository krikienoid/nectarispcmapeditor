#ifndef NEC_MAPSIZE_H
#define NEC_MAPSIZE_H

namespace Nec {

namespace MapSize {

constexpr std::size_t           maxChunkCountX = 4;
constexpr std::size_t           maxChunkCountY = 4;
constexpr std::size_t           chunkWidth     = 15;
constexpr std::size_t           chunkHeight    = 10;
constexpr std::size_t           padding        = 2;

constexpr std::size_t getWidth(std::size_t cX) {
    return cX * chunkWidth + padding;
}

constexpr std::size_t getHeight(std::size_t cY) {
    return cY * chunkHeight + padding;
}

constexpr std::size_t getSize(std::size_t cX, std::size_t cY) {
    return getWidth(cX) * getHeight(cY);
}

constexpr std::size_t           maxSize = getSize(
                                    maxChunkCountX,
                                    maxChunkCountY
                                );

} // namespace MapSize

} // namespace Nec

#endif // NEC_MAPSIZE_H
