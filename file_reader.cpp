#include "file_reader.h"
#include "fstream"
void read_file(const char* file_name, exchange_rate* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[1000];
        while (!file.eof())
        {
            exchange_rate* item = new exchange_rate;
            file >> item->some_bank.bank_name;
            file >> item->bying.some_oper;
            file >> item->selling.some_oper;
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(item->some_address.bank_address, 1000);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}