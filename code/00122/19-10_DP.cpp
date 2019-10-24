// AC
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

const int N = 50;
int matrix[N + 1][N + 1], f[N + 1][N + 1];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> matrix[i][j];
    for (int i = 1; i < n + m; ++i)
        for (int j = min(i, n); j; --j)
            for (int k = min(i, n); k; --k) {
                f[j][k] = max(max(f[j][k], f[j - 1][k - 1]),
                              max(f[j - 1][k], f[j][k - 1])) +
                          matrix[j][i - j + 1];
                f[j][k] += !(j == k) * matrix[k][i - k + 1];
            }
    cout << f[n][n] << endl;
    return 0;
}