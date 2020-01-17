// AC
#include <bits/stdc++.h>

using namespace std;

const int N = 100, M = 100, MAX = 200;
int a[N], b[M];
bool vis[MAX + 1];

int main() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        vis[a[i]] = true;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        vis[b[i]] = true;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i] + b[j] > MAX || !vis[a[i] + b[j]]) {
                cout << a[i] << ' ' << b[j] << endl;
                return 0;
            }
    return 0;
}