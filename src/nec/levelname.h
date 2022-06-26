#ifndef NEC_LEVELNAME_H
#define NEC_LEVELNAME_H

#include <iostream>
#include <string>

#include "datanode.h"

namespace Nec {

class LevelName : public Raw::AbstractDataNode {
public:
    static constexpr std::size_t    length = 6;

                                LevelName();
    explicit                    LevelName(const std::string&);
    explicit                    LevelName(const char*);

    std::istream&               read(std::istream&) override;
    std::ostream&               write(std::ostream&) const override;

    std::string                 getValue() const;
    void                        setValue(const std::string&);
    void                        setValue(const char*);

private:
    static constexpr char       filler = '_';
    static constexpr char       offsets[] = {72, -33, 88, 62, -22, 92};

    std::string                 data;
};

} // namespace Nec

#endif // NEC_LEVELNAME_H
