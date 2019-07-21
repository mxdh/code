#include <bits/stdc++.h>

using namespace std;

const int N = 1000, M = N * 3;
struct node {
    int u, v;
} ans[M];
bool isPrime[M + 1], flag[N];
int pri[M + 1], cnt;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= M; ++i) {
        if (!isPrime[i]) pri[cnt++] = i;
        for (int j = 0; j < cnt && i * pri[j] <= M; ++j) {
            isPrime[i * pri[j]] = true;
            if (!(i % pri[j])) break;
        }
    }
    for (int i = 0; i < n - 1; ++i) ans[i].u = i + 1, ans[i].v = i + 2;
    ans[n - 1].u = n;
    ans[n - 1].v = 1;
    int ss = n, k = 0;
    while (isPrime[ss]) {
        ans[ss].u = k + 1;
        ans[ss].v = k + 3;
        ++ss;
        flag[k] = flag[k + 2] = true;
        ++k;
        while (flag[k]) ++k;
    }
    printf("%d\n", ss);
    for (int i = 0; i < ss; i++) printf("%d %d\n", ans[i].u, ans[i].v);
    return 0;
}