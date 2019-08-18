#include <algorithm>
#include <cstdio>
#include <cstring>

using std::swap;

const int N = 100000;
struct Edge {
    int v, next;
} edge[(N - 1) << 1];
int a[N], b[N], tr[N << 2], lazy[N << 2], head[N], fa[N], dep[N], size[N],
    son[N], top[N], id[N], cnt, cnt1, n, p;

void AddEdge(int u, int v) {
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void AddUndiEdge(int u, int v) {
    AddEdge(u, v);
    AddEdge(v, u);
}

void dfs1(int k) {
    size[k] = 1;
    son[k] = -1;
    for (int i = head[k]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (v != fa[k]) {
            fa[v] = k;
            dep[v] = dep[k] + 1;
            dfs1(v);
            size[k] += size[v];
            if (son[k] == -1 || size[v] > size[son[k]]) son[k] = v;
        }
    }
}

void dfs2(int k) {
    id[k] = cnt1++;
    b[id[k]] = a[k];
    if (~son[k]) {
        top[son[k]] = top[k];
        dfs2(son[k]);
        for (int i = head[k]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (v != son[k] && v != fa[k]) {
                top[v] = v;
                dfs2(v);
            }
        }
    }
}

void pushup(int k) { tr[k] = (tr[k << 1] + tr[k << 1 | 1]) % p; }

void pushdown(int k, int len) {
    int lc = k << 1, rc = k << 1 | 1;
    tr[lc] = (tr[lc] + (long long)lazy[k] * (len - (len >> 1))) % p;
    tr[rc] = (tr[rc] + (long long)lazy[k] * (len >> 1)) % p;
    lazy[lc] = (lazy[lc] + lazy[k]) % p;
    lazy[rc] = (lazy[rc] + lazy[k]) % p;
    lazy[k] = 0;
}

void build(int k, int l, int r) {
    if (l == r) {
        tr[k] = b[l] % p;
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    pushup(k);
}

void update(int k, int l, int r, int l_, int r_, int val) {
    if (l >= l_ && r <= r_) {
        tr[k] = (tr[k] + (long long)(r - l + 1) * val) % p;
        lazy[k] = (lazy[k] + val) % p;
        return;
    }
    if (lazy[k]) pushdown(k, r - l + 1);
    int mid = (l + r) >> 1;
    if (l_ <= mid) update(k << 1, l, mid, l_, r_, val);
    if (r_ > mid) update(k << 1 | 1, mid + 1, r, l_, r_, val);
    pushup(k);
}

int query(int k, int l, int r, int l_, int r_) {
    if (l >= l_ && r <= r_) return tr[k];
    if (lazy[k]) pushdown(k, r - l + 1);
    int mid = (l + r) >> 1, ret = 0;
    if (l_ <= mid) ret += query(k << 1, l, mid, l_, r_);
    if (r_ > mid) ret += query(k << 1 | 1, mid + 1, r, l_, r_);
    return ret % p;
}

void UpdateTree(int k, int val) {
    update(1, 0, n - 1, id[k], id[k] + size[k] - 1, val % p);
}

int QueryTree(int k) { return query(1, 0, n - 1, id[k], id[k] + size[k] - 1); }

void UpdateRange(int x, int y, int val) {
    val %= p;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, 0, n - 1, id[top[x]], id[x], val);
        x = fa[top[x]];
    }
    if (dep[y] < dep[x]) swap(x, y);
    update(1, 0, n - 1, id[x], id[y], val);
}

int QueryRange(int x, int y) {
    int ret = 0;
    while (top[x] != top[y]) {
        // printf("%d %d %d %d\n", x, y, top[x], top[y]);
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ret = (ret + query(1, 0, n - 1, id[top[x]], id[x])) % p;
        x = fa[top[x]];
    }
    if (dep[y] < dep[x]) swap(x, y);
    return (ret + query(1, 0, n - 1, id[x], id[y])) % p;
}

int main() {
    int q, r;
    scanf("%d%d%d%d", &n, &q, &r, &p);
    --r;
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    memset(head, -1, sizeof head);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        AddUndiEdge(u - 1, v - 1);
    }
    fa[r] = -1;
    dfs1(r);
    top[r] = r;
    dfs2(r);
    build(1, 0, n - 1);
    // printf("%d\n", id[4]);
    // printf("#%d\n", QueryTree(4));
    for (int i = 0; i < q; ++i) {
        int op;
        scanf("%d", &op);
        switch (op) {
            int x, y, k, val;
            case 1:
                scanf("%d%d%d", &x, &y, &val);
                UpdateRange(x - 1, y - 1, val);
                break;
            case 2:
                scanf("%d%d", &x, &y);
                printf("%d\n", QueryRange(x - 1, y - 1));
                break;
            case 3:
                scanf("%d%d", &k, &val);
                UpdateTree(k - 1, val);
                break;
            case 4:
                scanf("%d", &k);
                printf("%d\n", QueryTree(k - 1));
        }
        // printf("#%d\n", query(1, 0, n - 1, id[2], id[2]));
    }
    // printf("%d\n", query(1, 0, n - 1, id[0], id[0]));
    // printf("%d\n", query(1, 0, n - 1, id[2], id[2]));
    // printf("%d %d %d %d %d %d\n", id[0], id[2], id[4], top[0], top[4],
    // son[0]);
    return 0;
}