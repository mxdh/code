#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

const int N = 500, M = 500, INF = 1E9;

struct DancingLinks {
  struct Node {
    int x, y, l, r, u, d;
  } node[N * M + 1];
  int head[N], size[M + 1], cnt, n, m;

  DancingLinks(int n, int m) {
    std::memset(head, -1, sizeof head);
    std::memset(size, 0, sizeof size);
    size[m] = INF;
    for (int i = 0; i <= m; ++i) node[i] = {-1, i, i - 1, i + 1, i, i};
    node[0].l = m;
    node[m].r = 0;
    cnt = m + 1;
    this->n = n;
    this->m = m;
  }

  void Insert(int x, int y) {
    node[cnt].x = x;
    node[cnt].y = y;
    node[cnt].d = y;
    node[cnt].u = node[y].u;
    node[node[y].u].d = cnt;
    node[y].u = cnt;
    if (head[x] == -1)
      head[x] = node[cnt].l = node[cnt].r = cnt;
    else {
      node[cnt].l = head[x];
      node[cnt].r = node[head[x]].r;
      node[node[head[x]].r].l = cnt;
      node[head[x]].r = cnt;
    }
    ++size[y];
    ++cnt;
  }

  void Remove(int k) {
    k = node[k].y;
    node[node[k].l].r = node[k].r;
    node[node[k].r].l = node[k].l;
    for (int i = node[k].d; i != k; i = node[i].d)
      for (int j = node[i].r; j != i; j = node[j].r) {
        node[node[j].u].d = node[j].d;
        node[node[j].d].u = node[j].u;
        --size[node[j].y];
      }
  }

  void Restore(int k) {
    k = node[k].y;
    node[node[k].l].r = node[node[k].r].l = k;
    for (int i = node[k].u; i != k; i = node[i].u)
      for (int j = node[i].l; j != i; j = node[j].l) {
        node[node[j].u].d = node[node[j].d].u = j;
        ++size[node[j].y];
      }
  }

  bool empty() { return node[m].l == m; }
};

class DLX : public DancingLinks {
 public:
  using DancingLinks::DancingLinks;

  void solve() { _solve(0); }

 private:
  int sta[N];

  void _solve(int cnt) {
    if (empty()) {
      for (int i = 0; i < cnt; ++i) std::cout << sta[i] + 1 << ' ';
      std::exit(0);
    }
    int y = m;
    for (int i = node[m].r; i != m; i = node[i].r)
      if (size[i] < size[y]) y = i;
    Remove(y);
    for (int i = node[y].d; i != y; i = node[i].d) {
      for (int j = node[i].r; j != i; j = node[j].r) Remove(j);
      sta[cnt] = node[i].x;
      _solve(cnt + 1);
      for (int j = node[i].l; j != i; j = node[j].l) Restore(j);
    }
    Restore(y);
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  DLX dlx(n, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int val;
      std::cin >> val;
      if (val) dlx.Insert(i, j);
    }
  }
  dlx.solve();
  std::cout << "No Solution!";
  return 0;
}