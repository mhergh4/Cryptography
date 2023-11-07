#include "RLE2.h"
#include <vector>

void RLE2::encode(std::string& input) const {
    std::string encoded;

    for (int i = 0; i < input.length(); i++) {
        char current = input[i];
        int count = 1;

        while (i < input.length() - 1 && input[i] == input[i + 1] && count < 255) {
            count++;
            i++;
        }

        while (count > 0) {
            int blockCount = std::min(count, 255);
            encoded += "[" + std::to_string(static_cast<int>(current)) + "," + std::to_string(blockCount-1) + "]";
            count -= blockCount;
        }
    }
    input = encoded;
}

void RLE2::decode(std::string& input) const {
    std::string decoded;
    int i = 0;

    while (i < input.length()) {
        if (input[i] == '[') {
            i++;
            std::string valueStr, countStr;

            while (i < input.length() && input[i] != ',') {
                valueStr += input[i];
                i++;
            }
            i++;
            while (i < input.length() && input[i] != ']') {
                countStr += input[i];
                i++;
            }
            i++;

            int value = std::stoi(valueStr);
            int count = std::stoi(countStr);
            count++;
            for (int j = 0; j < count; j++) {
                decoded += static_cast<char>(value);
            }
        }
        else {
            decoded += input[i];
            i++;
        }
    }

    input = decoded;
}

void RLE2::encodeDecode(std::string& input) {
    std::cout << "Original is: " << input << std::endl;
    encode(input);
    std::cout << "Encoded is: " << input << std::endl;
    decode(input);
    std::cout << "Decoded is: " << input << std::endl;
}