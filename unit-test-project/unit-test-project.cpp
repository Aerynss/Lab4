#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab4\processing.h"
#include "..\Lab4\exchange_rate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	exchange_rate* build_rate(std::string _bank_, double _buying_, double _selling_, char* _address_)
	{
		exchange_rate* temp = new exchange_rate;
		temp->some_bank.bank_name = _bank_;
		temp->buying.some_oper = _buying_;
		temp->selling.some_oper = _selling_;
		strcpy(temp->some_address.bank_address, _address_);
	}

	//       
	void delete_rate(exchange_rate* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}


	TEST_CLASS(unittestproject)
	{
	public:
		
		TEST_METHOD(TestMethod1) //     
		{
			exchange_rate* rates[3];
			rates[0] = build_rate("Беларусбанк", 10, 2, "г.Витебск пр.Московский д.54"); 
			rates[1] = build_rate("Беларусбанк", 10, 2.9, "г.Витебск пр.Московский д.54"); 
			rates[2] = build_rate("Беларусбанк", 9, 2.4, "г.Витебск пр.Московский д.54"); 
			Assert::AreEqual(7., process(rates, 3, 0));
			delete_rate(rates, 3);
		}

		TEST_METHOD(TestMethod2) //        
		{
			exchange_rate* rates[3];
			rates[0] = build_rate("Беларусбанк", 10, 2, "г.Витебск ул.Смоленская д.21"); // 15 
			rates[1] = build_rate("Беларусбанк", 10, 2.9, "г.Витебск ул.Смоленская д.21"); // 19 
			rates[2] = build_rate("Беларусбанк", 9, 2.4, "г.Витебск ул.Смоленская д.21"); // 14 
			Assert::AreEqual(19., process(rates, 3, 1));
			delete_rate(rates, 3);
		}

		TEST_METHOD(TestMethod3) //         
		{
			exchange_rate* rates[3];
			rates[0] = build_rate("Беларусбанк", 10, 2, "г.Витебск ул.Смоленская д.213"); // 11 
			rates[1] = build_rate("Беларусбанк", 10, 2.9, "г.Витебск ул.Смоленская д.213"); // 11 
			rates[2] = build_rate("Беларусбанк", 9, 2.4, "г.Витебск ул.Смоленская д.213"); // 10 
			Assert::AreEqual(6.6, process(rates, 3, 2));
			delete_rate(rates, 3);
		}

		

	};
}
