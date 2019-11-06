// AC
#include <algorithm>
#include <cstdio>

using std::sort;

const int N = 1000;
struct Node {
    int s, t;
} node[N];

inline bool cmp(const Node &a, const Node &b) { return a.t < b.t; }

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &node[i].s, &node[i].t);
    sort(node, node + n, cmp);
    int tmp = 0;
    for (int i = 0; i < n; ++i)
        if (node[i].s >= tmp) {
            ++ans;
            tmp = node[i].t;
        }
    printf("%d", ans);
    return 0;
}