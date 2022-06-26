#ifndef NEC_BIGMAP_H
#define NEC_BIGMAP_H

#include <iostream>
#include <vector>

#include "biginfo.h"
#include "levelmap.h"
#include "mapsize.h"

namespace Nec {

class BigMap {
public:
    explicit                    BigMap(BigInfo*);

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    std::vector<LevelMap>       items;

private:
    BigInfo*                    bigInfo;
};

} // namespace Nec

#endif // NEC_BIGMAP_H
