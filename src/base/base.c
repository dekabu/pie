int pie_isPow(int x)
{
	while (x % 2 == 0)
		x /= 2;
	return x == 1;
}
