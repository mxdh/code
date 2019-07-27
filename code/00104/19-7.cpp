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
    int q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        int val;
        scanf("%d", &val);
        add(i, val);
    }
    for (int i = 0; i < q; ++i) {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if (op == 1)
            add(a, b);
        else
            printf("%d\n", b >= a ? query(b) - query(a - 1) : 0);
    }
    return 0;
}