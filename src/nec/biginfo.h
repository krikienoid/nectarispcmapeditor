#ifndef NEC_BIGINFO_H
#define NEC_BIGINFO_H

#include <iostream>
#include <vector>

#include "levelinfo.h"

namespace Nec {

class BigInfo {
public:
    static constexpr std::size_t    levelCount = 0x100;
    static constexpr std::size_t    size = LevelInfo::size * levelCount;

                                BigInfo();

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    bool                        levelInfoExists(std::size_t) const;

    std::vector<LevelInfo>      items;
};

} // namespace Nec

#endif // NEC_BIGINFO_H
