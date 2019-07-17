// AC
#include <cstdio>
#include <cstring>
#include <queue>

using std::priority_queue;

const int N = 100000;
struct Edge {
    int v, next;
} edge[N << 1];
int head[N], ind[N], b[N], cnt;

void AddEdge(int u, int v) {
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    ++ind[v];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, s = 0;
        priority_queue<int> h;
        scanf("%d%d", &n, &m);
        memset(head, -1, sizeof head);
        memset(ind, 0, sizeof ind);
        cnt = 0;
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            AddEdge(v - 1, u - 1);
        }
        for (int i = 0; i < n; ++i)
            if (!ind[i]) h.push(i);
        while (!h.empty()) {
            int k = h.top();
            h.pop();
            b[s++] = k;
            for (int i = head[k]; ~i; i = edge[i].next) {
                int v = edge[i].v;
                --ind[v];
                if (!ind[v]) h.push(v);
            }
        }
        if (s < n)
            puts("Impossible!");
        else {
            for (int i = n - 1; ~i; --i) printf("%d ", b[i] + 1);
            putchar('\n');
        }
    }
}