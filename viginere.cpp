#include <iostream>
#include <cctype>
#include <string>

std::string encode(const std::string& plaintext, const std::string& key) {
    std::string encoded;
    for (int i{ 0 };i < plaintext.size();++i) {
        if (isalpha(plaintext[i])) {
            char encodedChar = 'a' + ((std::tolower(plaintext[i]) - 'a') + (std::tolower(key[i % key.size()]) - 'a')) % 26;
            if (std::isupper(plaintext[i])) {
                encodedChar = std::toupper(encodedChar);
            }

            encoded.push_back(encodedChar);
        }
        else {
            encoded.push_back(plaintext[i]);
        }
    }

    return encoded;
}

std::string decode(const std::string& ciphertext, const std::string& key) {
    std::string decoded;
    for (int i{ 0 };i < ciphertext.size();++i) {
        if (isalpha(ciphertext[i])) {
            char decodedChar = 'a' + ((std::tolower(ciphertext[i]) - 'a') - (std::tolower(key[(i % key.size())]) - 'a') + 26) % 26;
            if (isupper(ciphertext[i])) {
                decodedChar = std::toupper(decodedChar);
            }

            decoded.push_back(decodedChar);
        }
        else {
            decoded.push_back(ciphertext[i]);
        }
    }

    return decoded;
}

int main() {
    std::string plaintxt = "Hello my name is Mher";
    std::string key = "Lemon";
    std::string result = encode(plaintxt, key);
    std::cout << "Plaintext: " << plaintxt;
    std::cout << "\nEncoded: " << result;
    result = decode(result, key);
    std::cout << "\nDecoded: " << result;
}
