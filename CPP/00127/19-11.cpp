// AC
#include <iostream>

int main() {
  int n, last = 1, ans = 0;
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    if (a != last) ++ans;
    last = a;
  }
  std::cout << ans;
  return 0;
}