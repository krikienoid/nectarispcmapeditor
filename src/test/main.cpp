#include <iostream>
#include "byte.h"
#include "mapname.h"

int main () {

    {
        std::cout << std::endl << "Byte" << std::endl << std::endl;

        Nec::Byte a(0x0f);
        Nec::Byte b(0xff);
        Nec::Byte c(0xff01);

        std::cout << "0f : " << a.printString() << ' ' <<
            a.printString(Nec::Byte::BIN) << ' ' <<
            a.printString(Nec::Byte::DEC) << std::endl;
        std::cout << "ff : " << b.printString() << ' ' <<
            b.printString(Nec::Byte::BIN) << ' ' <<
            b.printString(Nec::Byte::DEC) << std::endl;
        std::cout << "01 : " << c.printString() << ' ' <<
            c.printString(Nec::Byte::BIN) << ' ' <<
            c.printString(Nec::Byte::DEC) << std::endl;
    }

    {
        std::cout << std::endl << "Nec::MapName" << std::endl << std::endl;
        Nec::MapName mapname("revolt");
        std::cout << mapname << std::endl;
    }

    return 0;
}
