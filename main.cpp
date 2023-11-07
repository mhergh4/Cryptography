#include <iostream>
#include "RLE2.h"
int main() {
    /*ParzPoxarinum pp;

    std::cout << "Alphabets are:\n" << pp.alphabet << "\n" << pp.alphabet2 << std::endl;

    std::string str;
    std::cout << "Enter the string" << std::endl;
    std::getline(std::cin, str);

    pp.encodeDecode(str);

    return 0;*/
    /*std::string key = "COLUMNROW";
    EncColumnsAndRows encryptor(key);
    std::string plaintext = "HELLOWORLD";

    encryptor.encodeDecode(plaintext);

    return 0;*/
    RLE2 rle;
    std::string input;
    std::cout << "Enter the text: ";
    std::getline(std::cin, input);
    std::cout << std::endl;
    rle.encodeDecode(input);

}