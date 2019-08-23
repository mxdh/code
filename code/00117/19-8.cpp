#include <bits/stdc++.h>

using namespace std;

int main() {
    int s = (1 << 7) - 1;
    cout << "? ";
    for (int i = 1; i < 100; ++i) cout << ((s << 7) | i) << " ";
    cout << ((s << 7) | 100) << endl;
    int ans1;
    cin >> ans1;
    ans1 >>= 7;
    ans1 ^= s;
    cout << "? ";
    for (int i = 1; i < 100; ++i) cout << ((i << 7) | s) << " ";
    cout << ((100 << 7) | s) << endl;
    int ans2;
    cin >> ans2;
    ans2 &= s;
    ans2 ^= s;
    cout << "! " << ((ans1 << 7) | ans2) << endl;
    return 0;
}