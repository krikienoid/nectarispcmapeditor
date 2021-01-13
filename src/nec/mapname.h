#ifndef NEC_MAPNAME_H
#define NEC_MAPNAME_H

#include <iostream>
#include <string>

namespace Nec {

class MapName : public std::string {
public:
    static const char           FILLER_CHAR = '_';
    static const std::size_t    LENGTH = 6;
    static const char           CHAR_OFFSET[LENGTH];

                                MapName();
    explicit                    MapName(const std::string&);
    explicit                    MapName(const char*);

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;
};

} // namespace Nec

#endif // NEC_MAPNAME_H
