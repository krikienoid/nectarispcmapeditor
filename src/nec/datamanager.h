#ifndef NEC_DATAMANAGER_H
#define NEC_DATAMANAGER_H

// Dependencies

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "biginfo.h"
#include "bigmap.h"

namespace Nec {

// Class

class DataManager {

public:

    DataManager  ();
    ~DataManager ();

    // Methods
    void           read          (const std::string&);
    void           write         (const std::string&);

    // Data
    BigInfo * bigInfo;
    //BigUnit * bigUnit;
    BigMap  * bigMap;

private:

    // Static consts
    static const std::string             FILENAME_BIGINFO;
    static const std::string             FILENAME_BIGUNIT;
    static const std::string             FILENAME_BIGMAP;
    static const std::ios_base::openmode FILEREADMODE;
    static const std::ios_base::openmode FILEWRITEMODE;

};

//

}

#endif // NEC_DATAMANAGER_H
