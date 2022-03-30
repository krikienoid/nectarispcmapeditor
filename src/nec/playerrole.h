#ifndef NEC_PLAYERROLE_H
#define NEC_PLAYERROLE_H

#include <string>
#include <vector>

#include "raw/int.h"

namespace Nec {

namespace PlayerRole {

struct PlayerRoleMeta {
    const Raw::UInt8            value;
    const std::string           name;
};

extern const std::vector<PlayerRoleMeta> data;

} // namespace PlayerRole

} // namespace Nec

#endif // NEC_PLAYERROLE_H
