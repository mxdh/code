// AC
#include <cstdio>
#include <cstring>
#include <queue>

using std::priority_queue;

const int K = 50, N = 200, V = 5000;
int a[N], b[N], f[V + 1][K], cnt[V + 1], tmp[K];

int main() {
    freopen("bag.in", "r", stdin);
    freopen("bag.out", "w", stdout);
    int k, v, n, ans = 0;
    scanf("%d%d%d", &k, &v, &n);
    for (register int i = 0; i < n; ++i) scanf("%d%d", a + i, b + i);
    cnt[0] = 1;
    for (register int i = 0; i < n; ++i)
        for (register int j = v; j >= a[i]; --j) {
            int p = 0, p1 = 0, p2 = 0, o = j - a[i];
            while (p < k && (p1 < cnt[o] || p2 < cnt[j]))
                if (p2 == cnt[j] || (p1 < cnt[o] && f[o][p1] + b[i] > f[j][p2]))
                    tmp[p++] = f[o][p1++] + b[i];
                else
                    tmp[p++] = f[j][p2++];
            memcpy(f[j], tmp, sizeof tmp);
            cnt[j] = p;
        }
    for (register int i = 0; i < cnt[v]; ++i) ans += f[v][i];
    printf("%d", ans);
    return 0;
}