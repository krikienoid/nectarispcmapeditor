#ifndef NEC_LEVELNAME_H
#define NEC_LEVELNAME_H

#include <iostream>
#include <string>

namespace Nec {

class LevelName {
public:
    static constexpr std::size_t    length = 6;

                                LevelName();
    explicit                    LevelName(const std::string&);
    explicit                    LevelName(const char*);

    std::istream&               read(std::istream&);
    std::ostream&               write(std::ostream&) const;

    std::string                 toString() const;

private:
    static constexpr char       filler = '_';
    static constexpr char       offsets[] = {72, -33, 88, 62, -22, 92};

    std::string                 data;
};

} // namespace Nec

#endif // NEC_LEVELNAME_H
