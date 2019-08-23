#include <bits/stdc++.h>

using namespace std;

const int N = 50;
int a[N][N], b[N][N], qx[N * N], qy[N * N], cnt;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m - 1; ++j)
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) {
                qx[cnt] = i + 1;
                qy[cnt] = j + 1;
                ++cnt;
                b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
            }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] != b[i][j]) {
                cout << -1;
                return 0;
            }
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i) cout << qx[i] << ' ' << qy[i] << endl;
    return 0;
}