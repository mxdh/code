// AC
#include <iostream>

const int N = 20;
int f[N - 1], g[N - 1];

int main() {
    int a, n, m, x, b;
    std::cin >> a >> n >> m >> x;
    if (x == n) {
        std::cout << 0;
        return 0;
    }
    if (x < 3) {
        std::cout << a;
        return 0;
    }
    f[1] = 1;
    g[2] = 1;
    for (int i = 3; i < n; ++i) {
        f[i] = f[i - 2] + f[i - 1];
        g[i] = g[i - 2] + g[i - 1];
    }
    b = (m - (f[n - 1] + 1) * a) / (g[n - 1] + -1);
    std::cout << (f[x] + 1) * a + (g[x] - 1) * b;
    return 0;
}