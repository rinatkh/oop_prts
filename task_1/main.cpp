#include "parser.h"

#include <iostream>
#include <vector>


int test_1() {
    size_t inputLen = 12;
    auto *inputArray = new unsigned char[inputLen];
    inputArray[0] = 0x05;
    inputArray[1] = 0x3F;
    inputArray[2] = 0x80;
    inputArray[3] = 0x00;
    inputArray[4] = 0x00;
    inputArray[5] = 0x09;
    inputArray[6] = 0x01;
    inputArray[7] = 0x1C;
    inputArray[8] = 0x40;
    inputArray[9] = 0x00;
    inputArray[10] = 0x00;
    inputArray[11] = 0x00;
    Parser parser(inputArray, inputLen);
    parser.output_parse();
    delete [] inputArray;
    return 0;
}

int test_2() {
    size_t inputLen = 64;
    auto *inputArray = new unsigned char[inputLen];
    inputArray[0] = 0x05;
    inputArray[1] = 0x43;
    inputArray[2] = 0x0D;
    inputArray[3] = 0x08;
    inputArray[4] = 0x3B;
    inputArray[5] = 0x18;
    inputArray[6] = 0x3F;
    inputArray[7] = 0x91;
    inputArray[8] = 0xBC;
    inputArray[9] = 0xD8;
    inputArray[10] = 0x19;
    inputArray[11] = 0x3E;
    inputArray[12] = 0xDF;
    inputArray[13] = 0x4D;
    inputArray[14] = 0xE9;
    inputArray[15] = 0x4F;
    inputArray[16] = 0x00;
    inputArray[17] = 0x08;
    inputArray[18] = 0x00;
    inputArray[19] = 0x15;
    inputArray[20] = 0xBC;
    inputArray[21] = 0xA4;
    inputArray[22] = 0x08;
    inputArray[23] = 0xC0;
    inputArray[24] = 0x16;
    inputArray[25] = 0x3B;
    inputArray[26] = 0xFB;
    inputArray[27] = 0x4D;
    inputArray[28] = 0xAB;
    inputArray[29] = 0x17;
    inputArray[30] = 0x3F;
    inputArray[31] = 0x80;
    inputArray[32] = 0xF5;
    inputArray[33] = 0x08;
    inputArray[34] = 0x1B;
    inputArray[35] = 0xC1;
    inputArray[36] = 0x6E;
    inputArray[37] = 0xA4;
    inputArray[38] = 0x37;
    inputArray[39] = 0x1C;
    inputArray[40] = 0xC1;
    inputArray[41] = 0x2D;
    inputArray[42] = 0x31;
    inputArray[43] = 0x27;
    inputArray[44] = 0x1D;
    inputArray[45] = 0x42;
    inputArray[46] = 0x51;
    inputArray[47] = 0x3D;
    inputArray[48] = 0x4F;
    inputArray[49] = 0x4A;
    inputArray[50] = 0x00;
    inputArray[51] = 0x00;
    inputArray[52] = 0x00;
    inputArray[53] = 0x00;
    inputArray[54] = 0x4B;
    inputArray[55] = 0x00;
    inputArray[56] = 0x00;
    inputArray[57] = 0x00;
    inputArray[58] = 0x00;
    inputArray[59] = 0x4C;
    inputArray[60] = 0x00;
    inputArray[61] = 0x00;
    inputArray[62] = 0x00;
    inputArray[63] = 0x00;
    Parser parser(inputArray, inputLen);
    parser.output_parse();
    delete [] inputArray;
    return 0;
}

int test_3() {
    size_t inputLen = 32;
    auto *inputArray = new unsigned char[inputLen];
    inputArray[0] = 0x05;
    inputArray[1] = 0x43;
    inputArray[2] = 0x0D;
    inputArray[3] = 0x08;
    inputArray[4] = 0x3B;
    inputArray[5] = 0x18;
    inputArray[6] = 0x3F;
    inputArray[7] = 0x91;
    inputArray[8] = 0xBC;
    inputArray[9] = 0xD8;
    inputArray[10] = 0x19;
    inputArray[11] = 0x3E;
    inputArray[12] = 0xDF;
    inputArray[13] = 0x4F;
    inputArray[14] = 0xE9;
    inputArray[15] = 0x4D;
    inputArray[16] = 0x42;
    inputArray[17] = 0x28;
    inputArray[18] = 0x69;
    inputArray[19] = 0xE2;
    inputArray[20] = 0x41;
    inputArray[21] = 0xF8;
    inputArray[22] = 0xF5;
    inputArray[23] = 0xC3;
    inputArray[24] = 0x41;
    inputArray[25] = 0xDE;
    inputArray[26] = 0xC2;
    inputArray[27] = 0x8F;
    inputArray[28] = 0x3C;
    inputArray[29] = 0x59;
    inputArray[30] = 0x4D;
    inputArray[31] = 0x0E;
    Parser parser(inputArray, inputLen);
    parser.output_parse();
    delete [] inputArray;
    return 0;
}

int main() {
    test_1();
    std::cout << "-----------------------" << std::endl;
    test_2();
    std::cout << "-----------------------" << std::endl;
    test_3();
    return 0;
}
