#include <iostream>

#include "nec/mapname.h"
#include "raw/byte.h"

int main() {
    {
        std::cout << std::endl << "Byte" << std::endl << std::endl;

        Raw::Byte a(0x0f);
        Raw::Byte b(0xff);
        Raw::Byte c(0xff01);

        std::cout << "0f: " << a.printString() << ' ' <<
            a.printString(Raw::Byte::Print::BIN) << ' ' <<
            a.printString(Raw::Byte::Print::DEC) << std::endl;
        std::cout << "ff: " << b.printString() << ' ' <<
            b.printString(Raw::Byte::Print::BIN) << ' ' <<
            b.printString(Raw::Byte::Print::DEC) << std::endl;
        std::cout << "01: " << c.printString() << ' ' <<
            c.printString(Raw::Byte::Print::BIN) << ' ' <<
            c.printString(Raw::Byte::Print::DEC) << std::endl;
    }

    {
        std::cout << std::endl << "Nec::MapName" << std::endl << std::endl;
        Nec::MapName mapname("revolt");
        std::cout << mapname.toString() << std::endl;
    }

    return 0;
}
