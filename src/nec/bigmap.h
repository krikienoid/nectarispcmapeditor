#ifndef NEC_BIGMAP_H
#define NEC_BIGMAP_H

#include <iostream>
#include <vector>

#include "raw/bytestring.h"
#include "biginfo.h"
#include "mapmap.h"

namespace Nec {

class BigMap : public std::vector<MapMap> {
public:
    explicit                    BigMap(BigInfo*);

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

private:
    BigInfo*                    bigInfo;
};

} // namespace Nec

#endif // NEC_BIGMAP_H
