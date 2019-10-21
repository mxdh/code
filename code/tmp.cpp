#include <bits/stdc++.h>
using namespace std;

int main() {
    for(int i=1;i<=10;i++)
        cout<<i<<" \n"[i==10];
    for(int i=1;i<=10;i++)
        printf("%d%c",i," \n"[i==10]);
    return 0;
}