#include "exchange_rate.h"
exchange_rate::exchange_rate() {}
exchange_rate::exchange_rate(bank _bank_, operations _bying_, operations _selling_, address _address_)
{
	this->some_bank = _bank_;
	this->bying = _bying_;
	this->selling = _selling_;
	this->some_address = _address_;
}