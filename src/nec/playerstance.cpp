#include "playerstance.h"

namespace Nec {

PlayerStance::PlayerStance(const std::size_t i) {
    const std::size_t max = DATA.size() - 1;

    if (i > max) {
        index = max;
    } else {
        index = i;
    }

    data = DATA.at(index).value;
}

Raw::Byte PlayerStance::toByte() const {
    return data;
}

std::size_t PlayerStance::getIndex() const {
    return index;
}

std::vector<PlayerStance::PlayerStanceType> PlayerStance::initData() {
    std::vector<PlayerStanceType> result;

    result.push_back(PlayerStanceType(Raw::Byte(0x00), "Enemy"));
    result.push_back(PlayerStanceType(Raw::Byte(0x01), "Dislike"));
    result.push_back(PlayerStanceType(Raw::Byte(0x02), "Neutral"));
    result.push_back(PlayerStanceType(Raw::Byte(0x03), "Like"));
    result.push_back(PlayerStanceType(Raw::Byte(0x04), "Ally"));
    result.push_back(PlayerStanceType(Raw::Byte(0xff), " - - "));

    return result;
}

std::vector<PlayerStance::PlayerStanceType> PlayerStance::DATA =
    PlayerStance::initData();

} // namespace Nec
