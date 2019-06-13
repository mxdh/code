// AC
#include <cstdio>
#include <cstring>

const int N = 10, A = 1000;
int a[N], b[N], sg[A + 1];
bool vis[A + 1];

int main() {
    int n, m, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) scanf("%d", b + i);
    for (int i = 1; i <= A; ++i) {
        memset(vis, 0, sizeof vis);
        for (int j = 0; j < m && b[j] <= i; ++j) vis[sg[i - b[j]]] = true;
        for (int j = 0;; ++j)
            if (!vis[j]) {
                sg[i] = j;
                break;
            }
    }
    for (int i = 0; i < n; ++i) ans ^= sg[a[i]];
    if (ans) {
        puts("YES");
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m && b[j] <= a[i]; ++j)
                if (!(ans ^ sg[a[i]] ^ sg[a[i] - b[j]])) {
                    printf("%d %d\n", i + 1, b[j]);
                    return 0;
                }
    } else
        puts("NO");
    return 0;
}
