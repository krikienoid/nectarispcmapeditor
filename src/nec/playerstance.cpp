#include "playerstance.h"

namespace Nec {

PlayerStance::PlayerStance(const int i) {
    if (i >= int(DATA.size())) {
        index = DATA.size() - 1;
    } else {
        index = i;
    }

    data = DATA.at(index).value;
}

Raw::Byte PlayerStance::toByte() const {
    return data;
}

int PlayerStance::getIndex() const {
    return index;
}

std::vector<PlayerStance::PlayerStanceType> PlayerStance::initData() {
    std::vector<PlayerStanceType> result;

    result.push_back(PlayerStanceType(0x00, "Enemy"));
    result.push_back(PlayerStanceType(0x01, "Dislike"));
    result.push_back(PlayerStanceType(0x02, "Neutral"));
    result.push_back(PlayerStanceType(0x03, "Like"));
    result.push_back(PlayerStanceType(0x04, "Ally"));
    result.push_back(PlayerStanceType(0xff, " - - "));

    return result;
}

std::vector<PlayerStance::PlayerStanceType> PlayerStance::DATA =
    PlayerStance::initData();

} // namespace Nec
