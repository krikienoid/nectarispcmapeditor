#include "necplayerstance.h"

namespace Nec {

// Static Data

std::vector<PlayerStance::PlayerStanceType> PlayerStance::initData () {
    std::vector<PlayerStanceType> result;
    result.push_back(PlayerStanceType(0x00, "Enemy"));
    result.push_back(PlayerStanceType(0x01, "Dislike"));
    result.push_back(PlayerStanceType(0x02, "Neutral"));
    result.push_back(PlayerStanceType(0x03, "Like"));
    result.push_back(PlayerStanceType(0x04, "Ally"));
    result.push_back(PlayerStanceType(0xff, " - - "));
    return result;
}

std::vector<PlayerStance::PlayerStanceType> PlayerStance::DATA = PlayerStance::initData();

//

}
