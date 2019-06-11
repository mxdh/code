void make_next()
{
	next[0]=next[1]=0;
	for (int i=1,j=0; i<n-1; i++)
	{
		while (j&&t[i]!=t[j]) j=next[j];
		f[i+1]=t[i]==t[j]?++j:0;
	}
}

int match()
{
	for (int i=0,j=0; i<m; i++)
	{
		while (j&&s[i]!=t[j]) j=next[j];
		if (s[i]==t[j]) j++;
		if (j==n) return i-n+2;
	}
	return -1;
}