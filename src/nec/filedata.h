#ifndef NEC_FILEDATA_H
#define NEC_FILEDATA_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "biginfo.h"
#include "bigmap.h"

namespace Nec {

class FileData {
public:
                                FileData();
                                ~FileData();

    void                        read(const std::string&);
    void                        write(const std::string&);

    BigInfo*                    bigInfo;
    // BigUnit*                    bigUnit;
    BigMap*                     bigMap;

private:
    static const std::string    bigInfoFilename;
    static const std::string    bigUnitFilename;
    static const std::string    bigMapFilename;
};

} // namespace Nec

#endif // NEC_FILEDATA_H
