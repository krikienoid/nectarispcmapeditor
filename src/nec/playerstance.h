#ifndef NEC_PLAYERSTANCE_H
#define NEC_PLAYERSTANCE_H

#include <string>
#include <vector>

#include "raw/byte.h"

namespace Nec {

class PlayerStance {
    struct PlayerStanceType {
                                PlayerStanceType(
                                    const Raw::Byte value,
                                    const std::string& name
                                ) : value(value), name(name) {}

        Raw::Byte               value;
        std::string             name;
    };

public:
    static std::vector<PlayerStanceType> DATA;

                                PlayerStance() : data(0), index(0) {}
    explicit                    PlayerStance(const int);

    Raw::Byte                   toByte() const;
    int                         getIndex() const;

    static std::vector<PlayerStanceType> initData();

private:
    Raw::Byte                   data;
    int                         index;
};

} // namespace Nec

#endif // NEC_PLAYERSTANCE_H
