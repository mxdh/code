#include <iostream>

using namespace std;

const int N = 20;
int a[N], p[N];

long long mul(long long a, long long b, long long p) {
    a %= p;
    b %= p;
    long long ret = 0;
    while (b) {
        if (b & 1) ret = (ret + a) % p;
        a = (a << 1) % p;
        b >>= 1;
    }
    return ret;
}

int exgcd(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int ret = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return ret;
}

long long crt(int n) {
    long long ret = 0, lcm = 1;
    for (int i = 0; i < n; ++i) lcm *= p[i];
    for (int i = 0; i < n; ++i) {
        long long tmp = lcm / p[i], x, y;
        exgcd(tmp, p[i], x, y);
        x = (x % p[i] + p[i]) % p[i];
        ret = (ret + mul(mul(tmp, x, lcm), a[i], lcm)) % lcm;
    }
    return (ret + lcm) % lcm;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) a[i] = (a[i] % p[i] + p[i]) % p[i];
    cout << crt(n);
    return 0;
}