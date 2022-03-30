#include "playerattitude.h"

namespace Nec {

namespace PlayerAttitude {

const std::vector<PlayerAttitudeMeta> data = {
    {Raw::UInt8(0x00), "Enemy"},
    {Raw::UInt8(0x01), "Dislike"},
    {Raw::UInt8(0x02), "Neutral"},
    {Raw::UInt8(0x03), "Like"},
    {Raw::UInt8(0x04), "Ally"},
    {Raw::UInt8(0xff), " - - "}
};

} // namespace PlayerAttitude

} // namespace Nec
