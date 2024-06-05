#ifndef SORTING_H
#define SORTING_H
#include "exchange_rates.h"
void bubble_sort(
	exchange_rates* array[],
	int size,
	bool (*check)(exchange_rates* rate1, exchange_rates* rate2)
	);

void merge_sort(
	exchange_rates* array[],
	int begin,
	int size,
	bool (*check)(exchange_rates* rate1, exchange_rates* rate2)
);
void merge(exchange_rates* array[], int  left, int mid,
	int right,
	bool (*check)(exchange_rates* rate1, exchange_rates* rate2));

bool by_exchange_difference(
	exchange_rates* rate1,
	exchange_rates* rate2);

bool by_name_rising(
	exchange_rates* rate1,
	exchange_rates* rate2);
#endif