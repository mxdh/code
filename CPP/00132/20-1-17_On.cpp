// AC
#include <iostream>

const int NA = 200, NB = 200,
          status[5][5] = {{0, 0, 1, 1, 0},
                          {1, 0, 0, 1, 0},
                          {0, 1, 0, 0, 1},
                          {0, 0, 1, 0, 1},
                          {1, 1, 0, 0, 0}};
int a[NA], b[NB];

int main() {
  int n, na, nb, scoreA = 0, scoreB = 0;
  std::cin >> n >> na >> nb;
  for (int i = 0; i < na; ++i) std::cin >> a[i];
  for (int i = 0; i < nb; ++i) std::cin >> b[i];
  for (int i = 0; i < n; ++i) {
    scoreA += status[a[i % na]][b[i % nb]];
    scoreB += status[b[i % nb]][a[i % na]];
  }
  std::cout << scoreA << ' ' << scoreB;
  return 0;
}