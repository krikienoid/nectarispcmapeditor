#include "playerattitude.h"

namespace Nec {

namespace PlayerAttitude {

const std::vector<PlayerAttitudeMeta> data = {
    {Raw::Byte(0x00), "Enemy"},
    {Raw::Byte(0x01), "Dislike"},
    {Raw::Byte(0x02), "Neutral"},
    {Raw::Byte(0x03), "Like"},
    {Raw::Byte(0x04), "Ally"},
    {Raw::Byte(0xff), " - - "}
};

} // namespace PlayerAttitude

} // namespace Nec
