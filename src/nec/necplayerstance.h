#ifndef NEC_PLAYERSTANCE_H
#define NEC_PLAYERSTANCE_H

// Dependencies

#include <string>
#include <vector>
#include "bytes/byte.h"

namespace Nec {

// Class

class PlayerStance {

private:

    // Data
    Byte data;
    int  index;

    // Helper Struct
    struct PlayerStanceType {

        PlayerStanceType (const Byte& value, const std::string& name)
            : value(value), name(name)
        {}

        Byte        value;
        std::string name;

    };

public:

    // Static Data
    static std::vector<PlayerStanceType> DATA;

    // Constructors
    PlayerStance () : data(0), index(0) {}
    PlayerStance (const int i) {
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
    static std::vector<PlayerStanceType> initData ();

};

//

}

#endif // NEC_PLAYERSTANCE_H
