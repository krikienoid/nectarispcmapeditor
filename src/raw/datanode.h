#ifndef RAW_DATANODE_H
#define RAW_DATANODE_H

#include <iostream>

#include "bytearray.h"

namespace Raw {

class AbstractDataNode {
public:
    virtual                     ~AbstractDataNode();

    virtual std::istream&       read(std::istream&) = 0;
    virtual std::ostream&       write(std::ostream&) const = 0;
};

class DataNode : public AbstractDataNode {
public:
                                DataNode();
                                ~DataNode() override;

    virtual std::istream&       read(std::istream&) override;
    virtual std::ostream&       write(std::ostream&) const override;

    void                        push(AbstractDataNode*);

private:
    std::size_t                 length;
    AbstractDataNode**          children;
};

class DataElement : public AbstractDataNode {
public:
                                DataElement();
                                DataElement(const ByteArray&);
                                DataElement(std::size_t);

    virtual std::istream&       read(std::istream&) override;
    virtual std::ostream&       write(std::ostream&) const override;

    ByteArray                   data;
};

} // namespace Raw

#endif // RAW_DATANODE_H
