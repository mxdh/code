#include <cstdio>

void put_int(int num)
{
	if (num > 9) put_int(num / 10);
	putchar((num % 10) ^ 48);
}