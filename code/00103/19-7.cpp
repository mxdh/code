#include <cctype>
#include <cstdio>

const int N = 80000;
int sum[N + 1];
long long f[N + 1];

inline char GetChar() {
    static const int SIZE = 1 << 20;
    static char buf[SIZE], *s, *t;
    return (s == t) && (t = (s = buf) + fread(buf, 1, SIZE, stdin), s == t)
               ? EOF
               : *s++;
}

#define getchar GetChar

inline int GetInt() {
    char c;
    int ret = 0;
    bool p = false;
    for (c = getchar(); !isdigit(c); c = getchar()) p |= c == '-';
    for (; isdigit(c); c = getchar()) ret = (ret << 1) + (ret << 3) + (c ^ 48);
    return p ? -ret : ret;
}

void PutInt(int num) {
    if (num > 9) PutInt(num / 10);
    putchar((num % 10) ^ 48);
}

int main() {
    int n = GetInt(), q = GetInt(), p = GetInt(), a = GetInt(), b = GetInt(), m;
    for (int i = 0; i < q; ++i) {
        int op = getchar();
        while (op != 'A' && op != 'Q') op = getchar();
        int l = GetInt(), r = GetInt();
        if (op == 'A') {
            int num = GetInt();
            f[l] += num;
            if (r < n) f[r + 1] -= num;
        } else {
            long long now = 0;
            int ans = 0;
            for (int i = 1; i <= r; ++i) {
                now += f[i];
                int tmp = now % p * i % p;
                if (i >= l && tmp >= a && tmp <= b) ++ans;
            }
            PutInt(ans);
            putchar('\n');
        }
    }
    long long now = 0;
    for (int i = 1; i <= n; ++i) {
        now += f[i];
        int tmp = now % p * i % p;
        sum[i] = sum[i - 1];
        if (tmp >= a && tmp <= b) ++sum[i];
    }
    m = GetInt();
    for (int i = 0; i < m; ++i) {
        int l = GetInt(), r = GetInt();
        PutInt(sum[r] - sum[l - 1]);
        putchar('\n');
    }
    return 0;
}