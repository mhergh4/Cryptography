#include "ParzPoxarinum.h"


void ParzPoxarinum::encodeDecode(std::string& s) {
    encode(s);
    std::cout << "Encoded string: " << s << std::endl;

    decode(s);
    std::cout << "Decoded string: " << s << std::endl;


}
void ParzPoxarinum::encode(std::string& s) const {
    for (char& c : s) {
        size_t index = alphabet.find(c);
        if (index != std::string::npos) {
            c = alphabet2[index];
        }
    }
}

void ParzPoxarinum::decode(std::string& s) const {
    for (char& c : s) {
        size_t index = alphabet2.find(c);
        if (index != std::string::npos) {
            c = alphabet[index];
        }
    }
}

