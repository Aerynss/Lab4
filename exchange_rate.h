#pragma once
#include "address.h"
#include "bank.h"
#include "operations.h"
class exchange_rate
{
public:
	bank some_bank;
	operations buying;
	operations selling;
	address some_address;
	exchange_rate();
	exchange_rate(bank, operations buying, operations selling, address);
};


