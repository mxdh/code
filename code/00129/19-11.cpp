// AC
#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::string str;
  int cnt = 0, ans = -1;
  std::cin >> str;
  for (std::string::iterator i = str.begin(); i != str.end(); ++i)
    if (*i == '0')
      ans = std::max(ans, ++cnt);
    else if (cnt > 0)
      --cnt;
  std::cout << ans;
  return 0;
}