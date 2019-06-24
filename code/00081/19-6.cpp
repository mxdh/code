// AC
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using std::sort;

const int N = 100;
int a[N], b[N];

bool cmp(int a, int b) { return a > b; }

int main() {
    int n, m, sum = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        sum += a[i];
        int tmp = sum, j;
        memcpy(b, a, i * sizeof a[0]);
        sort(b, b + i, cmp);
        for (j = 0; tmp > m; ++j) tmp -= b[j];
        printf("%d ", j);
    }
    return 0;
}