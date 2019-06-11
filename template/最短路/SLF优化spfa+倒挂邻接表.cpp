//可能卡到O(2^n)
#define N 10000
#define M 100000

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Edge
{
	int len, p, next;
} edge[M + 1];
int q[N], head[N], d[N + 1], tot;
bool vis[N];

void add_edge(int u, int v, int len)
{
	edge[++tot].next = head[u];
	edge[tot].p = v;
	edge[tot].len = len;
	head[u] = tot;
}

int main()
{
	int n, m, u, v, len, s, t, l, r;
	memset(d, 127, sizeof d);
	for (scanf("%d%d", &n, &m); m; m--)
	{
		scanf("%d%d%d", &u, &v, &len);
		u--;
		v--;
		add_edge(u, v, len);
	}
	scanf("%d%d", &s, &t);
	s--;
	t--;
	d[s] = 0;
	l = 0;
	r = 1;
	q[0] = s;
	memset(vis, false, sizeof vis);
	vis[s] = true;
	while (vis[q[l]])
	{
		int p1 = q[l], p2 = head[q[l]];
		vis[p1] = false;
		while (p2)
		{
			int tmp = edge[p2].p;
			if (d[p1] + edge[p2].len < d[tmp])
			{
				d[tmp] = d[p1] + edge[p2].len;
				if (!vis[tmp])
				{
					if (l == r - 1 || d[tmp] > d[q[(l + 1) % N]])
					{
						q[r] = tmp;
						r = (r + 1) % N;
					}
					else
					{
						q[l] = tmp;
						l = (l - 1 + N) % N;
					}
					vis[tmp] = true;
				}
			}
			p2 = edge[p2].next;
		}
		l = (l + 1) % N;
	}
	if (d[t] == d[n])
		printf("No Solution!\n");
	else
		printf("%d\n", d[t]);
	return 0;
}
