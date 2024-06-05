#include "filter.h"
#include <cstring>
#include <iostream>

void bubble_sort(
	exchange_rates* array[],
	int size,
	bool (*check)(exchange_rates* rate1, exchange_rates* rate2)
) {
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (check(array[j], array[j + 1])) {
				std::swap(array[j], array[j + 1]);
			}

}
void merge(exchange_rates* array[], int  left, int mid,
    int right,
    bool (*check)(exchange_rates* rate1, exchange_rates* rate2))
{
    int arr1 = mid - left + 1;
    int arr2 = right - mid;

    exchange_rates** leftArray = new exchange_rates * [arr1],
        ** rightArray = new exchange_rates * [arr2];

    for (auto i = 0; i < arr1; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < arr2; j++)
        rightArray[j] = array[mid + 1 + j];

    auto arr1_ind = 0, arr2_ind = 0;
    int merged_index = left;

    while (arr1_ind < arr1
        && arr2_ind < arr2) {
        if (!check(leftArray[arr1_ind], rightArray[arr2_ind])) {
            array[merged_index] = leftArray[arr1_ind];
            arr1_ind++;
        }
        else {
            array[merged_index] = rightArray[arr2_ind];
            arr2_ind++;
        }
        merged_index++;
    }

    while (arr1_ind < arr1) {
        array[merged_index] = leftArray[arr1_ind];
        arr1_ind++;
        merged_index++;
    }

    while (arr2_ind < arr2) {
        array[merged_index] = rightArray[arr2_ind];
        arr2_ind++;
        merged_index++;
    }
    delete[] leftArray;
    delete[] rightArray;
}


void merge_sort(
    exchange_rates* array[],
    int begin,
    int size,
	bool (*check)(exchange_rates* rate1, exchange_rates* rate2)
) {
    int end = size;
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    merge_sort(array, begin, mid,check);
    merge_sort(array, mid + 1, end,check);
    merge(array, begin, mid, end,check);
}

bool by_exchange_difference(
	exchange_rates* rate1,
	exchange_rates* rate2) {
	float diff1 = abs(rate1->exchange.buy - rate1->exchange.sell);
	float diff2 = abs(rate2->exchange.buy - rate2->exchange.sell);
    return diff1 < diff2;
}

bool by_name_rising(
	exchange_rates* rate1,
	exchange_rates* rate2) {
	if (strcmp(rate1->bank.name, rate2->bank.name) == 0) {
		return strcmp(rate1->address.place, rate2->address.place) > 0;
	}
	return strcmp(rate1->bank.name, rate2->bank.name) > 0;
}