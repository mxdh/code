// AC
#include <algorithm>
#include <iostream>

const int N = 1000, M = 1000;
struct Way {
  int id, val;
} sx[N - 1], sy[M - 1];

inline bool GreaterVal(const Way &a, const Way &b) { return a.val > b.val; }

inline bool LessId(const Way &a, const Way &b) { return a.id < b.id; }

int main() {
  int n, m, k, l, d;
  std::cin >> n >> m >> k >> l >> d;
  for (int i = 0; i < n; ++i) sx[i].id = i;
  for (int i = 0; i < m; ++i) sy[i].id = i;
  for (int i = 0; i < d; ++i) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2)
      ++sy[std::min(y1, y2) - 1].val;
    else
      ++sx[std::min(x1, x2) - 1].val;
  }
  std::sort(sx, sx + n, GreaterVal);
  std::sort(sx, sx + k, LessId);
  std::sort(sy, sy + m, GreaterVal);
  std::sort(sy, sy + l, LessId);
  for (int i = 0; i < k; ++i) std::cout << sx[i].id + 1 << ' ';
  std::cout << '\n';
  for (int i = 0; i < l; ++i) std::cout << sy[i].id + 1 << ' ';
  return 0;
}