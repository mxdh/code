#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <class T>
inline void read(T &x) {
    x = 0;
    char c = getchar();
    bool f = 0;
    for (; !isdigit(c); c = getchar()) f ^= c == '-';
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    x = f ? -x : x;
}

template <class T>
inline void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    T y = 1;
    int len = 1;
    for (; y <= x / 10; y *= 10) ++len;
    for (; len; --len, x %= y, y /= 10) putchar(x / y + 48);
}

const int MAXN = 1e3;
int n, m;
bool vis[MAXN + 5];

inline bool check(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return 0;
    return 1;
}

inline void printEdge(int u, int v) {
    write(u);
    putchar(' ');
    write(v);
    putchar('\n');
}

int main() {
    read(n);
    for (m = n; !check(m); ++m)
        ;
    write(m);
    putchar('\n');
    for (int i = 1; i < n; ++i) printEdge(i, i + 1);
    printEdge(n, 1);
    for (int i = 1; i <= m - n; ++i)
        for (int j = 1; j <= n; ++j)
            if (!vis[j] && !vis[(j + 1) % n + 1]) {
                printEdge(j, (j + 1) % n + 1);
                vis[j] = vis[(j + 1) % n + 1] = 1;
                break;
            }
    return 0;
}