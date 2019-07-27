// AC
#include <cstdio>

const int N = 500000;
int tr[N + 1], n;

inline int lowbit(int num) { return num & (-num); }

void add(int k, int val) {
    for (; k <= n; k += lowbit(k)) tr[k] += val;
}

int query(int k) {
    int ret = 0;
    for (; k; k -= lowbit(k)) ret += tr[k];
    return ret;
}

int main() {
    int q, last = 0;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        int val;
        scanf("%d", &val);
        add(i, val - last);
        last = val;
    }
    for (int i = 0; i < q; ++i) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int l, r, val;
            scanf("%d%d%d", &l, &r, &val);
            add(l, val);
            if (r < n) add(r + 1, -val);
        } else {
            int k;
            scanf("%d", &k);
            printf("%d\n", query(k));
        }
    }
    return 0;
}