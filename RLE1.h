#pragma once
#include "ENCDEC.h"
#include <string>

class RLE1 : public ENCDEC {
    void encode(std::string& s) const override;
    void decode(std::string& s) const override;
public:
    void encodeDecode(std::string& s);
};