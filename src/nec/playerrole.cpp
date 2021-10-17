#include "playerrole.h"

namespace Nec {

namespace PlayerRole {

const std::vector<PlayerRoleMeta> data = {
    {Raw::Byte(0x00), "USER"},
    {Raw::Byte(0x01), "COMP"},
    {Raw::Byte(0x02), "NORM"},
    {Raw::Byte(0x03), "CAPI"},
    {Raw::Byte(0x04), "ATCK"},
    {Raw::Byte(0x05), "KILL"},
    {Raw::Byte(0x06), "WALL"},
    {Raw::Byte(0x07), "SPEC"},
    {Raw::Byte(0x08), "AUTO"},
    {Raw::Byte(0xff), "DEAD"}
};

} // namespace PlayerRole

} // namespace Nec
