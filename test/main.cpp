#include <iostream>
#include "byte.h"
#include "necmapname.h"

using namespace std;

int main()
{
    Nec::Byte b(0x0f);
    Nec::MapName mapname("revolt");
    cout << b.toStringHex() << endl;
    cout << mapname << endl;
    return 0;
}
