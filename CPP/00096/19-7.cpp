#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int a[N], ans[N];

int main() {
    int n, cnt = 0, sum = 0, ssum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        ssum += a[i];
    }
    sum += a[0];
    ans[cnt++] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[0] >= (a[i] << 1)) {
            sum += a[i];
            ans[cnt++] = i;
        }
        if (sum > (ssum >> 1)) {
            printf("%d\n", cnt);
            for (int j = 0; j < cnt; ++j) printf("%d ", ans[j] + 1);
            return 0;
        }
    }
    putchar('0');
    return 0;
}