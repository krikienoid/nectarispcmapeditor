#include "datamanager.h"

namespace Nec {

const std::string               DataManager::FILENAME_BIGINFO = "biginfo.bin";
const std::string               DataManager::FILENAME_BIGUNIT = "bigunit.bin";
const std::string               DataManager::FILENAME_BIGMAP  = "bigmap.bin";
const std::ios_base::openmode   DataManager::FILEREADMODE     = std::ios::in  | std::ios::binary;
const std::ios_base::openmode   DataManager::FILEWRITEMODE    = std::ios::out | std::ios::binary;

DataManager::DataManager() {
    bigInfo = new BigInfo();
    // bigUnit = new BigUnit();
    bigMap  = new BigMap(bigInfo);
}

DataManager::~DataManager() {
    delete bigInfo;
    delete bigMap;
}

void DataManager::read(const std::string& filepath) {
    // Assume working directory by default
    std::string filedir  = "";
    std::string filename = filepath;

    // If directory is given
    std::size_t slashPos = filepath.find_last_of("/\\");

    if (slashPos != std::string::npos) {
        filedir  = filepath.substr(0, slashPos + 1);
        filename = filepath.substr(slashPos + 1);
    }

    // Check file name
    std::transform(
        filename.begin(),
        filename.end(),
        filename.begin(),
        ::tolower
    );

    if (
        filename == FILENAME_BIGINFO ||
        filename == FILENAME_BIGUNIT ||
        filename == FILENAME_BIGMAP
    ) {
        // Open files for reading
        std::ifstream bigInfoBin;
        std::ifstream bigUnitBin;
        std::ifstream bigMapBin;

        bigInfoBin.open((filedir + FILENAME_BIGINFO).c_str(), FILEREADMODE);
        bigUnitBin.open((filedir + FILENAME_BIGUNIT).c_str(), FILEREADMODE);
        bigMapBin.open((filedir + FILENAME_BIGMAP).c_str(), FILEREADMODE);

        // Read Data
        if (bigInfoBin.good() && bigUnitBin.good() && bigMapBin.good()) {
            // biginfo.bin must be read first
            bigInfo->read(bigInfoBin);

            // bigmap.bin
            bigMap->read(bigMapBin);
        }

        // Close Files
        bigInfoBin.close();
        bigUnitBin.close();
        bigMapBin.close();
    }
}

void DataManager::write(const std::string& filepath) {
    // Assume working directory by default
    std::string filedir  = "";
    std::string filename = filepath;

    // If directory is given
    std::size_t slashPos = filepath.find_last_of("/\\");

    if (slashPos != std::string::npos) {
        filedir  = filepath.substr(0, slashPos + 1);
        filename = filepath.substr(slashPos + 1);
    }

    // Check file name
    std::transform(
        filename.begin(),
        filename.end(),
        filename.begin(),
        ::tolower
    );

    if (
        filename == FILENAME_BIGINFO ||
        filename == FILENAME_BIGUNIT ||
        filename == FILENAME_BIGMAP
    ) {
        // Open files for writing
        std::ofstream bigInfoBin;
        std::ofstream bigUnitBin;
        std::ofstream bigMapBin;

        bigInfoBin.open((filedir + FILENAME_BIGINFO).c_str(), FILEWRITEMODE);
        // bigUnitBin.open((filedir + FILENAME_BIGUNIT).c_str(), FILEWRITEMODE);
        bigMapBin.open((filedir + FILENAME_BIGMAP).c_str(), FILEWRITEMODE);

        if (bigInfoBin.good() && bigUnitBin.good() && bigMapBin.good()) {
            // bigmap.bin
            bigMap->write(bigMapBin);

            // biginfo.bin must be written last
            bigInfo->write(bigInfoBin);
        }

        // Close Files
        bigInfoBin.close();
        bigUnitBin.close();
        bigMapBin.close();
    }
}

} // namespace Nec
