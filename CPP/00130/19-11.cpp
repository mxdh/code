// AC
#include <cstring>
#include <iostream>

using std::cin;

const int N = 100000, M = 200000;
struct Edge {
  int v, val, next;
} edge[M * 2];
int head[N + 1], dis[N + 1], cnt;
bool vis[N + 1];

inline void addEdge(int u, int v, int val) {
  edge[cnt] = {v, val, head[u]};
  head[u] = cnt++;
}

inline void addUndiEdge(int u, int v, int val) {
  addEdge(u, v, val);
  addEdge(v, u, val);
}

void dfs(int k) {
  vis[k] = true;
  for (int i = head[k]; i >= 0; i = edge[i].next) {
    int v = edge[i].v;
    if (!vis[v]) {
      dis[v] = dis[k] ^ edge[i].val;
      dfs(v);
    }
  }
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  std::memset(head, -1, sizeof head);
  while (m--) {
    int u, v, val;
    cin >> u >> v >> val;
    addUndiEdge(u, v, val);
  }
  dfs(1);
  while (q--) {
    int x, y;
    cin >> x >> y;
    std::cout << (dis[x] ^ dis[y]) << '\n';
  }
  return 0;
}