// AC
#include <iostream>
#include <string>

const int N = 100000, M = 100000;
int face[N];
std::string job[N];

int main() {
  int n, m, k = 0;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) std::cin >> face[i] >> job[i];
  for (int i = 0; i < m; ++i) {
    int dir, dist;
    std::cin >> dir >> dist;
    if (face[k] == dir)
      k = ((k - dist) % n + n) % n;
    else
      k = (k + dist) % n;
  }
  std::cout << job[k];
  return 0;
}