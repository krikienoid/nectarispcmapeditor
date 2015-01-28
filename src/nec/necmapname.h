#ifndef NEC_MAPNAME_H
#define NEC_MAPNAME_H

// Dependencies

#include <iostream>
#include <string>

namespace Nec {

// Class

class MapName : public std::string {

public:

    static const char        FILLER_CHAR = '_';
    static const std::size_t LENGTH      = 6;
    static const char        CHAR_OFFSET[LENGTH];

    MapName ()                       : std::string(LENGTH, FILLER_CHAR) {}
    MapName (const std::string& str) : std::string(str)                 {resize(LENGTH, FILLER_CHAR);}
    MapName (const char * s)         : std::string(s)                   {resize(LENGTH, FILLER_CHAR);}

    std::istream& read         (std::istream&);
    std::ostream& write        (std::ostream&)     const;

};

//

}

#endif // NEC_MAPNAME_H
