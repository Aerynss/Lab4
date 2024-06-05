#include "pch.h"
#include "CppUnitTest.h"

#include "../main-project/exchange_rates.h"
#include "../main-project/processing.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	exchange_rates* build_rates(float buy, float sell)
	{
		exchange_rates* rates = new exchange_rates;
		rates->exchange.buy = buy;
		rates->exchange.sell = sell;
		return rates;
	}
	void delete_rates(exchange_rates* array[], int size) {
		for (int i = 0; i < size; ++i) {
			delete array[i];
		}
	}

	TEST_CLASS(unittestproject)
	{
	public:
		double precision = 1e-6;
		TEST_METHOD(TestMethod1)
		{
			exchange_rates* rates[3];
			rates[0] = build_rates(3.17, 3.19);
			rates[1] = build_rates(3.3, 3.34);
			rates[2] = build_rates(3.2, 3.1);
			Assert::AreEqual(0.1, (double)process(rates, 3),precision);
			delete_rates(rates, 3);
		}

		TEST_METHOD(TestMethod2)
		{
			exchange_rates* rates[3];
			rates[0] = build_rates(2.85, 2.90);
			rates[1] = build_rates(3.324, 3.326);
			rates[2] = build_rates(3.3, 3.31);
			Assert::AreEqual(0.05, (double)process(rates, 3),precision);
			delete_rates(rates, 3);
		}
		TEST_METHOD(TestMethod3)
		{
			exchange_rates* rates[3];
			rates[0] = build_rates(3.2, 3.4);
			rates[1] = build_rates(3.3, 3.34);
			rates[2] = build_rates(3.2, 3.1);
			Assert::AreEqual(0.2, (double)process(rates, 3),precision);
			delete_rates(rates, 3);
		}
	};
}
