// AC
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, cnt1 = 0, cnt2 = 0;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a) {
            if (a < 0) ++cnt1;
            ans += abs(a) - 1;
        } else {
            ++ans;
            ++cnt2;
        }
    }
    if ((cnt1 & 1) && !cnt2) ans += 2;
    cout << ans << endl;
    return 0;
}