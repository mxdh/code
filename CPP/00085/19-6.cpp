// AC
#include <algorithm>
#include <cctype>
#include <cstdio>

using std::sort;

const int N = 1000000;
int a[N + 1], r1[N + 1], r2[N + 1], ans3[N];

inline char GetChar() {
    static const int SIZE = 1 << 20;
    static char buf[SIZE], *s = buf, *t = buf;
    return (s == t) && (t = (s = buf) + fread(buf, 1, SIZE, stdin), s == t)
               ? EOF
               : *s++;
}

#define getchar GetChar

template <typename T>
inline void GetNum(T &num) {
    char ch = getchar();
    num = 0;
    for (; !isdigit(ch); ch = getchar())
        ;
    for (; isdigit(ch); ch = getchar())
        num = (num << 3) + (num << 1) + (ch ^ 48);
}

inline bool cmp(int x, int y) { return a[x] > a[y]; }

int main() {
    int n, v, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    GetNum(n);
    GetNum(v);
    for (int i = 0; i < n; ++i) {
        int w;
        GetNum(w);
        GetNum(a[i]);
        if (w == 1)
            r1[cnt1++] = i;
        else
            r2[cnt2++] = i;
    }
    sort(r1, r1 + cnt1, cmp);
    sort(r2, r2 + cnt2, cmp);
    int k1 = 0, k2 = 0;
    long long ans = 0;
    if (v & 1) {
        --v;
        if (cnt1) {
            ++k1;
            ans += a[r1[0]];
            ans3[cnt3++] = r1[0];
        }
    }
    if ((cnt1 - k1) & 1) {
        r1[cnt1++] = n;
        a[n++] = 0;
    }
    while (v) {
        if (k1 >= cnt1 - 1 && k2 >= cnt2) break;
        if (k2 >= cnt2 ||
            (k1 < cnt1 - 1 && a[r1[k1]] + a[r1[k1 + 1]] >= a[r2[k2]])) {
            ans += a[r1[k1]] + a[r1[k1 + 1]];
            ans3[cnt3++] = r1[k1];
            if (a[r1[k1 + 1]]) ans3[cnt3++] = r1[k1 + 1];
            k1 += 2;
        } else {
            ans3[cnt3++] = r2[k2];
            ans += a[r2[k2]];
            ++k2;
        }
        v -= 2;
    }
    printf("%lld\n", ans);
    for (int i = 0; i < cnt3; ++i) printf("%d ", ans3[i] + 1);
    return 0;
}
