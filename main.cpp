#include <iostream>
#include <iomanip>
using namespace std;

#include "exchange_rates.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "Sorting.h"

void output(exchange_rates* bank) {
    cout << "����...............:";
    cout << bank->bank.name << '\n';
    cout << "�����..............:";
    cout << bank->exchange.buy << '\n';
    cout << "�������............:";
    cout << bank->exchange.sell << '\n';
    cout << "����� ���������....:";
    cout << bank->address.place << '\n';
    cout << '\n';
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �4. GIT\n";
    cout << "������� �4. ����� ������\n";
    cout << "�����: ���� �������\n";
    cout << "������: 23��1�\n\n";
    exchange_rates* exchange_rate[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", exchange_rate, size);
        cout << "***** ����� ����� *****\n\n";
        for (int i = 0; i < size; i++)
        {
            output(exchange_rate[i]);
        }
        bool (*check_function)(exchange_rates*) = NULL;
        bool (*check_function2)(exchange_rates * rate1, exchange_rates * rate2) = NULL;

        cout << "\n������:\n";
        cout << "\n1): ����� ������ �� ���� ���������� ����� ������������ (� ��������). \n";
        cout << "\n2): ����� ������ � ������ ��������� ������, � ������� ������� ������ 2,5.\n";
        cout << "\n3): ���������� �� ���������.\n";
        cout << "\n������� ����� ������:\n";
        int item;
        cin >> item;
        cout << '\n';
        switch (item) {
        case 1:
            check_function = check_by_name;
            cout << "****** ����� ������ �� ���� ���������� ����� ������������ (� ��������) *******\n\n";
            break;
        case 2:
            check_function = check_by_sell;
            cout << "****** ����� ������ � ������ ��������� ������, � ������� ������� ������ 2,5 *******\n\n";
            break;
        case 3:
            cout << "\n����������:\n";
            cout << "\n1): ���������� ���������. \n";
            cout << "\n2): ���������� ��������.\n";
            cout << "\n������� ����� ����������:\n";

            int item2;
            cin >> item2;
            cout << '\n';

            cout << "\n��������:\n";
            cout << "\n1): �� �������� ������� ����� ���������� ������� � �������. \n";
            cout << "\n2): �� ����������� �������� �����, � � ������ ������ ����� �� ����������� ������ ���������.\n";
            cout << "\n������� ����� ��������:\n";
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