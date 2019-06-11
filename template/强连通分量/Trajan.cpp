#include <algorithm>

using std::min;

const int N = 10000, M = 50000;
struct Edge {
    int v, next;
} edge[M];
int head[N], low[N], dfn[N], d[N + 1], belong[N], sz[N + 1], s[N], t, n_edge,
    n_scc, cnt;

void add_edge(int u, int v) {
    edge[n_edge].v = v;
    edge[n_edge].next = head[u];
    head[u] = n_edge++;
}

void dfs(int k) {
    low[k] = dfn[k] = ++cnt;
    s[t++] = k;
    for (int i = head[k]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (!dfn[v]) {
            dfs(v);
            low[k] = min(low[k], low[v]);
        } else if (!belong[v])
            low[k] = min(low[k], dfn[v]);
    }
    if (low[k] == dfn[k]) {
        n_scc++;
        for (;;) {
            int tmp = s[--t];
            belong[tmp] = n_scc;
            sz[n_scc]++;
            if (tmp == k) break;
        }
    }
}