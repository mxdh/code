// AC
#include <cstdio>

const int N = 100000, M = 100000, P = 100000;
int s[P];

int pow(int a, int b, int p) {
    int ret = 1 % p;
    while (b) {
        if (b & 1) ret = (long long)ret * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }
    return ret;
}

int c(int a, int b, int p) {
    return b > a ? 0
                 : (long long)s[a] * pow(s[b], p - 2, p) % p *
                       pow(s[a - b], p - 2, p) % p;
}

int lucas(int a, int b, int p) {
    return b ? (long long)c(a % p, b % p, p) * lucas(a / p, b / p, p) % p
             : 1 % p;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, p;
        scanf("%d%d%d", &n, &m, &p);
        s[0] = 1 % p;
        for (int i = 1; i < p; ++i) s[i] = (long long)s[i - 1] * i % p;
        printf("%d\n", lucas(n + m, m, p));
    }
    return 0;
}