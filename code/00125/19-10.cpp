// AC
#include <algorithm>
#include <iostream>
#include <string>

using std::cin;
using std::string;

const int N = 20;
string s[N];

inline bool cmp(const string &a, const string &b) { return a + b > b + a; }

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    sort(s, s + n, cmp);
    for (int i = 0; i < n; ++i) std::cout << s[i];
    return 0;
}