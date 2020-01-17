#include <bits/stdc++.h>
using namespace std;
const int N = 300000 + 5;
int b[N], a[N], c[N];
struct node {
    int x, y;
};
queue<node> que;
int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = a[i];
        b[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] != i) {
            int x = b[i];
            if (2 * abs(x - i) >= n) {
                swap(a[i], a[x]);
                swap(b[a[i]], b[a[x]]);
                que.push((node){i, x});
                ans++;
            } else {
                int y = 1;
                if (2 * abs(x - y) >= n && 2 * abs(i - y) >= n) {
                    swap(a[i], a[y]);
                    swap(b[a[i]], b[a[y]]);
                    que.push((node){i, y});
                    swap(a[x], a[y]);
                    swap(b[a[x]], b[a[y]]);
                    que.push((node){x, y});
                    swap(a[i], a[y]);
                    swap(b[a[i]], b[a[y]]);
                    que.push((node){i, y});
                    ans += 3;
                } else {
                    y = n;
                    if (2 * abs(x - y) >= n && 2 * abs(i - y) >= n) {
                        swap(a[i], a[y]);
                        swap(b[a[i]], b[a[y]]);
                        que.push((node){i, y});
                        swap(a[x], a[y]);
                        swap(b[a[x]], b[a[y]]);
                        que.push((node){x, y});
                        swap(a[i], a[y]);
                        swap(b[a[i]], b[a[y]]);
                        que.push((node){i, y});
                        ans += 3;
                    } else {
                        if (x > i) swap(x, i);
                        swap(a[i], a[1]);
                        swap(b[a[i]], b[a[1]]);
                        que.push((node){i, 1});
                        swap(a[x], a[n]);
                        swap(b[a[x]], b[a[n]]);
                        que.push((node){x, n});
                        swap(a[1], a[n]);
                        swap(b[a[1]], b[a[n]]);
                        que.push((node){1, n});
                        swap(a[i], a[1]);
                        swap(b[a[i]], b[a[1]]);
                        que.push((node){i, 1});
                        swap(a[x], a[n]);
                        swap(b[a[x]], b[a[n]]);
                        que.push((node){x, n});
                        ans += 5;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    while (!que.empty()) {
        printf("%d %d\n", que.front().x, que.front().y);
        swap(c[que.front().x], c[que.front().y]);
        for (int i = 1; i <= n; ++i) printf("%d ", c[i]);
        putchar('\n');
        que.pop();
    }
    return 0;
}