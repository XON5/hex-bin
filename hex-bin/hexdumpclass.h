#pragma once
#include <fstream>
#include <string>
#include "hexblockclass.h"

class Hexdump {
private:
    Hexblock fData;
    std::ifstream fInput;
    
public:
    bool open(const std::string& aInputFileName);
    void close();
    
    /* Generates the dex dump to standard output. The method has to repeatedly
    read a Hexblock (i.e 16 bytes) and produce the corresponding hex
    dump line consint of the offset and hex dump line for the Hexblcok object
    fData. */
    void processInput();
    
    /* Make objects of the type Hexdump callable. We use objects of type Hexdump
     as finctions that take a file name as parameter and return a boolean to
     indicate success or failure of making the hex dump to standard
     output. */
    bool operator()(const std::string& aInputFileName);
    
};