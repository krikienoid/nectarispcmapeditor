#ifndef IMP_BYTESTRING_H
#define IMP_BYTESTRING_H

// Dependencies

#include <cstddef>
#include <iostream>
#include <string>

#include "byte.h"

namespace Nec {

// Class

class ByteString {

public:

             ByteString ();
    explicit ByteString (const std::size_t);
             ByteString (const Byte);
             ByteString (const ByteString&);
            ~ByteString ();

    ByteString&   operator=    (ByteString);
    Byte          operator[]   (const std::size_t) const;
    Byte&         operator[]   (const std::size_t);
    ByteString    operator+    (const ByteString&) const;

    std::istream& read         (std::istream&);
    std::ostream& write        (std::ostream&)     const;

    std::istream& readLittle   (std::istream&);
    std::ostream& writeLittle  (std::ostream&)     const;
    std::istream& readBig      (std::istream&);
    std::ostream& writeBig     (std::ostream&)     const;

    int           size         ()                  const;
    void          push         (const Byte);
    ByteString    substr       (const std::size_t, const std::size_t) const;
    ByteString    substr       (const std::size_t)            const;
    void          insertSubstr (const std::size_t, const std::size_t, const ByteString&);
    void          resize       (const std::size_t);
    std::string   toString     ()                  const;
    int           toInt        ()                  const;

    static ByteString fromInt  (int n);

private:

    void swap (ByteString&);

    std::size_t length;
    Byte *      data;

};

// Public functions

ByteString    operator+  (const Byte, const ByteString&);

}

#endif // IMP_BYTESTRING_H
