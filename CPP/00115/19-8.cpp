#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200000;
ll f[N][2];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;
        memset(f, 63, sizeof f);
        f[0][0] = a + 2 * b;
        f[0][1] = 2 * a + 3 * b;
        for (int i = 1; i < n; ++i)
            if (s[i] == '0') {
                f[i][0] = min(f[i - 1][0] + a + b, f[i - 1][1] + 2 * a + b);
                f[i][1] =
                    min(f[i - 1][0] + 2 * a + 2 * b, f[i - 1][1] + a + 2 * b);
            } else
                f[i][1] = f[i - 1][1] + a + 2 * b;
        cout << f[n - 1][0] << endl;
    }
    return 0;
}