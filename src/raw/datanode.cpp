#include "datanode.h"

namespace Raw {

AbstractDataNode::~AbstractDataNode() {}

DataNode::DataNode() : length(0), children(nullptr) {}

DataNode::~DataNode() {
    delete[] children;
}

std::istream& DataNode::read(std::istream& ins) {
    for (std::size_t i = 0; i < length; ++i) {
        children[i]->read(ins);
    }

    return ins;
}

std::ostream& DataNode::write(std::ostream& outs) const {
    for (std::size_t i = 0; i < length; ++i) {
        children[i]->write(outs);
    }

    return outs;
}

void DataNode::push(AbstractDataNode* const p) {
    AbstractDataNode** old = children;
    AbstractDataNode** tmp = new AbstractDataNode*[length + 1];

    for (std::size_t i = 0; i < length; ++i) {
        tmp[i] = old[i];
    }

    tmp[length] = p;

    length += 1;
    children = tmp;

    delete[] old;
}

DataElement::DataElement() {}

DataElement::DataElement(const ByteArray& ba) : data(ba) {}

DataElement::DataElement(const std::size_t n) : data(n) {}

std::istream& DataElement::read(std::istream& ins) {
    return data.read(ins);
}

std::ostream& DataElement::write(std::ostream& outs) const {
    return data.write(outs);
}

} // namespace Raw
