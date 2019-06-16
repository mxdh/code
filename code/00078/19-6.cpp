// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::sort;

const int N = 100, MAX = 10000;
int sg[MAX + 1], a[N];
bool vis[MAX + 1];

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < n; ++i) scanf("%d", a + i);
        sort(a, a + n);
        for (int i = 1; i <= MAX; ++i) {
            memset(vis, 0, sizeof vis);
            for (int j = 0; j < n && a[j] <= i; ++j) vis[sg[i - a[j]]] = true;
            for (int j = 0;; ++j)
                if (!vis[j]) {
                    sg[i] = j;
                    break;
                }
        }
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            int k, ans = 0;
            scanf("%d", &k);
            for (int j = 0; j < k; ++j) {
                int b;
                scanf("%d", &b);
                ans ^= sg[b];
            }
            putchar(ans ? 'W' : 'L');
        }
        putchar('\n');
    }
    return 0;
}
