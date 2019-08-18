#include <bits/stdc++.h>

using namespace std;

int const N = 100000;
int a[N << 1];
int main() {
    int n;
    cin >> n;
    if (!(n & 1))
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i)
            if (i & 1) {
                a[i] = (i + 1) * 2;
                a[i + n] = i * 2 + 1;
            } else {
                a[i] = i * 2 + 1;
                a[i + n] = (i + 1) * 2;
            }
        for (int i = 0; i < n << 1; i++) cout << a[i] << ' ';
    }
    return 0;
}