// AC
#include <cstdio>
#include <cstring>

const int N = 100000;
int f[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n) {
        int now = 0;
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; ++i) {
            int l, r;
            scanf("%d%d", &l, &r);
            ++f[l - 1];
            if (r < n) --f[r];
        }
        for (int i = 0; i < n; ++i) {
            now += f[i];
            printf("%d ", now);
        }
        putchar('\n');
    }
    return 0;
}