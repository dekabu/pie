#include "base.h"

int pie_isPow2(unsigned long x)
{
	while (x % 2 == 0)
		x /= 2;

	return x == 1;
}
