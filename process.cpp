#include "processing.h"
double diff(operations b, operations d)
{
	double x = b.some_oper;
	double y = d.some_oper;
	return (x > y ? x - y : y - x);
}

double process(exchange_rate* array[], int size, int key)
{
	double max = diff(array[key]->buying, array[key]->selling);
	for (int i = 1; i < size; i++)
	{
		int curr = diff(array[key]->buying, array[key]->selling);
		if (curr > max)
		{
			max = curr;
		}
	}
	return max;
}
