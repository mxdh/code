// AC
#include <cstdio>

const int N = 14;
int a[N], n;
bool flag;

void dfs(int k, bool s, int val) {
    if (!val && s) {
        flag = true;
        return;
    }
    if (k == n) return;
    if (!flag) dfs(k + 1, s, val);
    if (!flag) dfs(k + 1, true, val ^ a[k]);
}

int main() {
    int q = 10;
    while (q--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", a + i);
        flag = false;
        dfs(0, 0, 0);
        puts(flag ? "NO" : "YES");
    }
    return 0;
}