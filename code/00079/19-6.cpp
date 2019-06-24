// AC
#include <algorithm>
#include <cstdio>

using std::sort;

int main() {
    int a[3], b, ans = 0;
    scanf("%d%d%d%d", a, a + 1, a + 2, &b);
    sort(a, a + 3);
    if (a[1] - a[0] < b) ans += b - (a[1] - a[0]);
    if (a[2] - a[1] < b) ans += b - (a[2] - a[1]);
    printf("%d", ans);
    return 0;
}