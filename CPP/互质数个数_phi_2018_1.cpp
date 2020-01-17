//计蒜客
#include <cmath>
#include <cstdio>

using namespace std;

int p[5000], t, n;
bool ip[10000000];

void sieve_Euler(int n) {
    for (int i = 2; i < n; i++) {
        if (!ip[i]) p[t++] = i;
        for (int j = 0; j < t && i * p[j] <= n; j++) {
            ip[i * p[j]] = true;
            if (!(i % p[j])) break;
        }
    }
}

int phi(int n) {
    int y = n;
    sieve_Euler(sqrt(n));
    for (int i = 0; i < t; i++)
        if (!(n % p[i])) {
            y -= y / p[i];
            while (!(n % p[i])) n /= p[i];
        }
    if (n > 1) y -= y / n;
    return y;
}

int main() {
    scanf("%d", &n);
    printf("%d", phi(n));
}
