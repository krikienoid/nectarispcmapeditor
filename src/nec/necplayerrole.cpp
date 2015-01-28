#include "necplayerrole.h"

namespace Nec {

// Static Data

std::vector<PlayerRole::PlayerRoleType> PlayerRole::initData () {
    std::vector<PlayerRoleType> result;
    result.push_back(PlayerRoleType(0x00, "User"));
    result.push_back(PlayerRoleType(0x01, "Comp"));
    result.push_back(PlayerRoleType(0x02, "Norm"));
    result.push_back(PlayerRoleType(0x03, "Capi"));
    result.push_back(PlayerRoleType(0x04, "Atck"));
    result.push_back(PlayerRoleType(0x05, "Kill"));
    result.push_back(PlayerRoleType(0x06, "Wall"));
    result.push_back(PlayerRoleType(0x07, "Spec"));
    result.push_back(PlayerRoleType(0x08, "Auto"));
    result.push_back(PlayerRoleType(0xff, "Dead"));
    return result;
}

std::vector<PlayerRole::PlayerRoleType> PlayerRole::DATA = PlayerRole::initData();

//

}
