#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int pow(int a, int b) {
    int ret = 1 % P;
    while (b) {
        if (b & 1) ret = (long long)ret * a % P;
        a = (long long)a * a % P;
        b >>= 1;
    }
    return ret;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", pow(2, n + m));
    return 0;
}