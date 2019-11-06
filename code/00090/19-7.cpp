// AC
#include <algorithm>
#include <cstdio>

using std::sort;

const int N = 100;
struct Node {
    int x, y;
    bool operator<(const Node &b) {
        if (x == b.x) return y > b.y;
        return x > b.x;
    }
} node[N];
bool flag[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &node[i].x, &node[i].y);
    sort(node, node + n);
    int tmp = -1;
    bool b = false;
    for (int i = 0; i < n; ++i)
        if (node[i].y > tmp) {
            flag[i] = true;
            tmp = node[i].y;
        }
    for (int i = n - 1; ~i; --i)
        if (flag[i]) {
            if (!b) {
                b = true;
                printf("(%d,%d)", node[i].x, node[i].y);
            } else
                printf(",(%d,%d)", node[i].x, node[i].y);
        }
    return 0;
}