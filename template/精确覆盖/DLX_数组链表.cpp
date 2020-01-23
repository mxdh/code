#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

const int N = 500, M = 500, INF = 1E9;

struct DancingLinks {
  int x[N * M + 1], y[N * M + 1], l[N * M + 1], r[N * M + 1], u[N * M + 1],
      d[N * M + 1], head[N], size[M + 1], cnt, n, m;

  DancingLinks(int n, int m) {
    std::memset(head, -1, sizeof head);
    std::memset(size, 0, sizeof size);
    size[m] = INF;
    for (int i = 0; i <= m; ++i) {
      x[i] = -1;
      l[i] = i - 1;
      r[i] = i + 1;
      y[i] = u[i] = d[i] = i;
    }
    l[0] = m;
    r[m] = 0;
    cnt = m + 1;
    this->n = n;
    this->m = m;
  }

  void Insert(int x, int y) {
    this->x[cnt] = x;
    this->y[cnt] = y;
    d[cnt] = y;
    u[cnt] = u[y];
    d[u[y]] = cnt;
    u[y] = cnt;
    if (head[x] == -1)
      head[x] = l[cnt] = r[cnt] = cnt;
    else {
      l[cnt] = head[x];
      r[cnt] = r[head[x]];
      l[r[head[x]]] = cnt;
      r[head[x]] = cnt;
    }
    ++size[y];
    ++cnt;
  }

  void Remove(int k) {
    k = y[k];
    r[l[k]] = r[k];
    l[r[k]] = l[k];
    for (int i = d[k]; i != k; i = d[i])
      for (int j = r[i]; j != i; j = r[j]) {
        d[u[j]] = d[j];
        u[d[j]] = u[j];
        --size[y[j]];
      }
  }

  void Restore(int k) {
    k = y[k];
    r[l[k]] = l[r[k]] = k;
    for (int i = u[k]; i != k; i = u[i])
      for (int j = l[i]; j != i; j = l[j]) {
        d[u[j]] = u[d[j]] = j;
        ++size[y[j]];
      }
  }

  bool empty() { return l[m] == m; }
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
    for (int i = r[m]; i != m; i = r[i])
      if (size[i] < size[y]) y = i;
    Remove(y);
    for (int i = d[y]; i != y; i = d[i]) {
      for (int j = r[i]; j != i; j = r[j]) Remove(j);
      sta[cnt] = x[i];
      _solve(cnt + 1);
      for (int j = l[i]; j != i; j = l[j]) Restore(j);
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