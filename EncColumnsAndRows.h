#pragma once
#include "ENCDEC.h"

class EncColumnsAndRows : public ENCDEC {
    void encode(std::string& ) const override;
    void decode(std::string& ) const override;
public:
    void encodeDecode(std::string& s);
    EncColumnsAndRows(const std::string& key);
private:
    std::string key;

};