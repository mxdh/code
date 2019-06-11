#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using std::swap;

const int N = 100000;
int a[N];

void qsort(int l, int r)
{
	if (l >= r) return;
	int i = l, j = r, tmp = a[l + rand() % (r - l + 1)];
	while (i <= j)
	{
		while (a[i] < tmp) ++i;
		while (a[j] > tmp) --j;
		if (i <= j) swap(a[j--], a[i++]);
	}
	qsort(l, j);
	qsort(i, r);
}

void sort(int l, int r)
{
	srand(time(NULL));
	qsort(l, r);
}