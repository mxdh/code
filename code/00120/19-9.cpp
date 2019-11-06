// AC
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef long long LL;

const int N = 100000;
int a[N + 1];
LL sum[N + 1], tr[N << 2], tag[N << 2];

void push_down(int k, int len) {
    tr[k << 1] += tag[k] * (len - (len >> 1));
    tag[k << 1] += tag[k];
    tr[(k << 1) | 1] += tag[k] * (len >> 1);
    tag[(k << 1) | 1] += tag[k];
    tag[k] = 0;
}

void push_up(int k) { tr[k] = tr[k << 1] + tr[(k << 1) | 1]; }

void modify(int k, int l, int r, int l_, int r_, LL val) {
    if (l >= l_ && r <= r_) {
        tr[k] += val * (r - l + 1);
        tag[k] += val;
        return;
    }
    int mid = (l + r) >> 1;
    push_down(k, r - l + 1);
    if (l_ <= mid) modify(k << 1, l, mid, l_, r_, val);
    if (mid < r_) modify((k << 1) | 1, mid + 1, r, l_, r_, val);
    push_up(k);
}

LL query(int k, int l, int r, int l_, int r_) {
    if (l >= l_ && r <= r_) return tr[k];
    int mid = (l + r) >> 1;
    LL ret = 0;
    push_down(k, r - l + 1);
    if (l_ <= mid) ret += query(k << 1, l, mid, l_, r_);
    if (mid < r_) ret += query((k << 1) | 1, mid + 1, r, l_, r_);
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        modify(1, 1, n, i, i, sum[i]);
    }
    for (int i = 0; i < m; ++i) {
        string opt;
        int k;
        cin >> opt >> k;
        if (opt == "Query")
            cout << query(1, 1, n, 1, k) << endl;
        else {
            int val;
            cin >> val;
            modify(1, 1, n, k, n, val - a[k]);
            a[k] = val;
        }
    }
    return 0;
}