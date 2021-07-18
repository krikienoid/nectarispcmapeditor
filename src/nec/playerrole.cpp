#include "playerrole.h"

namespace Nec {

PlayerRole::PlayerRole(const std::size_t i) {
    const std::size_t max = DATA.size() - 1;

    if (i > max) {
        index = max;
    } else {
        index = i;
    }

    data = DATA[index].value;
}

Raw::Byte PlayerRole::toByte() const {
    return data;
}

std::size_t PlayerRole::getIndex() const {
    return index;
}

std::vector<PlayerRole::PlayerRoleType> PlayerRole::initData() {
    std::vector<PlayerRoleType> result;

    result.push_back(PlayerRoleType(Raw::Byte(0x00), "User"));
    result.push_back(PlayerRoleType(Raw::Byte(0x01), "Comp"));
    result.push_back(PlayerRoleType(Raw::Byte(0x02), "Norm"));
    result.push_back(PlayerRoleType(Raw::Byte(0x03), "Capi"));
    result.push_back(PlayerRoleType(Raw::Byte(0x04), "Atck"));
    result.push_back(PlayerRoleType(Raw::Byte(0x05), "Kill"));
    result.push_back(PlayerRoleType(Raw::Byte(0x06), "Wall"));
    result.push_back(PlayerRoleType(Raw::Byte(0x07), "Spec"));
    result.push_back(PlayerRoleType(Raw::Byte(0x08), "Auto"));
    result.push_back(PlayerRoleType(Raw::Byte(0xff), "Dead"));

    return result;
}

std::vector<PlayerRole::PlayerRoleType> PlayerRole::DATA =
    PlayerRole::initData();

} // namespace Nec
