#include <algorithm>
#include <cstdio>

using std::min;

int main() {
    freopen("bx.in", "r", stdin);
    freopen("bx.out", "w", stdout);
    long long s, t, n;
    while (scanf("%lld%lld%lld", &s, &t, &n) == 3) {
        long long tmp = s - (n - 1), ans1 = (n - 1) * 3, ans2 = n;
        if (tmp < 0) {
            ans1 += tmp * 2;
            tmp = 0;
        }
        if (tmp > t) ans1 += 3;
        if (tmp == t) ans1 += 1;
        ans2 = min(n + 2 - min(n - 1, t), n - min(n, t >= s ? t - s : -2));
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}