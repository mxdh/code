// AC
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int a, b, c;
    long long ans = 0;
    scanf("%d%d%d", &a, &b, &c);
    ans = (long long)(min(a, b) + c) << 1;
    if (a != b) ++ans;
    printf("%lld", ans);
    return 0;
}