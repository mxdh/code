// AC
#include <iostream>

const int N = 13, N_ANS = 3;
int n, s[N], cnt;
bool vis1[N], vis2[(N << 1) - 1], vis3[(N << 1) - 1];

void dfs(int k) {
  if (k == n) {
    if (cnt < N_ANS) {
      for (int i = 0; i < n; ++i) std::cout << s[i] + 1 << ' ';
      std::cout << '\n';
    }
    ++cnt;
    return;
  }
  for (int i = 0; i < n; ++i)
    if (!vis1[i] && !vis2[k - i + n - 1] && !vis3[k + i]) {
      vis1[i] = vis2[k - i + n - 1] = vis3[k + i] = true;
      s[k] = i;
      dfs(k + 1);
      vis1[i] = vis2[k - i + n - 1] = vis3[k + i] = false;
    }
}

int main() {
  std::cin >> n;
  dfs(0);
  std::cout << cnt;
  return 0;
}