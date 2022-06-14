#include <iostream>

#include "nec/levelname.h"
#include "raw/bytearray.h"
#include "raw/int.h"

int main() {
    {
        std::cout << std::endl << "Byte" << std::endl << std::endl;

        Raw::ByteArray a(Raw::Byte(0x0f));
        Raw::ByteArray b(Raw::Byte(0xff));
        Raw::ByteArray c(Raw::Byte(0xff01));
        Raw::ByteArray d = Raw::UInt16(0xff01).toByteArray();

        std::cout << "0f: " << a.toString() << ' ' <<
            a.toString(Raw::ByteArray::PrintFormat::Bin) << ' ' <<
            a.toString(Raw::ByteArray::PrintFormat::Dec) << std::endl;

        std::cout << "ff: " << b.toString() << ' ' <<
            b.toString(Raw::ByteArray::PrintFormat::Bin) << ' ' <<
            b.toString(Raw::ByteArray::PrintFormat::Dec) << std::endl;

        std::cout << "01: " << c.toString() << ' ' <<
            c.toString(Raw::ByteArray::PrintFormat::Bin) << ' ' <<
            c.toString(Raw::ByteArray::PrintFormat::Dec) << std::endl;

        std::cout << "ff01: " << d.toString() << ' ' <<
            d.toString(Raw::ByteArray::PrintFormat::Bin) << ' ' <<
            d.toString(Raw::ByteArray::PrintFormat::Dec) << std::endl;
    }

    {
        std::cout << std::endl << "Nec::LevelName" << std::endl << std::endl;
        Nec::LevelName levelName("revolt");
        std::cout << levelName.toString() << std::endl;
    }

    return 0;
}
