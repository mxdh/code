// AC
#include <algorithm>
#include <cstdio>

using std::swap;

const int N = 200000;
int a[N + 1], s, t;
long long f[N + 1];

long long calc(long long num) {
    return -(num > 0 ? (long long)s * num : (long long)t * num);
}

int main() {
    int n, q;
    long long ans = 0;
    scanf("%d%d%d%d", &n, &q, &s, &t);
    for (int i = 0; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) {
        f[i] = a[i] - a[i - 1];
        ans += calc(f[i]);
    }
    for (int i = 0; i < q; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (y < x) swap(x, y);
        ans -= calc(f[x]);
        f[x] += z;
        ans += calc(f[x]);
        if (y != n) {
            ans -= calc(f[y + 1]);
            f[y + 1] -= z;
            ans += calc(f[y + 1]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}