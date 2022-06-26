#ifndef NEC_LEVELMAP_H
#define NEC_LEVELMAP_H

#include <iostream>
#include <vector>

#include "raw/datanode.h"
#include "raw/int.h"
#include "mapsize.h"

namespace Nec {

class LevelMap : public Raw::AbstractDataNode {
public:
                                LevelMap();
    explicit                    LevelMap(std::size_t, std::size_t);

    std::istream&               read(std::istream&) override;
    std::ostream&               write(std::ostream&) const override;

    std::size_t                 cX;
    std::size_t                 cY;

    std::vector<Raw::UInt16>    items;
};

} // namespace Nec

#endif // NEC_LEVELMAP_H
