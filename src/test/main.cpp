#include <iostream>

#include "nec/levelname.h"
#include "raw/byte.h"

int main() {
    {
        std::cout << std::endl << "Byte" << std::endl << std::endl;

        Raw::Byte a(0x0f);
        Raw::Byte b(0xff);
        Raw::Byte c(0xff01);

        std::cout << "0f: " << a.printString() << ' ' <<
            a.printString(Raw::Byte::Format::Bin) << ' ' <<
            a.printString(Raw::Byte::Format::Dec) << std::endl;
        std::cout << "ff: " << b.printString() << ' ' <<
            b.printString(Raw::Byte::Format::Bin) << ' ' <<
            b.printString(Raw::Byte::Format::Dec) << std::endl;
        std::cout << "01: " << c.printString() << ' ' <<
            c.printString(Raw::Byte::Format::Bin) << ' ' <<
            c.printString(Raw::Byte::Format::Dec) << std::endl;
    }

    {
        std::cout << std::endl << "Nec::LevelName" << std::endl << std::endl;
        Nec::LevelName levelName("revolt");
        std::cout << levelName.toString() << std::endl;
    }

    return 0;
}
