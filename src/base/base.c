#include "base.h"

int pie_ispow2(unsigned long x)
{
	while (x % 2 == 0)
		x /= 2;
	return x == 1;
}
