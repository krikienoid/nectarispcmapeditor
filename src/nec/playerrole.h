#ifndef NEC_PLAYERROLE_H
#define NEC_PLAYERROLE_H

#include <string>
#include <vector>

#include "raw/byte.h"

namespace Nec {

class PlayerRole {
private:
    Raw::Byte                   data;
    int                         index;

    struct PlayerRoleType {
                                PlayerRoleType(
                                    const Raw::Byte& value,
                                    const std::string& name
                                ) : value(value), name(name) {}

        Raw::Byte               value;
        std::string             name;
    };

public:
    static std::vector<PlayerRoleType> DATA;

                                PlayerRole() : data(0), index(0) {}
                                PlayerRole(const int i) {
                                    if (i >= int(DATA.size())) {
                                        index = DATA.size() - 1;
                                    } else {
                                        index = i;
                                    }

                                    data = DATA.at(index).value;
                                }

    Raw::Byte                   toByte() const { return data; }
    int                         getIndex() const { return index; }

    static std::vector<PlayerRoleType> initData();
};

} // namespace Nec

#endif // NEC_PLAYERROLE_H
