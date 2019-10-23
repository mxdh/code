#include <iostream>

const int N=9;
int matrix[N][N];

int main() {
    int n,nStep;
    std::cin>>n;
    while (true) {
        int x,y,val;
        std::cin>>x>>y>>val;
        if (!(x||y||val)) break;
        matrix[x-1][y-1]=val;
    }
    nStep=n*2-1;
    for (int i=0;i<nStep;++i)
        for (int j=0;j<n;++j)

    return 0;
}