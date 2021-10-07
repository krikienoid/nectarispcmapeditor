#ifndef NEC_PLAYERATTITUDE_H
#define NEC_PLAYERATTITUDE_H

#include <string>
#include <vector>

#include "raw/byte.h"

namespace Nec {

class PlayerAttitude {
    struct PlayerAttitudeMeta {
                                PlayerAttitudeMeta(
                                    const Raw::Byte value,
                                    const std::string& name
                                ) : value(value), name(name) {}

        Raw::Byte               value;
        std::string             name;
    };

public:
    static std::vector<PlayerAttitudeMeta> DATA;

                                PlayerAttitude() : data(0), index(0) {}
    explicit                    PlayerAttitude(std::size_t);

    Raw::Byte                   toByte() const;
    std::size_t                 getIndex() const;

    static std::vector<PlayerAttitudeMeta> initData();

private:
    Raw::Byte                   data;
    std::size_t                 index;
};

} // namespace Nec

#endif // NEC_PLAYERATTITUDE_H
