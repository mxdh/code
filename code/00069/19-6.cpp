// AC
#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
int a[N], b[N];
struct node {
    int x, y;
};
queue<node> q;
int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        b[a[i]] = i;
    }
    for (int i = 0; i < n; i++)
        if (b[i] != i) {
            int x = b[i];
            if (2 * abs(x - i) >= n) {
                swap(a[i], a[x]);
                swap(b[a[i]], b[a[x]]);
                q.push((node){i, x});
                ++ans;
            } else {
                int y = -1;
                if (2 * abs(x - 0) >= n && 2 * abs(i - 0) >= n)
                    y = 0;
                else if (2 * abs(x - (n - 1)) >= n && 2 * abs(i - (n - 1)) >= n)
                    y = n - 1;
                if (~y) {
                    swap(a[i], a[y]);
                    swap(b[a[i]], b[a[y]]);
                    q.push((node){i, y});
                    swap(a[x], a[y]);
                    swap(b[a[x]], b[a[y]]);
                    q.push((node){x, y});
                    swap(a[i], a[y]);
                    swap(b[a[i]], b[a[y]]);
                    q.push((node){i, y});
                    ans += 3;
                } else {
                    y = i;
                    if (x > y) swap(x, y);
                    swap(a[y], a[0]);
                    swap(b[a[y]], b[a[0]]);
                    q.push((node){y, 0});
                    swap(a[x], a[n - 1]);
                    swap(b[a[x]], b[a[n - 1]]);
                    q.push((node){x, n - 1});
                    swap(a[0], a[n - 1]);
                    swap(b[a[0]], b[a[n - 1]]);
                    q.push((node){0, n - 1});
                    swap(a[y], a[0]);
                    swap(b[a[y]], b[a[0]]);
                    q.push((node){y, 0});
                    swap(a[x], a[n - 1]);
                    swap(b[a[x]], b[a[n - 1]]);
                    q.push((node){x, n - 1});
                    ans += 5;
                }
            }
        }
    cout << ans << '\n';
    while (!q.empty()) {
        cout << q.front().x + 1 << ' ' << q.front().y + 1 << '\n';
        q.pop();
    }
    cout << endl;
    return 0;
}