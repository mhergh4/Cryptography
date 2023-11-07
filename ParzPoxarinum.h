#pragma once
#include "ENCDEC.h"
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class ParzPoxarinum : public ENCDEC {
    void encode(std::string& s) const override;
    void decode(std::string& s) const override;
public:
    void encodeDecode(std::string& s);
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string alphabet2 = alphabet;

    ParzPoxarinum() {
        srand(static_cast<unsigned>(time(nullptr)));
        std::random_shuffle(alphabet2.begin(), alphabet2.end());
    }
};
