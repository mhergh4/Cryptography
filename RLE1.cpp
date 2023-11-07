#include "RLE1.h"

void RLE1:: encode(std::string& input) const{
    std::string encoded;
    int count = 1;

    for (int i = 0; i < input.length(); i++) {
        while (i < input.length() - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        if (count >= 2) {
            encoded += input[i];
            encoded += std::to_string(count);
            count = 1;
        }
        else {
            encoded += input[i];
        }
    }
    input = encoded;
}

void RLE1:: decode (std::string& input) const{
    std::string decoded;
    int count = 0;

    for (int i = 0; i < input.length()-1; i++) {
        while (i < input.length()-1 && isdigit(input[i+1])) {
            count = count * 10 + (input[i+1] - '0');
            i++;
        }
        if (count == 0) {
            decoded += input[i];
        }
        else {
            for (int j = 0; j < count; j++) {
                decoded += input[i - 1];
            }
        
        }

        count = 0;
    }
    input = decoded;
}

void RLE1::encodeDecode(std::string& input) {
    std::cout << "Original is: " << input << std::endl;
    encode(input);
    std::cout << "Encoded is: " <<input << std::endl;
    decode(input);
    std::cout << "Decoded is: " << input << std::endl;
}