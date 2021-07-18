#ifndef NEC_MAPNAME_H
#define NEC_MAPNAME_H

#include <iostream>
#include <string>

namespace Nec {

class MapName {
public:
    static constexpr std::size_t    LENGTH = 6;
    static constexpr char           FILLER_CHAR = '_';
    static constexpr char           CHAR_OFFSET[] = {72, -33, 88, 62, -22, 92};

                                MapName();
    explicit                    MapName(const std::string&);
    explicit                    MapName(const char*);

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    std::string                 toString() const;

private:
    std::string                 data;
};

} // namespace Nec

#endif // NEC_MAPNAME_H
