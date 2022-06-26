#include "filedata.h"

namespace Nec {

const std::string               FileData::bigInfoFilename = "biginfo.bin";
const std::string               FileData::bigUnitFilename = "bigunit.bin";
const std::string               FileData::bigMapFilename  = "bigmap.bin";

FileData::FileData() {
    bigInfo = new BigInfo();
    // bigUnit = new BigUnit();
    bigMap  = new BigMap(bigInfo);
}

FileData::~FileData() {
    delete bigInfo;
    delete bigMap;
}

void FileData::read(const std::string& filepath) {
    // Assume working directory by default.
    std::string filedir  = "";
    std::string filename = filepath;

    // If directory is given...
    const auto slashPos = filepath.find_last_of("/\\");

    if (slashPos != std::string::npos) {
        filedir  = filepath.substr(0, slashPos + 1);
        filename = filepath.substr(slashPos + 1);
    }

    // Check filename.
    std::transform(
        filename.begin(),
        filename.end(),
        filename.begin(),
        ::tolower
    );

    if (
        filename == bigInfoFilename ||
        filename == bigUnitFilename ||
        filename == bigMapFilename
    ) {
        constexpr auto fileReadMode = std::ios::in | std::ios::binary;

        // Open files for reading.
        std::ifstream bigInfoBin;
        std::ifstream bigUnitBin;
        std::ifstream bigMapBin;

        bigInfoBin.open(filedir + bigInfoFilename, fileReadMode);
        bigUnitBin.open(filedir + bigUnitFilename, fileReadMode);
        bigMapBin.open(filedir + bigMapFilename, fileReadMode);

        // Read data.
        if (bigInfoBin.good() && bigUnitBin.good() && bigMapBin.good()) {
            // biginfo.bin must be read first.
            bigInfo->read(bigInfoBin);

            bigMap->read(bigMapBin);
        }

        // Close files.
        bigInfoBin.close();
        bigUnitBin.close();
        bigMapBin.close();
    }
}

void FileData::write(const std::string& filepath) const {
    // Assume working directory by default.
    std::string filedir  = "";
    std::string filename = filepath;

    // If directory is given...
    const auto slashPos = filepath.find_last_of("/\\");

    if (slashPos != std::string::npos) {
        filedir  = filepath.substr(0, slashPos + 1);
        filename = filepath.substr(slashPos + 1);
    }

    // Check filename.
    std::transform(
        filename.begin(),
        filename.end(),
        filename.begin(),
        ::tolower
    );

    if (
        filename == bigInfoFilename ||
        filename == bigUnitFilename ||
        filename == bigMapFilename
    ) {
        constexpr auto fileWriteMode = std::ios::out | std::ios::binary;

        // Open files for writing.
        std::ofstream bigInfoBin;
        std::ofstream bigUnitBin;
        std::ofstream bigMapBin;

        bigInfoBin.open(filedir + bigInfoFilename, fileWriteMode);
        // bigUnitBin.open(filedir + bigUnitFilename, fileWriteMode);
        bigMapBin.open(filedir + bigMapFilename, fileWriteMode);

        if (bigInfoBin.good() && bigUnitBin.good() && bigMapBin.good()) {
            bigMap->write(bigMapBin);

            // biginfo.bin must be written last.
            bigInfo->write(bigInfoBin);
        }

        // Close files.
        bigInfoBin.close();
        bigUnitBin.close();
        bigMapBin.close();
    }
}

} // namespace Nec
