#pragma once
#include <istream>
#include <ostream>

class Hexblock {
private:
    unsigned char fBuffer[16];
    unsigned long fSize;
    
public:
    Hexblock();
    std::istream& read(std::istream& aIStream);
    unsigned long size() const;
    friend std::ostream& operator<<(std::ostream& aOStream, const Hexblock& aHexblock);
};