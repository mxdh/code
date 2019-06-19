#include <cstdio>

const int LEN = 1000000;
char s1[LEN + 1], s2[LEN + 1];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        bool flag = true;
        scanf("%s%s", s1, s2);
        int k = 0;
        for (int j = 0; s1[j]; ++j) {
            if (s1[j] != s2[k]) {
                flag = false;
                break;
            }
            if (s1[j] != s1[j + 1])
                while (s1[j] == s2[k]) ++k;
            else
                ++k;
        }
        if (s2[k]) flag = false;
        puts(flag ? "YES" : "NO");
    }
    return 0;
}