void dfs(int k)
{
	int n_son=0,n_son_cut=0;
	time_dfs[k]=low[k]=++cnt;
	for (int i=head[k]; i>=0; i=edge[i].next)
		if (!time_dfs[edge[i].v])
		{
			n_son++;
			dfs(edge[i].v);
			low[k]=min(low[k],low[edge[i].v]);
			if ((!k&&n_son>1)||(k&&low[edge[i].v]>=time_dfs[k]))
			{
				n_son_cut++;
				if (!k) cut[k]=n_son;
				else cut[k]=n_son_cut+1;
			}
		}
		else low[k]=min(low[k],time_dfs[edge[i].v]);
}