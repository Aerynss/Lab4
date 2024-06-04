#pragma once
class operations
{
public:
	double some_oper;
	operations();
	operations(double);
	bool operator<(const operations& oper);
};

