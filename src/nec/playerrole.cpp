#include "playerrole.h"

namespace Nec {

namespace PlayerRole {

const std::vector<PlayerRoleMeta> data = {
    {Raw::UInt8(0x00), "USER"},
    {Raw::UInt8(0x01), "COMP"},
    {Raw::UInt8(0x02), "NORM"},
    {Raw::UInt8(0x03), "CAPI"},
    {Raw::UInt8(0x04), "ATCK"},
    {Raw::UInt8(0x05), "KILL"},
    {Raw::UInt8(0x06), "WALL"},
    {Raw::UInt8(0x07), "SPEC"},
    {Raw::UInt8(0x08), "AUTO"},
    {Raw::UInt8(0xff), "DEAD"}
};

} // namespace PlayerRole

} // namespace Nec
