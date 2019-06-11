#define N 100 

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int g[N][N];

void add(int x,int y,int l) {
	if (x>=0&&y>=0) {
		g[x][y]=g[y][x]=l;
	}
}

int main() {
	int n,x,y;
	memset(g,63,sizeof g);
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&x,&y);
		add(i,x-1,1); add(i,y-1,1);
		g[i][i]=0;
	}
	for (int k=0;k<n;k++)
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for (int i=0;i<n;i++) 
		for (int j=0;j<n;j++) printf("%d %d %d\n",i,j,g[i][j]);
	return 0;
}
