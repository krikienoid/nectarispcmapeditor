#ifndef NEC_PLAYERROLE_H
#define NEC_PLAYERROLE_H

// Dependencies

#include <string>
#include <vector>

#include "raw/byte.h"

namespace Nec {

// Class

class PlayerRole {

private:

    // Data
    Raw::Byte data;
    int  index;

    // Helper Struct
    struct PlayerRoleType {

        PlayerRoleType (const Raw::Byte& value, const std::string& name)
            : value(value), name(name)
        {}

        Raw::Byte   value;
        std::string name;

    };

public:

    // Static Data
    static std::vector<PlayerRoleType> DATA;

    // Constructors
    PlayerRole () : data(0), index(0) {}
    PlayerRole (const int i) {
        if (i >= int(DATA.size()))
            index = DATA.size() - 1;
        else
            index = i;
        data = DATA.at(index).value;
    }

    // Methods
    Raw::Byte toByte () const {return data;}
    int  getIndex () const {return index;}

    // Static Data Initializer
    static std::vector<PlayerRoleType> initData ();

};

//

} // namespace Nec

#endif // NEC_PLAYERROLE_H
