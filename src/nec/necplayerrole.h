#ifndef NEC_PLAYERROLE_H
#define NEC_PLAYERROLE_H

// Dependencies

#include <string>
#include <vector>
#include "bytes/byte.h"

namespace Nec {

// Class

class PlayerRole {

private:

    // Data
    Byte data;
    int  index;

    // Helper Struct
    struct PlayerRoleType {

        PlayerRoleType (const Byte& value, const std::string& name)
            : value(value), name(name)
        {}

        Byte        value;
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
    Byte toByte   () const {return data;}
    int  getIndex () const {return index;}

    // Static Data Initializer
    static std::vector<PlayerRoleType> initData ();

};

//

}

#endif // NEC_PLAYERROLE_H
