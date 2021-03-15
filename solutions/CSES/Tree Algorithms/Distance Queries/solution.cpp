#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
const int LG = 19;
vector<int> g[MXN];
int depth[MXN];
int st[MXN][LG];

void dfs(int u = 0, int p = 0) {
    for(auto & v : g[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        st[v][0] = u;
        for(int i = 1; i < LG; i++) {
            st[v][i] = st[st[v][i - 1]][i - 1];
        }
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    for(int i = LG - 1; i >= 0; i--) {
        if(depth[u] - (1 << i) >= depth[v])
            u = st[u][i];
    }
    if(u == v) return u;
    for(int i = LG - 1; i >= 0; i--) {
        if(st[u][i] != st[v][i]) {
            u = st[u][i];
            v = st[v][i];
        }
    }
    return st[u][0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs();
    while(q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int lc = lca(u, v);
        cout << depth[u] + depth[v] - 2*depth[lc] << endl;
    }
    return 0;
}