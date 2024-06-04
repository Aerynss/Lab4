#pragma once
#include "address.h"
#include "bank.h"
#include "operations.h"
class exchange_rate
{
public:
	bank some_bank;
	operations bying;
	operations selling;
	address some_address;
	exchange_rate();
	exchange_rate(bank, operations bying, operations selling, address);
};


