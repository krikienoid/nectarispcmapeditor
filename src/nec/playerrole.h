#ifndef NEC_PLAYERROLE_H
#define NEC_PLAYERROLE_H

#include <string>
#include <vector>

#include "raw/byte.h"

namespace Nec {

class PlayerRole {
    struct PlayerRoleType {
                                PlayerRoleType(
                                    const Raw::Byte value,
                                    const std::string& name
                                ) : value(value), name(name) {}

        Raw::Byte               value;
        std::string             name;
    };

public:
    static std::vector<PlayerRoleType> DATA;

                                PlayerRole() : data(0), index(0) {}
    explicit                    PlayerRole(int);

    Raw::Byte                   toByte() const;
    int                         getIndex() const;

    static std::vector<PlayerRoleType> initData();

private:
    Raw::Byte                   data;
    int                         index;
};

} // namespace Nec

#endif // NEC_PLAYERROLE_H
