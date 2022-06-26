#include "levelinfo.h"

namespace Nec {

LevelInfo::LevelInfo() {
    push(&levelNumber);
    push(&unknown1);
    push(&chunkCountX);
    push(&chunkCountY);

    for (auto& item : playerRole) {
        push(&item);
    }

    for (auto& item : playerAttitude) {
        push(&item);
    }

    for (auto& item : activeTilesets) {
        push(&item);
    }

    unknown2 = Raw::DataElement(3);

    push(&unknown2);
    push(&levelName);

    for (auto& item : playerHQs) {
        push(&item);
    }

    unknown3 = Raw::DataElement(10);

    push(&unknown3);
    push(&levelMapAddress);
    push(&levelUnitAddress);
}

} // namespace Nec
