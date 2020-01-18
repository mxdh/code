#include <algorithm>
#include <iostream>

const int N = 100000;
struct Player {
  int id, score, strength;

  bool operator<(const Player& b) const {
    return score == b.score ? id < b.id : score > b.score;
  }
} player[N * 2];
int winner[N], cntWinner, loser[N], cntLoser;

void ClearResult() { cntWinner = cntLoser = 0; }

inline void AddWinner(const int k) {
  ++player[k].score;
  winner[cntWinner++] = k;
}

inline void AddLoser(const int k) { loser[cntLoser++] = k; }

inline void Win(int x, int y) {
  AddWinner(x);
  AddLoser(y);
}

void MergeSort() {
  static Player tmp[N * 2];
  int i = 0, j = 0, k = 0;
  while (i < cntWinner && j < cntLoser)
    if (player[winner[i]] < player[loser[j]])
      tmp[k++] = player[winner[i++]];
    else
      tmp[k++] = player[loser[j++]];
  while (i < cntWinner) tmp[k++] = player[winner[i++]];
  while (j < cntLoser) tmp[k++] = player[loser[j++]];
  for (int i = 0; i < k; ++i) player[i] = tmp[i];
}

int main() {
  int n, r, q;
  std::cin >> n >> r >> q;
  n *= 2;
  for (int i = 0; i < n; ++i) player[i].id = i;
  for (int i = 0; i < n; ++i) std::cin >> player[i].score;
  for (int i = 0; i < n; ++i) std::cin >> player[i].strength;
  std::sort(player, player + n);
  for (int i = 0; i < r; ++i) {
    ClearResult();
    for (int j = 0; j < n; j += 2)
      if (player[j].strength > player[j + 1].strength)
        Win(j, j + 1);
      else
        Win(j + 1, j);
    MergeSort();
  }
  std::cout << player[q - 1].id + 1;
  return 0;
}