#include "parser.h"

#include <iostream>
#include <vector>

int run(std::istream &input, std::ostream &output) {
    size_t inputLen = 12;
    unsigned char rawInput[inputLen];
    rawInput[0] = 0x05;
    rawInput[1] = 0x3F;
    rawInput[2] = 0x80;
    rawInput[3] = 0x00;
    rawInput[4] = 0x00;
    rawInput[5] = 0x09;
    rawInput[6] = 0x01;
    rawInput[7] = 0x1C;
    rawInput[8] = 0x40;
    rawInput[9] = 0x00;
    rawInput[10] = 0x00;
    rawInput[11] = 0x00;
    Parser pniTrax(rawInput, inputLen);
    pniTrax.output_parse();
    return 0;
}

int main() {
    run(std::cin, std::cout);
}
