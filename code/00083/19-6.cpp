#include <algorithm>
#include <cstdio>
#include <map>

using std::map;
using std::sort;

const int N = 200000;
int a[N], r[N], cnt[N];

bool cmp(int x, int y) { return a[x] < a[y]; }

int main() {
    int n, k = 0;
    map<int, int> h;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        r[i] = i;
    }
    sort(r, r + n, cmp);
    for (int i = 1; i < n; ++i) {
        int tmp = a[r[i]] - a[r[i - 1]];
        if (!h.count(tmp)) h[tmp] = k++;
        ++cnt[h[tmp]];
        // printf("%d %d\n", tmp, h[tmp]);
    }

    if (k <= 3) {
        int ss = 0;
        for (int i = 1; i < k; ++i)
            if (cnt[i] > cnt[ss]) ss = i;
        if (n>4)
        for (int i = 1; i < n - 1; ++i)
            if (h[a[r[i]] - a[r[i - 1]]] != ss &&
                h[a[r[i + 1]] - a[r[i]]] != ss) {
                if (((a[r[i]] - a[r[i - 1]] != a[r[i + 1]] - a[r[i]] &&
                      k == 3) ||
                     (a[r[i]] - a[r[i - 1]] == a[r[i + 1]] - a[r[i]] &&
                      k == 2)) &&
                    (h.count(a[r[i + 1]] - a[r[i - 1]])) &&
                    (h[a[r[i + 1]] - a[r[i - 1]]] == ss))
                    printf("%d", r[i] + 1);
                else
                    puts("-1");
                return 0;
            }
        else {
            
        }
        if (k == 2 && h[a[r[1]] - a[r[0]]] != ss) {
            printf("%d", r[0] + 1);
            // printf("%d\n", h[a[r[1] - a[r[0]]]]);
            // puts("%%");
            return 0;
        }
        if (k == 2 && h[a[r[n - 1]] - a[r[n - 2]]] != ss) {
            printf("%d", r[n - 1] + 1);
            // puts("&&");
            return 0;
        }
    }
    if (k == 1) {
        printf("%d", r[0] + 1);
        return 0;
    }
    puts("-1");
    return 0;
}