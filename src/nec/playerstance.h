#ifndef NEC_PLAYERSTANCE_H
#define NEC_PLAYERSTANCE_H

#include <string>
#include <vector>

#include "raw/byte.h"

namespace Nec {

class PlayerStance {
private:
    Raw::Byte                   data;
    int                         index;

    struct PlayerStanceType {
                                PlayerStanceType(
                                    const Raw::Byte& value,
                                    const std::string& name
                                ) : value(value), name(name) {}

        Raw::Byte               value;
        std::string             name;
    };

public:
    static std::vector<PlayerStanceType> DATA;

                                PlayerStance() : data(0), index(0) {}
                                PlayerStance(const int i) {
                                    if (i >= int(DATA.size())) {
                                        index = DATA.size() - 1;
                                    } else {
                                        index = i;
                                    }

                                    data = DATA.at(index).value;
                                }

    Raw::Byte                   toByte() const { return data; }
    int                         getIndex() const { return index; }

    static std::vector<PlayerStanceType> initData();
};

} // namespace Nec

#endif // NEC_PLAYERSTANCE_H
