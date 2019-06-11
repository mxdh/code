#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
struct node {
    int x, y, id;
} a[N], b[N];
vector<int> v1, v2;
bool cmp1(node a, node b) { return a.y > b.y; }
bool cmp2(node a, node b) { return a.y < b.y; }
int main() {
    int n, cnt1 = 0, cnt2 = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x < y)
            a[cnt1++] = {x, y, i};
        else
            b[cnt2++] = {x, y, i};
    }
    sort(a, a + cnt1, cmp1);
    sort(b, b + cnt2, cmp2);
    if (cnt1 > cnt2) {
        cout << cnt1 << '\n';
        for (int i = 0; i < cnt1; ++i) cout << a[i].id << ' ';
    } else {
        cout << cnt2 << '\n';
        for (int i = 0; i < cnt2; ++i) cout << b[i].id << ' ';
    }
    return 0;
}