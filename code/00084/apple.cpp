#include <algorithm>
#include <cctype>
#include <cstdio>

using std::sort;

const int N = 1000000;
int a1[N+1], a2[N+1];

inline char GetChar()
{
	static const int SIZE = 1 << 20;
	static char buf[SIZE], *s = buf, *t = buf;
	return (s == t) &&(t = (s = buf) + fread(buf, 1, SIZE, stdin), s == t) ?EOF: *s++;
}

#define getchar GetChar

template <typename T>
inline void GetNum(T &num)
{
	char ch = getchar();
	num = 0;
	for (; !isdigit(ch); ch = getchar())
		;
	for (; isdigit(ch); ch = getchar())
		num = (num << 3) + (num << 1) + (ch ^ 48);
}

inline bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n, v, cnt1 = 0, cnt2 = 0, ans2 = 0;
	GetNum(n);
	GetNum(v);
	for (int i = 0; i < n; ++i)
	{
		int w, c;
		GetNum(w);
		GetNum(c);
		if (w == 1)
			a1[cnt1++] = c;
		else
			a2[cnt2++] = c;
	}
	sort(a1, a1 + cnt1, cmp);
	sort(a2, a2 + cnt2, cmp);
	int k1 = 0, k2 = 0;
	long long ans = 0;
	if (v & 1)
	{
		--v;
		if (cnt1)
		{
			++ans2;
			++k1;
			ans += a1[0];
		}
	}
	if ((cnt1 - k1) & 1)
		a1[cnt1++] = 0;
	while (v)
	{
		if (k1 >= cnt1 - 1 && k2 >= cnt2)
			break;
		if (k2 >= cnt2 || (k1 < cnt1 - 1 && a1[k1] + a1[k1 + 1] >= a2[k2]))
		{
			ans += a1[k1] + a1[k1 + 1];
			++ans2;
			if (a1[k1 + 1])
				++ans2;
			k1 += 2;
		}
		else
		{
			ans2 += 2;
			ans += a2[k2];
			++k2;
		}
		v -= 2;
	}
	printf("%lld\n%d", ans, ans2);
	return 0;
}
