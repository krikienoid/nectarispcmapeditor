#ifndef NEC_DATAMANAGER_H
#define NEC_DATAMANAGER_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "biginfo.h"
#include "bigmap.h"

namespace Nec {

class DataManager {
public:
                                DataManager();
                                ~DataManager();

    void                        read(const std::string&);
    void                        write(const std::string&);

    BigInfo*                    bigInfo;
    // BigUnit*                    bigUnit;
    BigMap*                     bigMap;

private:
    static const std::string    FILENAME_BIGINFO;
    static const std::string    FILENAME_BIGUNIT;
    static const std::string    FILENAME_BIGMAP;
};

} // namespace Nec

#endif // NEC_DATAMANAGER_H
