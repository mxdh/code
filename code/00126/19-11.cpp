// AC
#include <algorithm>
#include <iostream>

const int N = 1000000;
long long a[N - 1];

int main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  long long seg = 0, sum = 0, mm;
  std::cin >> n >> k;
  for (int i = 0; i < n - 1; ++i) {
    std::cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < k; ++i) seg += a[i];
  mm = seg;
  for (int i = k; i < n - 1; ++i) {
    seg += a[i] - a[i - k];
    mm = std::max(mm, seg);
  }
  std::cout << sum - mm;
  return 0;
}