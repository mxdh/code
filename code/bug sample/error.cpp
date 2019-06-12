int GetFa(int k) { return k == fa[k] ? k : fa[k] = GetFa(fa[k]); }
int fa[10000];