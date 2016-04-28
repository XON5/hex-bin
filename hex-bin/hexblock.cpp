#include "hexblockclass.h"
#include <iomanip>
#include <cctype>
using namespace std;

Hexblock::Hexblock() {
    fSize = 0;
    for(int i = 0; i < 16; i++) {
        fBuffer[i] = 0;
    }
}

std::istream& Hexblock::read(std::istream& aIStream) {
    aIStream.read((char*)fBuffer, 16);
    fSize = (unsigned long)aIStream.gcount();
    return aIStream;
}

unsigned long Hexblock::size() const {
    return fSize;
}

std::ostream& operator<<(std::ostream& aOStream, const Hexblock& aHexblock) {
    //Hex Rep
    aOStream << setw(1) << setfill('0');
    
    for(int i = 0; i < aHexblock.fSize; i++) {
        aOStream << " " << setw(2) << hex << (int)aHexblock.fBuffer[i] << uppercase << setw(1) << setfill('0');
        if(i == 7) {
            aOStream << " | ";
        }
    }
    
    aOStream << setw(2) << setfill(' ');
    
    //Graphical Rep
    for(int i = 0; i < aHexblock.fSize; i++) {
        if(!isgraph(aHexblock.fBuffer[i])) {
            aOStream << ".";
        } else {
            aOStream << (char)aHexblock.fBuffer[i];
        }
    }
    return aOStream;
}