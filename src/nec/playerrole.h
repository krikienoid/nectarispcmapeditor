#ifndef NEC_PLAYERROLE_H
#define NEC_PLAYERROLE_H

#include <string>
#include <vector>

#include "raw/byte.h"

namespace Nec {

namespace PlayerRole {

struct PlayerRoleMeta {
    const Raw::Byte             value;
    const std::string           name;
};

extern const std::vector<PlayerRoleMeta> data;

} // namespace PlayerRole

} // namespace Nec

#endif // NEC_PLAYERROLE_H
