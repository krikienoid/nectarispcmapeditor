#ifndef NEC_BIGMAP_H
#define NEC_BIGMAP_H

// Dependencies

#include <iostream>
#include <vector>
#include "necmapmap.h"
#include "necbiginfo.h"

namespace Nec {

// Class

class BigMap : public std::vector<MapMap> {

public:

    explicit BigMap (BigInfo *);

    std::istream& read         (std::istream&);
    std::ostream& write        (std::ostream&)     const;

private:

    BigInfo * bigInfo;

};

//

}

#endif // NEC_BIGMAP_H
