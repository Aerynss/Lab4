#include "operations.h"
operations::operations() {}
operations::operations(double oper)
{
	if (oper < 0) this->some_oper = -oper;
	else this->some_oper = oper;
}
bool operations::operator<(const operations& oper)
{
	if (some_oper < oper.some_oper)return true;
	else return false;
}