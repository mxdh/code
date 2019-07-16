#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            AddEdge(v - 1, u - 1);
        }
        for (int i = 0; i < n; ++i)
            if (!ind[i]) q[r++] = i;
    }
}