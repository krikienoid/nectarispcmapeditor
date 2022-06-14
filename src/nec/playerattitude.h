#ifndef NEC_PLAYERATTITUDE_H
#define NEC_PLAYERATTITUDE_H

#include <string>
#include <vector>

#include "raw/int.h"

namespace Nec {

namespace PlayerAttitude {

struct PlayerAttitudeMeta {
    const Raw::UInt8            value;
    const std::string           name;
};

extern const std::vector<PlayerAttitudeMeta> data;

} // namespace PlayerAttitude

} // namespace Nec

#endif // NEC_PLAYERATTITUDE_H
