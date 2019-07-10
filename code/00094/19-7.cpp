#include <cstdio>

const int N = 50;
bool g[N][N];

int main() {
    int n, u, v;
    scanf("%d", &n);
    while (scanf("%d%d", &u, &v) != EOF) {
        --u;
        --v;
        g[u][v] = g[v][u] = true;
    }
    return 0;
}