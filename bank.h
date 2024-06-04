#pragma once
#include <iostream>
class bank
{
public:
	std::string bank_name;
	bank();
	bank(std::string);
	bool operator==(const bank& _bank);
};

