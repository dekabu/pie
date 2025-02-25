int pie_isPow2(int x)
{
	while (x % 2 == 0)
		x /= 2;
	return x == 1;
}
