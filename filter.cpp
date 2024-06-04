#include "filter.h"
void only_one_bank(exchange_rate* array[], bank find_bank, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i]->some_bank == find_bank)
		{
			std::cout << "Банк: ";
			std::cout << array[i]->some_bank.bank_name << "\nПокупка/Продажа:\n" << array[i]->bying.some_oper << " " << array[i]->selling.some_oper;
			std::cout << "\nАдрес банка: " << array[i]->some_address.bank_address << "\n\n";
		}
	}
}
void better_value(exchange_rate* array[], operations find_value, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i]->selling < find_value)
		{
			std::cout << "Банк: ";
			std::cout << array[i]->some_bank.bank_name << "\nПокупка/Продажа:\n" << array[i]->bying.some_oper << " " << array[i]->selling.some_oper;
			std::cout << "\nАдрес банка: " << array[i]->some_address.bank_address << "\n\n";
		}
	}
}