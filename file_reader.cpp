#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

/*date convert(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
} */

void read(const char* file_name, exchange_rates* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
           exchange_rates* item = new exchange_rates;
           file >> item->bank.name;
           file >> item->exchange.buy;
           file >> item->exchange.sell;
          // file >> tmp_buffer;
           file.read(tmp_buffer, 1);
           file.getline(item->address.place,MAX_STRING_SIZE);
           array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}