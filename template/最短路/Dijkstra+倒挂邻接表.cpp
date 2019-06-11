#define N 10000
#define M 100000

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Edge{
	int len,p,next;
} edge[M+1];
int head[N],d[N+1],tot;
bool vis[N];

void add_edge(int u,int v,int len) {
	edge[++tot].next=head[u]; edge[tot].p=v; edge[tot].len=len;
	head[u]=tot;
}

int main() {
	int n,m,u,v,len;
	for (scanf("%d%d",&n,&m);m;m--) {
		scanf("%d%d%d",&u,&v,&len);
		u--; v--;
		add_edge(u,v,len); add_edge(v,u,len);
	}
	memset(d,127,sizeof d); d[0]=0;
	for (int i=0;i<n;i++) {
		int k=-1;
		for (int j=0;j<n;j++)
			if (!vis[j]&&(k<0||d[j]<d[k])) k=j;
		vis[k]=true;
		int p=head[k];
		while (p) {
			d[edge[p].p]=min(d[edge[p].p],d[k]+edge[p].len);
			p=edge[p].next;
		}
	}
	for (int i=1;i<n;i++) 
		if (d[i]==d[n]) printf("-1\n");
		else printf("%d\n",d[i]);
	return 0;
}
