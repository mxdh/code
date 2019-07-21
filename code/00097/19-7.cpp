#include <bits/stdc++.h>

using namespace std;

int const LEN = 1000000;
long long f[3];
char s[LEN + 1];
int main() {
    gets(s);
    for (int i = 0; s[i]; ++i) {
        if (s[i] == 'o')
            f[1] += f[0];
        else if (i && s[i - 1] == 'v') {
            ++f[0];
            f[2] += f[1];
        }
    }
    cout << f[2] << endl;
    return 0;
}