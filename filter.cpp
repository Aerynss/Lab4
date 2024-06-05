#include "filter.h"
#include <cstring>
#include <iostream>

exchange_rates** filter(
    exchange_rates* array[],
    int size,
    bool (*check)(exchange_rates* element),
    int& result_size
) {
    exchange_rates** result = new exchange_rates * [size];
    result_size = 0;
    for (int i = 0; i < size; ++i) {
        if (check(array[i])) {
            result[result_size++] = array[i];
        }
    }
    return result;
}

bool check_by_name(
    exchange_rates* element
) {
    return strcmp(element->bank.name, "Беларусбанк") == 0;
}
bool check_by_sell(
    exchange_rates* element
) {
    return element->exchange.sell < 2.5;
}
