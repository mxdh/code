// AC
#include <bits/stdc++.h>

using namespace std;

const int N = 200000;
long long a[N], b[N];

int main() {
    int n, m, k;
    long long ta, tb, ans = 0;
    cin >> n >> m >> ta >> tb >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    for (int i = 0, j = 0; i <= k; ++i) {
        if (i == n) {
            ans = -1;
            break;
        }
        while (j < m && a[i] + ta > b[j]) ++j;
        int tmp = j + k - i;
        if (tmp >= m) {
            ans = -1;
            break;
        }
        ans = max(ans, b[tmp] + tb);
    }
    cout << ans << endl;
    return 0;
}