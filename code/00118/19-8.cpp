#include <bits/stdc++.h>

using namespace std;

const int N = 500000;
int a[N], sum[261][N];

signed main() {
    int n, k = 260;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            a[x] += y;
            for (int j = 1; j <= k; ++j) sum[j][x % j] += y;
        } else {
            if (x <= k)
                cout << sum[x][y] << endl;
            else {
                int ans = 0;
                for (; y <= 500000; y += x) ans += a[y];
                cout << ans << endl;
            }
        }
    }
    return 0;
}
