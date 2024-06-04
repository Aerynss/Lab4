#include "bank.h"
bank::bank() {}
bank::bank(std::string name)
{
	this->bank_name = name;
}
bool bank::operator==(const bank& _bank)
{
	if (bank_name == _bank.bank_name)
	{
		return true;
	}
	else return false;
}