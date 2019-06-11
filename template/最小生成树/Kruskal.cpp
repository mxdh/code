#include <cstdio>
//#include <cmath>
#include <algorithm>

using std::sort;

const int N = 1000, M = 10000;

struct Edge
{
	int x, y, l; //double l;
} e[M];
int fa[N], ans; //double ans;

bool cmp(Edge &a, Edge &b)
{
	return a.l < b.l;
}

int get_fa(int k)
{
	return fa[k] == k ? k : fa[k] = get_fa(fa[k]);
}

int main()
{
	int m, n, k, cnt;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].l);
		e[i].x--;
		e[i].y--;
	}
	/*m=0;
	for (int i=0;i<n;i++) {
		scanf("%d%d",&x[i],&y[i]);
		for (int j=0;j<i;j++) {
			int t1=x[i]-x[j],t2=y[i]-y[j];
			e[m].x=i; e[m].y=j; e[m++].l=sqrt(t1*t1+t2*t2);
		}
	}*/
	sort(e, e + m, cmp);
	for (int i = 0; i < n; i++)
		fa[i] = i;
	cnt = n - k;
	for (int i = 0; i < m && cnt; i++)
	{
		int x = get_fa(e[i].x), y = get_fa(e[i].y);
		if (x != y)
		{
			fa[x] = y;
			ans += e[i].l;
			cnt--;
		}
	}
	if (cnt)
		printf("No Answer");
	else
		printf("%d", ans);
	return 0;
}
