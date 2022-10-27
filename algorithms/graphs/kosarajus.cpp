// dont forget graph g and transpose t
int cmp[Mxn];
bool vis[Mxn];
stack<int> st;

void dfs1(int u) {
    vis[u] = 1;
    for(auto & v : g[u]) if(!vis[v]) dfs1(v);
    st.push(u);
}

void dfs2(int u, int c) {
    vis[u] = 1, cmp[u] = c;
    for(auto & v : t[u]) if(!vis[v]) dfs2(v, c);
}

void kosarajus(int n) {
    memset(vis, 0, sizeof vis);
    fori(i,0,n) if(!vis[i]) dfs1(i);
    memset(vis, 0, sizeof vis);
    int c = 0;
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        if(!vis[u]) dfs2(u, c++);
    }
}