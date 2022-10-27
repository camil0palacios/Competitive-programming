// dont forget de max value of n and log of n
int st[Mxn][Lg], lvl[Mxn];

void dfs(int u, int p) {
    for(auto & v : g[u]) {
        if(v == p) continue;
        lvl[v] = lvl[u] + 1;
        st[v][0] = u;
        fori(i,1,Lg) st[v][i] = st[st[v][i-1]][i-1];
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if(lvl[u] < lvl[v]) swap(u, v);
    forr(i,Lg-1,0)
        if(lvl[u] - (1 << i) >= lvl[v]) u = st[u][i];
    if(u == v) return u;
    forr(i,Lg-1,0) {
        if(st[u][i] != st[v][i]) {
            u = st[u][i];
            v = st[v][i];
        } 
    }
    return st[u][0];
}

int dist(int u, int v) {
    return lvl[u] + lvl[v] - 2*lvl[lca(u, v)];
}