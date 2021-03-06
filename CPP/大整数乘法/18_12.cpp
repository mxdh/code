// AC
#include <cstdio>
#include <cstring>

typedef long long ll;

class Num
{
  public:
	static const int LEN = 400, BASE = 10;
	void init(ll num = 0);
	Num(const ll num = 0) { init(num); }
	void stn(const char s[]);
	Num(const char s[]) { stn(s); }
	void input();
	void output() const;
	int &operator[](const int k) { return num[k]; }
	int operator[](const int k) const { return num[k]; }
	Num operator*(const Num &b) const;

  private:
	int num[LEN], len;
};

int main()
{
	Num a, b;
	a.input();
	b.input();
	(a * b).output();
	return 0;
}

void Num::init(ll num)
{
	memset(this->num, 0, sizeof this->num);
	for (len = 0; num; ++len)
	{
		this->num[len] = num % BASE;
		num /= BASE;
	}
	if (!len) len = 1;
}

void Num::stn(const char s[])
{
	memset(num, 0, sizeof num);
	int tmp = strlen(s);
	for (len = 0; len < tmp; ++len) num[len] = s[tmp - 1 - len] - '0';
	while (len > 1 && !num[len - 1]) --len;
}

void Num::input()
{
	char s[LEN + 1];
	scanf("%s", s);
	stn(s);
}

void Num::output() const
{
	for (int i = len - 1; ~i; --i) printf("%d", num[i]);
}

Num Num::operator*(const Num &b) const
{
	Num ret;
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < b.len; ++j) ret[i + j] += num[i] * b[j];
	int &l = ret.len;
	l = len + b.len - 1;
	for (int i = 0; i < l; ++i)
	{
		ret[i + 1] += ret[i] / BASE;
		ret[i] %= BASE;
	}
	if (ret[l]) ++l;
	while (l > 1 && !ret[l - 1]) --l;
	return ret;
}