#include <iostream>
#include <iomanip>
using namespace std;

#include "exchange_rates.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "Sorting.h"

void output(exchange_rates* bank) {
    cout << "Банк...............:";
    cout << bank->bank.name << '\n';
    cout << "Купля..............:";
    cout << bank->exchange.buy << '\n';
    cout << "Продажа............:";
    cout << bank->exchange.sell << '\n';
    cout << "Адрес отделения....:";
    cout << bank->address.place << '\n';
    cout << '\n';
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №4. GIT\n";
    cout << "Вариант №4. Курсы валюты\n";
    cout << "Автор: Олег Дроздов\n";
    cout << "Группа: 23ПИ1д\n\n";
    exchange_rates* exchange_rate[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", exchange_rate, size);
        cout << "***** Курсы валют *****\n\n";
        for (int i = 0; i < size; i++)
        {
            output(exchange_rate[i]);
        }
        bool (*check_function)(exchange_rates*) = NULL;
        bool (*check_function2)(exchange_rates * rate1, exchange_rates * rate2) = NULL;

        cout << "\nЗадачи:\n";
        cout << "\n1): Курсы валюты во всех отделениях банка «Беларусбанк» (с адресами). \n";
        cout << "\n2): Курсы валюты и адреса отделений банков, в которых продажа меньше 2,5.\n";
        cout << "\n3): Сортировка по критериям.\n";
        cout << "\nВведите номер задачи:\n";
        int item;
        cin >> item;
        cout << '\n';
        switch (item) {
        case 1:
            check_function = check_by_name;
            cout << "****** Курсы валюты во всех отделениях банка «Беларусбанк» (с адресами) *******\n\n";
            break;
        case 2:
            check_function = check_by_sell;
            cout << "****** Курсы валюты и адреса отделений банков, в которых продажа меньше 2,5 *******\n\n";
            break;
        case 3:
            cout << "\nСортировки:\n";
            cout << "\n1): Сортировка пузырьком. \n";
            cout << "\n2): Сортировка слиянием.\n";
            cout << "\nВведите номер сортировки:\n";

            int item2;
            cin >> item2;
            cout << '\n';

            cout << "\nКритерии:\n";
            cout << "\n1): По убыванию разницы между стоимостью продажи и покупки. \n";
            cout << "\n2): По возрастанию названию банка, а в рамках одного банка по возрастанию адреса отделения.\n";
            cout << "\nВведите номер критерия:\n";
            int item3;
            cin >> item3;
            cout << '\n';
            switch (item3) {
            case 1:
                check_function2 = by_exchange_difference;
                break;
            case 2:
                check_function2 = by_name_rising;
                break;
            default:
                throw "error";
            }

            switch (item2) {
            case 1:
                bubble_sort(exchange_rate, size, check_function2);
                break;
            case 2:
                merge_sort(exchange_rate, 0,size - 1, check_function2);
                break;
            default:
                throw "error";
            }
            break;
        default:
            throw "error";
        }
        if (check_function) {
            int new_size;
            exchange_rates** filtered = filter(exchange_rate, size, check_function, new_size);
            for (int i = 0; i < new_size; ++i) {
                output(filtered[i]);
            }
            delete[] filtered;
        }
        if (check_function2) {
            for (int i = 0; i < size; ++i) {
                output(exchange_rate[i]);
            }
        }
        for (int i = 0; i < size; i++)
        {
            delete exchange_rate[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    /*cout << "Laboratory work #4. GIT\n";
    cout << "Variant #4. Exchange Rates\n";
    cout << "Author: Oleg Drozdov\n";
    cout << "Group: 23PI1d\n"; */
    return 0;
}