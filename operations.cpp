#include "operations.h"
operations::operations() {}
operations::operations(double oper)
{
	if (oper < 0) this->some_oper = -oper;
	this->some_oper = oper;
}