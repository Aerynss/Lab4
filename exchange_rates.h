#ifndef EXCHANGE_RATES_H
#define EXCHANGE_RATES_H

#include "constants.h"
#include <string>
struct bank
{
    char name[MAX_STRING_SIZE];
};

struct Exchange
{
    float buy;
    float sell;
};

struct address
{
    char place[MAX_STRING_SIZE];
};

struct exchange_rates
{
    bank bank;
    Exchange exchange;
    address address;
    void operator = (exchange_rates* rate2) {
        strcpy_s(this->bank.name, rate2->bank.name);
        strcpy_s(this->address.place, rate2->address.place);
        this->exchange.buy = rate2->exchange.buy;
        this->exchange.sell = rate2->exchange.sell;
    }
};

#endif