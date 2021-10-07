#include "playerattitude.h"

namespace Nec {

PlayerAttitude::PlayerAttitude(const std::size_t i) {
    const std::size_t max = DATA.size() - 1;

    if (i > max) {
        index = max;
    } else {
        index = i;
    }

    data = DATA[index].value;
}

Raw::Byte PlayerAttitude::toByte() const {
    return data;
}

std::size_t PlayerAttitude::getIndex() const {
    return index;
}

std::vector<PlayerAttitude::PlayerAttitudeMeta> PlayerAttitude::initData() {
    std::vector<PlayerAttitudeMeta> result;

    result.push_back(PlayerAttitudeMeta(Raw::Byte(0x00), "Enemy"));
    result.push_back(PlayerAttitudeMeta(Raw::Byte(0x01), "Dislike"));
    result.push_back(PlayerAttitudeMeta(Raw::Byte(0x02), "Neutral"));
    result.push_back(PlayerAttitudeMeta(Raw::Byte(0x03), "Like"));
    result.push_back(PlayerAttitudeMeta(Raw::Byte(0x04), "Ally"));
    result.push_back(PlayerAttitudeMeta(Raw::Byte(0xff), " - - "));

    return result;
}

std::vector<PlayerAttitude::PlayerAttitudeMeta> PlayerAttitude::DATA =
    PlayerAttitude::initData();

} // namespace Nec
