#include "hexdumpclass.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool Hexdump::open(const std::string& aInputFileName) {
    fInput.open(aInputFileName, fstream::binary);
    if(fInput.good()) {
        return true;
    } else {
        return false;
    }
}

void Hexdump::close() {
    fInput.close();
}

void Hexdump::processInput() {
    cout << "Hexdump for this file successfully represented as: " << endl << endl;

    //Prints out 1 line of hex for every 16 bytes of data
    unsigned long offset = 0;
    do {
        fData.read(fInput);
        cout << setw(8) << setfill('0') << hex << offset << ": " << fData <<uppercase << endl;
        offset += 16;
    } while (fData.size() == 16);
}

bool Hexdump::operator()(const std::string& aInputFileName) {
    if(open(aInputFileName)) {
        processInput();
        return true;
    } else {
        cerr << "Input file cannot be opened." << endl;
        return false;
    }
}
