#include <bits/stdc++.h>

using namespace std;

const int N=500;
char s[N][N+1];

int main() {
    int n,m;
    bool flag=false;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i) scanf("%s",s[i]);
    for (int i=1;i<n-1;++i)
    {
        for (int j=1;j<m-1;++j)
            if (s[i][j]=='*'&&s[i-1][j]=='*'&&s[i+1][j]=='*'&&s[i][j-1]=='*'&&s[i][j+1]=='*') {
                flag=true;
                s[i][j]='.';
                for (int k=i-1;~k&&s[k][j]=='*';--k) s[k][j]='.';
                for (int k=i+1;k<n&&s[k][j]=='*';++k) s[k][j]='.';
                for (int k=j-1;~k&&s[i][k]=='*';--k) s[i][k]='.';
                for (int k=j+1;k<m&&s[i][k]=='*';++k) s[i][k]='.';
                break;
            }
        if (flag) break;
    }
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (s[i][j]=='*') flag=false;
    puts(flag?"YES":"NO");
    return 0;
}