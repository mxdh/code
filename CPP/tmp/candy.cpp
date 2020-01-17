#include <cmath>
#include <cstdio>

const int N = 100000;
int a[N << 1];

int main() {
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        a[n + i] = a[i];
    }
    long long sum = 0, ans1;
    int ans2;
    double ans = 0;
    int ss = sqrt(ans2);
    for (int i = 2; i <= ss; ++i)
        while (!(ans1 % i) && !(ans2 % i)) {
            ans1 /= i;
            ans2 /= i;
        }
    if (!(ans1 % ans2)) {
        ans1 /= ans2;
        ans2 = 1;
    }
    if (ans2 > 1)
        printf("%lld/%d", ans1, ans2);
    else
        printf("%lld", ans1);
    return 0;
}