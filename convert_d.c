#include "holberton.h"

int p_dec(int nb)
{
	int num;
	int last = nb % 10;
	int dig;
	int exp = 1;
	int i = 1;

	nb = nb / 10;
	num = nb;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		nb = -nb;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = nb;
		while (exp > 0)
		{
			dig = num / exp;
			_putchar(dig + '0');
			num = num - (dig * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}
