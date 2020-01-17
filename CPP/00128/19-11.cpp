#include <iostream>
#include <list>

using std::cin;

const int N = 1000000, M = 33333;
int s[N], t[M * 2];
std::list<int> h;

int main() {
  int n, m, l = M - 1, r = M, ans = 0;
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> s[i];
  while (m--) {
    int opt, ch;
    cin >> opt >> ch;
    if (opt == 0) {
      ans = 0;
      for (std::list<int>::iterator i = h.begin(); i != h.end(); ++i)
        if (s[r - *i] != ch)
          ++ans;
        else
          h.erase(i--);
      if (ch != s[0]) {
        h.push_back(r);
        ++ans;
      }
      t[r++] = ch;
    } else {
      bool flag = true;
      t[l] = ch;
      for (int i = l; i < r; ++i)
        if (t[i] == s[i - l]) {
          flag = false;
          break;
        }
      if (flag) {
        ++ans;
        h.push_front(l);
      }
      --l;
    }
    std::cout << ans << '\n';
  }
  return 0;
}