#include <bits/stdc++.h>

using namespace std;

const int N = 300000, P = 998244353;
struct Node {
    int a, b;
} node[N];
int n, f[N + 1];

bool cmp00(const Node &a, const Node &b) { return a.a < b.a; }

bool cmp01(const Node &a, const Node &b) { return a.b < b.b; }

bool cmp02(const Node &a, const Node &b) {
    return a.a == b.a ? a.b < b.b : a.a < b.a;
}

bool cmp10(const Node &a, const Node &b) { return a.a == b.a; }

bool cmp11(const Node &a, const Node &b) { return a.b == b.b; }

bool cmp12(const Node &a, const Node &b) { return a.a == b.a && a.b == b.b; }

int calc(bool (*cmp)(const Node &, const Node &)) {
    int ret = 1, tmp = 0;
    for (int i = 0; i < n; ++i)
        if (!i || cmp(node[i - 1], node[i]))
            ++tmp;
        else {
            ret = (long long)ret * f[tmp] % P;
            tmp = 1;
        }
    ret = (long long)ret * f[tmp] % P;
    return ret;
}

int main() {
    int tmp = 0;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; ++i) f[i] = (long long)f[i - 1] * i % P;
    for (int i = 0; i < n; ++i) cin >> node[i].a >> node[i].b;
    sort(node, node + n, cmp00);
    tmp = (tmp + calc(cmp10)) % P;
    sort(node, node + n, cmp01);
    tmp = (tmp + calc(cmp11)) % P;
    sort(node, node + n, cmp02);
    bool flag = true;
    for (int i = 1; i < n; ++i)
        if (node[i - 1].b > node[i].b) {
            flag = false;
            break;
        }
    if (flag) tmp = ((tmp - calc(cmp12)) % P + P) % P;
    cout << ((f[n] - tmp) % P + P) % P << endl;
    return 0;
}