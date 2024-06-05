#pragma once
#include "exchange_rate.h"
#ifndef PROCESSING_H
#define PROCESSING_H
double diff(operations a, operations b);
double process(exchange_rate* array[], int size, int key);


#include "exchange_rate.h"

bool by_exchange_difference(const exchange_rate* rate1, const exchange_rate* rate2);
bool by_name_rising(const exchange_rate* rate1, const exchange_rate* rate2);
void bubble_sort(exchange_rate* rate[], int size, bool (*compare_function)(const exchange_rate*, const exchange_rate*));
void merge_sort(exchange_rate* rate[], int left, int right, bool (*compare_function)(const exchange_rate*, const exchange_rate*));
double process(exchange_rate* rate[], int size, int index);

#endif // PROCESSING_H
