#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, e, tmp1, ans = 0;
        cin >> a >> b >> c >> d >> e;
        a /= 2;
        if (d < e) {
            swap(d, e);
            swap(b, c);
        }
        tmp1 = min(a, b);
        ans += tmp1 * d;
        a -= tmp1;
        ans += min(a, c) * e;
        cout << ans << endl;
    }
    return 0;
}