#define N 2000 //E*2

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int q[N],g[N][N],dist[N+1];
bool v[N];

int main() {
	int n,e,x,y,d,l,r;
	memset(dist,127,sizeof dist); memset(g,127,sizeof g);
	for (scanf("%d%d",&n,&e);e;e--) {
		scanf("%d%d%d",&x,&y,&d);
		x--; y--;
		g[x][y]=g[y][x]=min(d,g[x][y]);
	}
	scanf("%d%d",&x,&y);
	x--; y--;
	dist[x]=0; l=0; r=1; q[0]=x; //v[x]=true; ø…“‘≤ª–¥ 
	while (v[q[l]]) {
		v[q[l]]=false;
		for (int i=0;i<n;i++)
			if (dist[q[l]]+g[q[l]][i]<dist[i]) {
			  	dist[i]=dist[q[l]]+g[q[l]][i];
			  	if (!v[i]) {
			  		q[r]=i;
			  		r=(r+1)%N;
					v[i]=true;
				}
			}
		l=(l+1)%N;
	}
	if (dist[y]==dist[n]) printf("-1\n");
	else printf("%d\n",dist[y]);
	return 0; 
}
