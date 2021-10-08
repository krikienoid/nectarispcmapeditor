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

std::vector<PlayerRole::PlayerRoleMeta> PlayerRole::initData() {
    std::vector<PlayerRoleMeta> result;

    result.push_back(PlayerRoleMeta(Raw::Byte(0x00), "USER"));
    result.push_back(PlayerRoleMeta(Raw::Byte(0x01), "COMP"));
    result.push_back(PlayerRoleMeta(Raw::Byte(0x02), "NORM"));
    result.push_back(PlayerRoleMeta(Raw::Byte(0x03), "CAPI"));
    result.push_back(PlayerRoleMeta(Raw::Byte(0x04), "ATCK"));
    result.push_back(PlayerRoleMeta(Raw::Byte(0x05), "KILL"));
    result.push_back(PlayerRoleMeta(Raw::Byte(0x06), "WALL"));
    result.push_back(PlayerRoleMeta(Raw::Byte(0x07), "SPEC"));
    result.push_back(PlayerRoleMeta(Raw::Byte(0x08), "AUTO"));
    result.push_back(PlayerRoleMeta(Raw::Byte(0xff), "DEAD"));

    return result;
}

std::vector<PlayerRole::PlayerRoleMeta> PlayerRole::DATA =
    PlayerRole::initData();

} // namespace Nec
