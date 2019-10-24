// AC
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

const int N = 9;
int matrix[N + 1][N + 1], f[N + 1][N + 1];

int main() {
    int n;
    cin >> n;
    while (true) {
        int x, y, val;
        cin >> x >> y >> val;
        if (!(x || y || val)) break;
        matrix[x][y] = val;
    }
    for (int i = 2; i <= n * 2; ++i)
        for (int j = min(i - 1, n); j; --j)
            for (int k = min(i - 1, n); k; --k) {
                f[j][k] = max(max(f[j][k], f[j - 1][k - 1]),
                              max(f[j - 1][k], f[j][k - 1])) +
                          matrix[j][i - j];
                f[j][k] += !(j == k) * matrix[k][i - k];
            }
    cout << f[n][n] << endl;
    return 0;
}