// AC
#include <bits/stdc++.h>

using namespace std;

const int N = 100000, M = 63;
int b[128], f[128][128], e[128][128], tmp[N];
long long a[N];
vector<int> g[N];

signed main() {
    int n, ans = 1E8, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 0; j < M; ++j) {
        int tot = 0;
        for (int i = 0; i < n; i++)
            if (a[i] & (1ll << j)) tmp[tot++] = i;
        if (tot >= 3) {
            cout << 3 << endl;
            return 0;
        }
        if (tot == 2) {
            g[tmp[0]].push_back(tmp[1]);
            g[tmp[1]].push_back(tmp[0]);
            b[cnt++] = tmp[0];
            b[cnt++] = tmp[1];
        }
    }
    sort(b, b + cnt);
    cnt = unique(b, b + cnt) - b;
    memset(e, 31, sizeof e);
    memset(f, 31, sizeof f);
    for (int x = 0; x < n; ++x)
        for (int i = 0; i < (int)g[x].size(); ++i) {
            int y = g[x][i];
            int k1 = lower_bound(b, b + cnt, x) - b;
            int k2 = lower_bound(b, b + cnt, y) - b;
            f[k1][k2] = f[k2][k1] = e[k1][k2] = e[k2][k1] = 1;
        }
    for (int i = 0; i < cnt; ++i) f[i][i] = e[i][i] = 0;
    for (int k = 0; k < cnt; ++k) {
        for (int i = 0; i < k; ++i)
            for (int j = i + 1; j < k; ++j)
                ans = min(ans, f[i][j] + e[j][k] + e[k][i]);
        for (int i = 0; i < cnt; ++i)
            for (int j = 0; j < cnt; ++j)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    }
    cout << (ans > 100000 ? -1 : ans) << endl;
    return 0;
}