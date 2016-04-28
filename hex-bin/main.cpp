#include <iostream>
#include <fstream>
#include "hexdumpclass.h"
using namespace std;

int main(int argc, char* argv[]) {
    if(argc < 1) {
        cerr << "Missing arguments. Check: " << argv[1] << endl;
        return 1;
    }
    
    ifstream inputFile;
    inputFile.open(argv[1], ifstream::binary);
    
    if(inputFile.fail()) {
        cerr << "Input file cannot be opened. Check: " << argv[1] << endl;
        return 2;
    }
    
    Hexdump lHex;
    return lHex(argv[1]) ? 0 : 2;
    
}