#pragma once
#include <iostream>
#include <string>
class ENCDEC {
private:
	virtual void encode(std::string&)const = 0;
	virtual void decode(std::string&)const = 0;
};
