#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    if (n&1) putchar('0');
    else printf("%d",1<<(n>>1));
    return 0;
}