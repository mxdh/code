// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int N = 50;
int ans, s[N + 1][N], ss[N], cnt[N + 1];
bool g[N][N], flag;

void dfs(int k) {
    if (!cnt[k]) {
        ans = max(ans, k);
        flag = false;
    }
    for (int i = 0; i < cnt[k]; ++i) {
        if (!flag) return;
        int u = s[k][i];
        if (ss[u] + k > ans && cnt[k] - i + k > ans) {
            cnt[k + 1] = 0;
            for (int j = i + 1; j < cnt[k]; ++j)
                if (g[u][s[k][j]]) s[k + 1][cnt[k + 1]++] = s[k][j];
            dfs(k + 1);
        }
    }
}

int main() {
    int n, u, v;
    scanf("%d", &n);
    while (scanf("%d%d", &u, &v) != EOF) {
        --u;
        --v;
        g[u][v] = g[v][u] = true;
    }
    for (int i = n; ~i; --i) {
        cnt[1] = 0;
        for (int j = i + 1; j < n; ++j)
            if (g[i][j]) s[1][cnt[1]++] = j;
        flag = true;
        dfs(1);
        ss[i] = ans;
    }
    printf("%d", ans);
    return 0;
}