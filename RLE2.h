#pragma once
#include "ENCDEC.h"
#include <string>


class RLE2 : public ENCDEC {
    void encode(std::string& input) const ;
    void decode(std::string& input) const ;
public:
    void encodeDecode(std::string& input);
};