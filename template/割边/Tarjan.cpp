void dfs(int k,int fa)
{
	int n_son=0;
	time_dfs[k]=low[k]=++cnt;
	for (int i=head[k]; i>=0; i=edge[i].next)
		if (!time_dfs[edge[i].v])
		{
			n_son++;
			dfs(edge[i].v,i);
			low[k]=min(low[k],low[edge[i].v]);
			if (low[edge[i].v]>time_dfs[k]) is_cut[edge[i].id]=true;
		}
		else if (i!=(fa^1)) low[k]=min(low[k],time_dfs[edge[i].v]);
}
//edge必须从0开始