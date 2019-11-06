// AC
#include <algorithm>
#include <cstdio>

using std::min;

const int A = 100;
int ht[A + 1];

int main() {
    int n, m, sum = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int a, ans = 0;
        scanf("%d", &a);
        sum += a;
        int tmp = sum;
        for (int j = 100; tmp > m; --j) {
            int s = min(ht[j], (tmp - m) / j + (bool)((tmp - m) % j));
            tmp -= j * s;
            ans += s;
        }
        ++ht[a];
        printf("%d ", ans);
    }
}