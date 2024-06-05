#ifndef FILE_READER_H
#define FILE_READER_H

#include "exchange_rates.h"

void read(const char* file_name, exchange_rates* array[], int& size);

#endif