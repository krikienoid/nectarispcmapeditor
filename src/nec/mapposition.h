#ifndef NEC_MAPPOSITION_H
#define NEC_MAPPOSITION_H

#include "raw/datanode.h"
#include "raw/int.h"

namespace Nec {

class MapPosition : public Raw::DataNode {
public:
                                MapPosition();

    Raw::UInt8                  x;
    Raw::UInt8                  y;
};

} // namespace Nec

#endif // NEC_MAPPOSITION_H
