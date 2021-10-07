#ifndef NEC_PLAYERROLE_H
#define NEC_PLAYERROLE_H

#include <string>
#include <vector>

#include "raw/byte.h"

namespace Nec {

class PlayerRole {
    struct PlayerRoleMeta {
                                PlayerRoleMeta(
                                    const Raw::Byte value,
                                    const std::string& name
                                ) : value(value), name(name) {}

        Raw::Byte               value;
        std::string             name;
    };

public:
    static std::vector<PlayerRoleMeta> DATA;

                                PlayerRole() : data(0), index(0) {}
    explicit                    PlayerRole(std::size_t);

    Raw::Byte                   toByte() const;
    std::size_t                 getIndex() const;

    static std::vector<PlayerRoleMeta> initData();

private:
    Raw::Byte                   data;
    std::size_t                 index;
};

} // namespace Nec

#endif // NEC_PLAYERROLE_H
